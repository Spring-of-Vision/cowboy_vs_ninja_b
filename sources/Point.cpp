#include <cmath>
#include <stdio.h>
#include <iostream>
#include <stdexcept>
#include "Point.hpp"

using namespace std;

namespace ariel
{
    Point::Point(double xCord, double yCord) : xAxis(xCord), yAxis(yCord)
    {
    }

    double Point::distance(const Point& dest) const
    {
        //distance is the hypotenuse of the triangle created by the x difference and y difference
        double a = (dest.xAxis - this->xAxis), b = (dest.yAxis - this->yAxis);
        return sqrt(a*a + b*b);
    }

    string Point::print()
    {
        return"( " + to_string(xAxis) + "," + to_string(yAxis) + ")\n";
    }

    Point Point::moveTowards(Point& origin, Point& dest, double scope)
    {
        if(scope < 0)
        {
            throw std::invalid_argument("scope can't be negative");
        }

        double dx = dest.xAxis - origin.xAxis;
        double dy = dest.yAxis - origin.yAxis;
        double distance = origin.distance(dest);

        if(distance <= scope)
        {
            return dest;
        }
        else
        {
            double ratio = scope / distance;
            double newX = origin.xAxis + dx * ratio;
            double newY = origin.yAxis + dy * ratio;
            
            return Point(newX, newY);
        }
    }
}