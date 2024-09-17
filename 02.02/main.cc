#include <iostream>
#include <cmath>
#include <unordered_set>

namespace
{

bool is_armstrong (int num)
{
    int orig = num;
    int sum = 0;
    int digits_num = std::log10 (num) + 1;

    while (num > 0)
    {
        int digit = num % 10;
        sum += std::pow (digit, digits_num);
        num /= 10;
    }

    return sum == orig;
}

void calc_and_dump_armstrong (int N)
{
    for (int i = 1; i < N; ++i)
    {
        if (is_armstrong (i))
            std::cout << "Armstrong [" << i << "]: " << i << std::endl;
    }
}

void calc_and_dump_fibonacci (int N)
{
    int a = 0, b = 1;

    for (int i = 0; a < N; ++i)
    {
        std::cout << "Fibonacci [" << i << "]: " << a << std::endl;
        int next = a + b;
        a = b;
        b = next;
    }
}

int sum_proper_division (int num)
{
    int sum = 1; /* 1 is divisor of everything.  */
    int sqrt_num = static_cast<int> (std::sqrt (num));

    for (int i = 2; i <= sqrt_num; ++i)
    {
        if (num % i == 0)
        {
            sum += i;
            if (i != num / i)
            {
                sum += num / i;
            }
        }
    }

    return sum;
}

void calc_and_dump_abundant (int N)
{
    const int min_abundant = 12;
    for (int i = min_abundant; i < N; ++i)
    {
        if (sum_proper_division (i) > i)
            std::cout << "Abundant [" << i << "]: " << i << std::endl;
    }
}

void calc_and_dump_amicable (int N)
{
    /* To prevent duplicates.  */
    std::unordered_set<int> seen;

    for (int i = 2; i < N; ++i)
    {
        /* Prevent duplicates.  */
        if (seen.find (i) != seen.end())
            continue;

        int div_sum = sum_proper_division (i);
        if (div_sum != i && sum_proper_division (div_sum) == i)
        {
            std::cout << "Amicable [" << i << "]: (" << i << ", " << div_sum << ")" << std::endl;
            seen.insert (i);
            seen.insert (div_sum);
        }
    }
}

}

int main ()
{
    int N = 0;
    std::cin >> N;

    std::cout << "------------------------" << std::endl;
    calc_and_dump_armstrong (N);

    std::cout << "------------------------" << std::endl;
    calc_and_dump_fibonacci (N);

    std::cout << "------------------------" << std::endl;
    calc_and_dump_abundant (N);

    std::cout << "------------------------" << std::endl;
    calc_and_dump_amicable (N);
}

