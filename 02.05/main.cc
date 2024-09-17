#include <iostream>
#include <numbers>
#include <cmath>
#include <iomanip>

namespace
{

const double Epsilon = 1e-15;

double my_e_eval ()
{
    /* e = sum (1 / (n!)).  */
    double res = 0.;
    double term = 1.; /* (1 / 0!).  */

    for (int denom = 1; term > Epsilon; ++denom)
    {
        res += term;
        term /= denom;
    }

    return res;
}

}

int main ()
{
    double my_e = my_e_eval ();

    std::cout << std::setprecision (17);
    std::cout << "My calculated e = " << my_e << std::endl;
    std::cout << "std::numbers::e = " << std::numbers::e << std::endl;
    std::cout << "Diff = " << std::fabs (my_e - std::numbers::e) << std::endl;
}

