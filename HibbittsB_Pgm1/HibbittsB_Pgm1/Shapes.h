#pragma once
#include "Polygon.h"
#include <iostream>


#ifndef SHAPES_H
#define SHAPES_H

//Triangle Class
class Triangle : public Polygon {
protected:
	int sideB, sideC;
public:
	Triangle(int sA = 0, int sB = 0, int sC = 0) : Polygon(sA), sideB(sB), sideC(sC) {}
	double area() const override;
	double perimeter() const override;
};

//Isosceles Triangle Class
class IsoscelesTriangle : public Triangle{
public:
	IsoscelesTriangle(int sA = 0, int sB = 0) : Triangle(sA,sB,sB) {}
	double area() const override;
	double perimeter() const override;
};

//EquilateralTriangle
class EquilateralTriangle : public Triangle{
public:
	EquilateralTriangle(int sA = 0) : Triangle(sA,sA,sA) {}
	double area() const override;
	double perimeter() const override;
};

//Quadrilateral Class
class Quadrilateral : public Polygon{
protected:
	int sideB, sideC, sideD;
	double angle;
public:
	Quadrilateral(int sA = 0, int sB = 0, int sC = 0, int sD = 0,double a = 0.0) : Polygon(sA), sideB(sB), sideC(sC), sideD(sD), angle(a) {}
	double area() const override;
	double perimeter() const override;
};

//Rectangle Class
class Rectangle : public Quadrilateral{
public:
	Rectangle(int sA = 0, int sB = 0) : Quadrilateral(sA, sB, sA, sB,90.0) {}
	double area() const override;
	double perimeter() const override;
};

//Square Class
class Square : public Rectangle{
public:
	Square(int sA = 0) : Rectangle(sA,sA) {}
	double area() const override;
	double perimeter() const override;
};
//Pentagon Class
class Pentagon : public Polygon{
public:
	Pentagon(int sA = 0) : Polygon(sA){}
	double area() const override;
	double perimeter() const override;
};

//Hexagon Class
class Hexagon : public Polygon{
public:
	Hexagon(int sA = 0) : Polygon(sA){}
	double area() const override;
	double perimeter() const override;
};
//Octagon Class
class Octagon : public Polygon{
public:
	Octagon(int sA = 0) : Polygon(sA) {}
	double area() const override;
	double perimeter() const override;
};
#endif
