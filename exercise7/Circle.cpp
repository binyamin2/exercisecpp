/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 7.
the file is definition of methods of class "Circle"
*/
#include<iostream>
#include"Point.h"
#include "Shape.h"
#include <cmath>
#include"Circle.h"

using namespace std;

const float Pi = 3.14;//pi

Circle::Circle(float r) : Shape(1)//ctor
{
	radius = r;
}

Circle::Circle(Circle& c) : Shape(c)//copy ctor
{
	radius = c.radius;
}

bool Circle::isSpecial() const//check if spacial circle
{
	Point p1(0, 0);
	if (Points[0].distance(p1) == 0)//check if the point that in the center =(0,0)
		return true;
	return false;
}

void Circle::printSpecial() const//print if sfacial
{
	if (this->isSpecial())
		cout << "A canonical circle with a radius " << radius << endl;
}

float Circle::area()const//calculate area
{
	return radius * radius * Pi;
}
