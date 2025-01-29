#include "Shapes.h"
#include<cmath>

const double M_PI = 3.14159;


//Triangle Functions
double Triangle::area() const
{
    double s = (sideA + sideB + sideC) / 2.0;
    return sqrt(s * (s - sideA) * (s - sideB) * (s - sideC));
}

double Triangle::perimeter() const
{
    return sideA + sideB + sideC;
}

//Isosceles Triangle
double IsoscelesTriangle::area() const
{
    return 0.5 * sideA * sqrt(sideB * sideB - (sideA * sideA) / 4.0);
}

double IsoscelesTriangle::perimeter() const
{
    return sideA + (2 * sideB);
}

//Equilateral Triangle
double EquilateralTriangle::area() const
{
    return (sqrt(3.0) / 4.0) * sideA * sideA;
}

double EquilateralTriangle::perimeter() const
{
    return 3 * sideA;
}

//Quadrilateral
double Quadrilateral::area() const
{
    double s = (sideA + sideB + sideC + sideD) / 2.0;
    double rad = angle * M_PI / 180.0;
    return sqrt((s - sideA) * (s - sideB) * (s - sideC) * (s - sideD) - sideA * sideB * sideC * sideD * pow(cos(rad / 2), 2));
}
double Quadrilateral::perimeter() const
{
    return sideA + sideB + sideC + sideD;
}

//Rectangle
double Rectangle::area() const
{
    return sideA * sideB;
}
double Rectangle::perimeter() const
{
    return (sideA + sideB) * 2;
}

//Square
double Square::area() const
{
    return sideA * sideA;
}
double Square::perimeter() const
{
    return sideA * 4;
}

//Pentagon
double Pentagon::area() const
{
    return (1.0 / 4.0) * sqrt(5 * (5 + 2 * sqrt(5))) * sideA * sideA;
}

double Pentagon::perimeter() const
{
    return 5 * sideA;
}

//Hexagon
double Hexagon::area() const
{
    return (3.0 * sqrt(3.0) / 2.0) * sideA * sideA;
    }

double Hexagon::perimeter() const
{
    return 6 * sideA;
}

//Octagon
double Octagon::area() const
{
    return 2.0 * (1.0 + sqrt(2.0)) * sideA * sideA;
}

double Octagon::perimeter() const
{
    return 8 * sideA;
}
