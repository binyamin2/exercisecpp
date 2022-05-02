/*
binyamin shapira 208965863

oz asban 207565607.

we make together

course : cadna c++.

exercise 7

the file is definition of class "point"
and declaration of is methods.*/
#pragma once
#include<iostream>
#include"Point.h"
#include <cmath>
using namespace std;

class Shape
{
	//data
protected:
	int numOfPoint;
	Point* Points;

public:
	Shape();//empty ctor
	Shape(int size);//ctor
	Shape(Shape& s);//copy ctor
	Shape(Shape&& s);//move ctor
	virtual~Shape();//dtor
	friend ostream& operator<<(ostream& os, Shape& s);//operator for cout
	virtual float area()const=0;//virtual func
	virtual bool isSpecial() const=0;//virtual func
	virtual void printSpecial() const=0;//virtual func

};
