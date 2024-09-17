#include <iostream>
#include <numeric>

int gcd_recursive (int a, int b)
{
    if (b == 0)
        return a;

    return gcd_recursive (b, a % b);
}

int gcd_iterative (int a, int b)
{
    while (b != 0)
    {
        int tmp = b;
        b = a % b;
        a = tmp;
    }

    return a;
}

int lcm (int a, int b)
{
    /* lcm = (a * b) / gcd (a, b).  */
    return a * (b / gcd_iterative (a, b));
}

int main ()
{
    const int border = 100;
    for (int a = 1; a < border; ++a)
        for (int b = 1; b < border; ++b)
        {
            int my_gcd_recursive_res = gcd_recursive (a, b);
            int my_gcd_iterative_res = gcd_iterative (a, b);
            int my_lcm_res = lcm (a, b);

            if (my_gcd_recursive_res != std::gcd (a, b))
                std::cerr << "Bad work of recursive gcd!" << std::endl;
            if (my_gcd_iterative_res != std::gcd (a, b))
                std::cerr << "Bad work of iterative gcd!" << std::endl;
            if (my_lcm_res != std::lcm (a, b))
                std::cerr << "Bad work of lcm!" << std::endl;
        }
}

