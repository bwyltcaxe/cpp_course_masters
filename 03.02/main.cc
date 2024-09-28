#include <iostream>
#include "geom.hpp"

int main ()
{
    my_geom::Triangle tr (my_geom::Point (0, 0), my_geom::Point (1, 1), my_geom::Point (-1, 1));
    std::cout << "Triangle: area = " << tr.area () << ", perimeter = " << tr.perimeter () << std::endl;

    my_geom::Square sq (my_geom::Point (2, 2), 3);
    std::cout << "Square: area = " << sq.area () << ", perimeter = " << sq.perimeter () << std::endl;

    my_geom::Circle cir (my_geom::Point (0, 0), 1);
    std::cout << "Circle: area = " << cir.area () << ", perimeter = " << cir.perimeter () << std::endl;
}

