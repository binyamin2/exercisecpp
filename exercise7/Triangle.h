/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 7

the file is definition of class "Triangle" (this class is sun of class "shape")
and declaration of is methods.*/
#pragma once
#include<iostream>
#include"Point.h"
#include <cmath>
#include "Shape.h"
using namespace std;

class Triangle: public Shape
{
public:
	Triangle() : Shape(3) {} //ctor defualt
	bool isSpecial() const override;//check if spacial 
	void printSpecial() const override;//print if 
	float area()const override;//calculate area

};


