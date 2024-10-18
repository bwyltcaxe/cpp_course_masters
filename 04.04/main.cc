#include <iostream>
#include <type_traits>

int sum_ints_rec ()
{
    return 0;
}

template<typename T, typename... Args>
int sum_ints_rec (T cur_arg, Args... rest)
{
    /* Check for 'int' type.  */
    if constexpr (std::is_same_v<T, int>)
    {
        return cur_arg + sum_ints_rec (rest...);
    }
    else
        return sum_ints_rec (rest...);
}

template<typename... Args>
int sum_ints (Args... args)
{
    return sum_ints_rec (args...);
}


int main ()
{
    std::cout << sum_ints (1, "hi", 'c', 4, 12.5, 12) << std::endl;
}

