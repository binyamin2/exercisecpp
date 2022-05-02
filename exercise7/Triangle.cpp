/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 7.
the file is definition of methods of class "Triangle.h"

*/#include "Triangle.h"
#include<iostream>
#include"Point.h"
#include <cmath>
using namespace std;

bool Triangle::isSpecial() const
{
	float rib1 = this->Points[0].distance(Points[1]);//the distance between the point is the rib
	float rib2 = this->Points[1].distance(Points[2]);
	float rib3 = this->Points[2].distance(Points[0]);

	if (rib1 == rib2 && rib2 == rib3)//if all the rib equally
	{
		return true;
	}
	return false;
}

void Triangle::printSpecial() const
{ 
	if (this->isSpecial())//if isSpecial
	{
		float rib1 = this->Points[0].distance(Points[1]);//the distance between the point is the rib
		cout << "An equilateral triangle with a side length " << rib1 << endl;
	}
}

float Triangle::area() const
{
	float rib1 = this->Points[0].distance(Points[1]);//the distance between the point is the rib
	float rib2 = this->Points[1].distance(Points[2]);
	float rib3 = this->Points[2].distance(Points[0]);

	float s = (rib1 + rib2 + rib3) / 2;//for the formula

	float area = sqrt(s * (s - rib1) * (s - rib2) * (s - rib3));

	return area;
}
