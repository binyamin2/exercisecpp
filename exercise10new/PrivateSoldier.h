/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

the file is definition of class "PrivateSoldier" (this class is sun of class "Soldier")
and declaration of is methods          .*/
#pragma once
#include<iostream>
#include "Soldier.h"
using namespace std;

class PrivateSoldier : public Soldier
{
protected:
	int* military_assessment;
public:
	PrivateSoldier() : Soldier() { military_assessment = nullptr; };
	//constractor the value and dynamic array
	PrivateSoldier(int id, string privete_name, string familiy_name, int specials_event) :
		Soldier(id, privete_name, familiy_name, specials_event) {
		this->military_assessment = new int[specials_event];}
	virtual ~PrivateSoldier() override;//detor
	PrivateSoldier(PrivateSoldier & ps) ;
	PrivateSoldier(PrivateSoldier && ps);
	virtual bool medal()const override;
	virtual void print()const override;
	virtual string soldierType() const { return "private"; };//virtual func
	int get_grade(int index) { return military_assessment[index]; };
	void set_array();//inside value in the array

};
