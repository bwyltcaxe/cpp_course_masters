#ifndef _GEOM_H__
#define _GEOM_H__

namespace my_geom
{

class Rectangle final {
    int x, y;
    int width, height;

public:
    Rectangle (int x_, int y_, int width_, int height_)
        : x (x_), y (y_), width (width_), height (height_) {}

    Rectangle (const Rectangle& other)
        : x(other.x), y(other.y),
          width(other.width), height(other.height) {}

    Rectangle &operator= (const Rectangle &other)
    {
        if (this == &other)
            return *this;

        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
    }

    Rectangle (Rectangle &&other)
        : x (other.x), y (other.y),
          width (other.width), height (other.height) {}

    Rectangle& operator= (Rectangle&& other)
    {
        if (this == &other)
            return *this;

        x = other.x;
        y = other.y;
        width = other.width;
        height = other.height;
    }

    ~Rectangle () {}

    int get_top_coord () const
    {
        return y + height;
    }

    int get_right_coord () const
    {
        return x + width;
    }

    int get_left_coord () const
    {
        return x;
    }

    int get_bottom_coord () const
    {
        return y;
    }
};

} /* namespace my_geom.  */

#endif

