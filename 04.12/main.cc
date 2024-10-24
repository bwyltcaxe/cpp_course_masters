#include <iostream>
#include <type_traits>

/* I don't know what to say.  This one just adds const to T type.  */
template<typename T>
struct add_const
{
    using type = const T;
};

/* remove_const is harder.  This one is just template structure.  */
template<typename T>
struct remove_const
{
    using type = T;
};

/* The specialization of one above.  Remove const from type.  */
template<typename T>
struct remove_const<const T>
{
    using type = T;
};

int main ()
{
    add_const<int>::type a = 2;
    remove_const<const int>::type b = 4;
    remove_const<int>::type c = 8;
    std::cout << "Let's check add_const:" << std::is_const<decltype (a)>::value << std::endl;
    std::cout << "Same for remove_const:" << std::is_const<decltype (b)>::value << std::endl;
    std::cout << "Same for remove_const:" << std::is_const<decltype (c)>::value << std::endl;
}

