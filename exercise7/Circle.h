/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 7

the file is definition of class "circle" (this class is sun of class "shape")
and declaration of is methods.*/
#pragma once
#include<iostream>
#include"Point.h"
#include "Shape.h"
#include <cmath>

using namespace std;

class Circle :public Shape
{
	//data
	float radius;
public:
	Circle(float r);//ctor
	Circle(Circle& c);//copy ctor
	bool isSpecial() const override;//check if spacial circle
	void printSpecial() const override;//print if sfacial
	float area()const override;//calculate area
};