#include <iostream>
#include <string>
#include <sstream>

class my_ipv4 final
{
#define OCTETS_NUM 4
    uint8_t address [OCTETS_NUM];

public:
    my_ipv4 (uint8_t octet_1 = 0, uint8_t octet_2 = 0,
             uint8_t octet_3 = 0, uint8_t octet_4 = 0)
      : address {octet_1, octet_2, octet_3, octet_4} {}

    friend std::istream &operator>> (std::istream &is, my_ipv4 &ipv4)
    {
        std::string input;
        is >> input;

        /* Unfortunately, C++ has no normal split function.  */
        std::stringstream ss (input);
        std::string token;
        for (auto i = 0; i < OCTETS_NUM; ++i)
        {
            std::getline (ss, token, '.');
            ipv4.address [i] = std::stoul (token);
        }

        return is;
    }

    friend std::ostream &operator<< (std::ostream &os, const my_ipv4 &ipv4)
    {
        os << std::to_string (ipv4.address [0]) << "." << std::to_string (ipv4.address [1])
           << "." << std::to_string (ipv4.address [2]) << "." << std::to_string (ipv4.address [3]);
        return os;
    }
};

int main ()
{
    my_ipv4 ipv4_stream;
    std::cin >> ipv4_stream;
    std::cout << "Here we are: " << ipv4_stream << std::endl;

    my_ipv4 ipv4_construct (172, 26, 5, 73);
    std::cout << "This one was constructed: " << ipv4_construct << std::endl;
}

