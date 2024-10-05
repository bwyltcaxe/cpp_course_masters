#include <iostream>
#include "geom.hpp"

int main ()
{
    my_geom::Triangle tr (3, 4, 5);
    std::cout << "Triangle: area = " << tr.area ()
              << ", perimeter = " << tr.perimeter () << std::endl;
    my_geom::Rectangle rect (2, 3);
    std::cout << "Rectangle: area = " << rect.area ()
              << ", perimeter = " << rect.perimeter () << std::endl;

    my_geom::Square sq (5);
    std::cout << "Square: area = " << sq.area ()
              << ", perimeter = " << sq.perimeter () << std::endl;

    my_geom::Ellipse ells (5, 3);
    std::cout << "Ellipse: area = " << ells.area ()
              << ", perimeter = " << ells.perimeter () << std::endl;

    my_geom::Circle circ (2);
    std::cout << "Circle: area = " << circ.area ()
              << ", perimeter = " << circ.perimeter () << std::endl;
}

