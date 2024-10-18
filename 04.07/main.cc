#include <iostream>

template<int N>
struct Fibonacci
{
    static constexpr int value = Fibonacci<N - 1>::value + Fibonacci<N - 2>::value;
};

template<>
struct Fibonacci<0>
{
    static constexpr int value = 0;
};

template<>
struct Fibonacci<1>
{
    static constexpr int value = 1;
};

int main ()
{
    std::cout << Fibonacci<0>::value << std::endl;
    std::cout << Fibonacci<1>::value << std::endl;
    std::cout << Fibonacci<2>::value << std::endl;
    std::cout << Fibonacci<5>::value << std::endl;
    std::cout << Fibonacci<13>::value << std::endl;
}

