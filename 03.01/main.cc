#include <iostream>
#include <vector>
#include <algorithm>
#include "geom.hpp"

namespace
{

int evaluate_intersect_area (const my_geom::Rectangle &first, const my_geom::Rectangle &second)
{
    int left = std::max (first.get_left_coord (), second.get_left_coord ());
    int top = std::min (first.get_top_coord (), second.get_top_coord ());
    int right = std::min (first.get_right_coord (), second.get_right_coord ());
    int bottom = std::max (first.get_bottom_coord (), second.get_bottom_coord ());

    int width = right - left;
    int height = top - bottom;

    if (width < 0 || height < 0)
        return 0;

    return width * height;
}

void intersect_area(const std::vector<my_geom::Rectangle>& rects) {
    if (rects.empty ())
        return;

    for (int first_ind = 0; first_ind < rects.size (); ++first_ind)
        for (int second_ind = first_ind; second_ind < rects.size (); ++second_ind)
        {
            int area = evaluate_intersect_area (rects [first_ind], rects [second_ind]);
            std::cout << "Intersection area of rectangle #" << first_ind
                      << " and rectangle #" << second_ind
                      << " is " << area << std::endl;
        }

}

}

int main ()
{
    my_geom::Rectangle first (0, 0, 2, 2);
    my_geom::Rectangle second (1, 1, 2, 2);
    my_geom::Rectangle third (2, 2, 4, 4);
    std::vector<my_geom::Rectangle> rectangles = {first, second, third};
    intersect_area (rectangles);
}

