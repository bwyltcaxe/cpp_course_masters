#include <iostream>
#include <cmath>

namespace
{

void evaluate_and_dump_prime_factors (int N)
{
    /* It looks like it's better to remove all even numbers.  */
    while (N % 2 == 0)
    {
        std::cout << 2 << std::endl;
        N >>= 1;
    }

    for (int i = 3; i < static_cast<int> (std::sqrt (N)); i += 2)
    {
        while (N % i == 0)
        {
            std::cout << i << std::endl;
            N /= i;
        }
    }

    if (N > 2)
        std::cout << N << std::endl;
}

}

int main ()
{
    int N = 0;
    std::cin >> N;
    evaluate_and_dump_prime_factors (N);
}

