/*
binyamin shapira 208965863

oz asban 207565607.

we make together

course : cadna c++.

exercise 7

the file is definition of class "point"
and declaration of is methods.*/

#pragma once
#include <iostream>
using namespace std;

class Point
{
private:
	int x, y;
public:
	Point()//ctor
	{
		x = 0;
		y = 0;
	}

	int getX();
	int getY();
	void setX(int myX);
	void setY(int myY);
	Point(int x, int y);//ctor
	Point(const Point& p);//copy ctor
	float distance(Point p2);//calculate distance between 2 points
	friend istream& operator>>(istream& is, Point& p);//operator for cin
};
