/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 7.
the file is definition of methods of class "Rectangle.h"
*/
#include "Rectangle.h"
#include<iostream>
#include"Point.h"
#include <cmath>
using namespace std;

bool Rectangle::isSpecial() const
{
	float rib1 = this->Points[0].distance(Points[1]);//the distance between the point is the rib
	float rib2 = this->Points[1].distance(Points[2]);
	float rib3 = this->Points[2].distance(Points[3]);
	float rib4 = this->Points[3].distance(Points[0]);

	if (rib1 == rib2 && rib2 == rib3 && rib3 == rib4)//if all the rib equally
	{
		return true;
	}
	return false;
}

void Rectangle::printSpecial() const
{
	if (this->isSpecial())//if isSpecial
	{
		float rib1 = this->Points[0].distance(Points[1]);//the distance between the point is the rib
		cout << "Square with side length " << rib1 << endl;
	}
}

float Rectangle::area() const
{
	float rib1 = this->Points[0].distance(Points[1]);//the distance between the point is the rib
	float rib2 = this->Points[1].distance(Points[2]);
	float area = rib1 * rib2;
	return area;
}
