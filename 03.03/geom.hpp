#ifndef _MY_GEOM_H__
#define _MY_GEOM_H__

#include <cmath>
#include <numbers>

namespace my_geom
{

struct Shape
{
    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual ~Shape () = default;
};

class Polygon : public Shape
{
    int num_sides;

public:
    Polygon (int num_sides_)
        : num_sides (num_sides_) {}

    virtual ~Polygon () = default;
};

#define TRIANGLE_SIDES_NUM 3
class Triangle final : public Polygon
{
    double side_a, side_b, side_c;

public:
    Triangle (double a, double b, double c)
        : Polygon (TRIANGLE_SIDES_NUM),
          side_a (a), side_b (b), side_c (c) {}

    double perimeter () const override
    {
        return side_a + side_b + side_c;
    }

    double area () const override
    {
        /* Half of perimeter.  */
        double hp = perimeter () / 2;
        return std::sqrt (hp * (hp - side_a) * (hp - side_b) * (hp - side_c));
    }
};

#define RECTANGLE_SIDES_NUM 4
class Rectangle : public Polygon
{
    double width, height;

public:
    Rectangle (double width_, double height_)
        : Polygon (RECTANGLE_SIDES_NUM),
          width (width_), height (height_) {}

    double perimeter () const override
    {
        return 2 * (width + height);
    }

    double area () const override
    {
        return width * height;
    }

    virtual ~Rectangle () = default;
};

struct Square final : public Rectangle
{
    Square (double side)
        : Rectangle (side, side) {}
};

class Ellipse : public Shape
{
    double major_axis, minor_axis;

public:
    Ellipse (double major_axis_, double minor_axis_)
        : major_axis (major_axis_), minor_axis (minor_axis_) {}

    double area () const override
    {
        return std::numbers::pi * major_axis * minor_axis;
    }

    double perimeter () const override
    {
        return 4 * (area () + (major_axis - minor_axis) * (major_axis - minor_axis)) / (major_axis + minor_axis);
    }

    virtual ~Ellipse () = default;
};

struct Circle final : public Ellipse
{
    Circle (double radius)
        : Ellipse (radius, radius) {}
};

}

#endif

