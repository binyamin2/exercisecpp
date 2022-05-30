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
#include "Soldier.h"
using namespace std;

class PrivateSoldier : public Soldier
{
private:
	int* military_assessment;
public:
	PrivateSoldier(int id, string privete_name, string familiy_name, int specials_event) :
		Soldier(id, privete_name, familiy_name, specials_event) {
		this->military_assessment = new int[specials_event];}
	//ctor : Shape(3) {} //ctor
	bool isSpecial() const override;//check if spacial 
	void printSpecial() const override;//print if 
	float area()const override;//calculate area

};
