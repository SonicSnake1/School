#ifndef POLYGON_H
#define POLYGON_H
class Polygon
{
protected:
	int sideA;
public:
	Polygon(int sA = 0): sideA(sA){}
	virtual double area() const = 0;
	virtual double perimeter() const = 0;
	virtual ~Polygon() {}
};
#endif

