#include <iostream>

template <typename T>
T min_value (T first)
{
    return first;
}

template <typename T, typename... Args>
T min_value (T first, Args... rest)
{
    T min_of_rest = min_value (rest...);
    return first < min_of_rest ? first : min_of_rest;
}

int main ()
{
    std::cout << min_value (12, -6, 4, 8) << std::endl;
    std::cout << min_value (12.5, 0.3, -0.66, 12.8) << std::endl;
}

