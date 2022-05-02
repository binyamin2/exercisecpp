/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 7.
the file is definition of methods of class "point.h"
*/

#include<iostream>
#include"Point.h"
#include <cmath>
using namespace std;


int Point::getX()
{
	return x;
}
int Point::getY()
{
	return y;
}
void Point::setX(int myX)
{
	x = myX;
}
void Point::setY(int myY)
{
	y = myY;
}
Point::Point(int myX, int myY)//constructor
{
	x = myX;
	y = myY;
}
Point::Point(const Point& p) //copy constructor
{
	x = p.x;
	y = p.y;
}
float Point::distance(Point p2)//return distance between 2 points
{
	float d;
	d = ((float)x - p2.getX()) * (x - p2.getX()) + (y - p2.getY()) * (y - p2.getY());//acording to distance formula
	return  sqrt(d);
}
istream& operator>>(istream& is, Point& p)//operator for cin a point
{
	int x, y;
	char gar;
	is >> gar;
	is >> x;
	is >> gar;
	is >> y;
	is >> gar;
	p.x = x;
	p.y = y;
	return is;
}