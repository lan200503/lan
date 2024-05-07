#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;

const double PI = 3.1415926535;

class Shape
{
    public:
        Shape(){};
        virtual double Area() = 0;
        virtual double Perimeter() = 0;
};


class Circle:public Shape
{
    public:
        Circle(double r);
        double Area()
        {
            return radius*radius*PI;
        }
        double Perimeter()
        {
            return 2.0*PI*radius;
        }
    private:
        double radius;
};

Circle::Circle(double r): Shape(),radius(r)
{

}

class Square:public Shape
{
    public:
        Square(double s);
        double Area()
        {
            return side_length*side_length;
        }
        double Perimeter()
        {
            return 4.0*side_length;
        }
    private:
        double side_length;
};

Square::Square(double s): Shape(),side_length(s)
{

}

class Rectangle:public Shape
{
    public:
        Rectangle(double l,double w);
        double Area()
        {
            return length*width;
        }
        double Perimeter()
        {
            return 2.0*(length+width);
        }
    private:
        double length;
        double width;
};

Rectangle::Rectangle(double l,double w):Shape(),length(l),width(w)
{

}


int main()
{
    return 0;
}
