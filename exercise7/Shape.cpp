/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 7.
the file is definition of methods of class "shape.h"
*/
#include<iostream>
#include"Point.h"
#include "Shape.h"
#include <cmath>
using namespace std;

Shape::Shape()//empty ctor
{
	numOfPoint = 0;
	Points = nullptr;
}

Shape::Shape(int size)//ctor
{
	numOfPoint = size;
	Points = new Point[size];
	cout << "Enter values of " << size << " points:" << endl;
	for (int i = 0; i < size; i++)
		cin >> Points[i];
}

Shape::Shape(Shape& s)//copy ctor
{
	numOfPoint = s.numOfPoint;
	Points = new Point[numOfPoint];
	for (int i = 0; i < numOfPoint; i++)//deep copieng for the dinamic field
		Points[i] = s.Points[i];
}

Shape::Shape(Shape&& s)//move ctor
{
	numOfPoint = s.numOfPoint;
	Points = s.Points;
	s.Points = nullptr;//reales the old pointer
}

Shape::~Shape()//dtor
{
	if (Points)//check if not allready released
		delete[] Points;
	Points = nullptr;
}

ostream& operator<<(ostream& os, Shape& s)//operator for cout
{
	for (int i = 0; i < s.numOfPoint; i++)//printing all the points in the array
	{
		os << "(";
		os << s.Points[i].getX();
		os << ",";
		os << s.Points[i].getY();
		os << ")";
	}
	return os;
}