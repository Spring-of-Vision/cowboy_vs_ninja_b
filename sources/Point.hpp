#pragma once

namespace ariel
{ 
    class Point
    {
        //fields
        double xAxis, yAxis;

        public:
            //constructors
            Point(double, double);

            //methods
            double distance(const Point&) const;
            std::string print();
            static Point moveTowards(Point& origin, Point& dest, double scope);
    };
};