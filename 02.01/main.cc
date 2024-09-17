#include <iostream>
#include <cctype> /* For std::isdigit().  */

enum SymbType
{
    DECIMAL, /* Decimal number {0, ..., 9}.  */
    OPER, /* Arithmetical operattor {+, -, *, /}.  */
    BRACK, /* Round brackets {'(', ')'}.  */
    UNKNOWN, /* All others.  */
};

namespace
{

SymbType define_symb_type (char input_symb)
{
    /* Check for digit.  */
    if (std::isdigit (input_symb))
        return DECIMAL;

    switch (input_symb)
    {
        case '+':
        case '-':
        case '*':
        case '/':
            return OPER;
        case '(':
        case ')':
            return BRACK;
        default:
            return UNKNOWN;
    }
}

void print_symb_type (SymbType type)
{
    switch (type)
    {
        case DECIMAL:
            std::cout << "Decimal type" << std::endl;
            break;
        case OPER:
            std::cout << "Arithmetical operator" << std::endl;
            break;
        case BRACK:
            std::cout << "Brackets" << std::endl;
            break;
        case UNKNOWN:
            std::cout << "Unknown type of symbol" << std::endl;
            break;
        default:
            std::cerr << "WRONG USAGE OF " << __func__ << std::endl;
    }
}

}

int main ()
{
    char input_symb = 0;
    /* Let's read input until 'q' symbol.  */
    do {
        std::cin >> input_symb;
        SymbType type = define_symb_type (input_symb);
        print_symb_type (type);
    } while (input_symb != 'q');
}

