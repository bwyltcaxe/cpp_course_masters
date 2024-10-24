#include <iostream>
#include <type_traits>

/* This one is taken from  CPPReference as 'possible implementation'.  Let's try to understand
   what is going on here:

    1) typedef typename std::remove_reference<T>::type U; as private field to remove references.
    2) Then we use std::conditionals.  Let's recode it into pseudocode:

        if (is_array (U))
            add_pointer (remove_extent (U)); // remove_extent -- removes [*].  Then add pointer
        else
            if (is_function (U))
                add_pointer (U); // pointer to function
            else
                remove_cv (U); // Remove qualifiers

*/
template<class T>
struct my_decay
{
private:
    typedef typename std::remove_reference<T>::type U;
public:
    typedef typename std::conditional< 
        std::is_array<U>::value,
        typename std::add_pointer<typename std::remove_extent<U>::type>::type,
        typename std::conditional< 
            std::is_function<U>::value,
            typename std::add_pointer<U>::type,
            typename std::remove_cv<U>::type
        >::type
    >::type type;
};

template<class T>
using my_decay_t = typename my_decay<T>::type;

template<typename T, typename U>
constexpr bool is_decay_equ = std::is_same_v<my_decay_t<T>, U>;
 
int main()
{
    static_assert
    (
        is_decay_equ<int, int> &&
        ! is_decay_equ<int, float> &&
        is_decay_equ<int&, int> &&
        is_decay_equ<int&&, int> &&
        is_decay_equ<const int&, int> &&
        is_decay_equ<int[2], int*> &&
        ! is_decay_equ<int[4][2], int*> &&
        ! is_decay_equ<int[4][2], int**> &&
        is_decay_equ<int[4][2], int(*)[2]> &&
        is_decay_equ<int(int), int(*)(int)>
    );

    std::cout << "Every test is passed" << std::endl;
}

