#include<iostream>
#include "PrivateSoldier.h"
#include "Commander.h"

using namespace std;

/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

file for comander class implementation   .*/


bool Commander::medal() const//return true if should get a medal
{
	if (this->specials_event > 6 && this->combat)
	{
		float sum = 0, averge = 0;
		for (int i = 0; i < this->specials_event; i++)
			sum += this->military_assessment[i];
		averge = sum / this->specials_event;
		if (averge > 90)
		{
			return true;
		}
	}
	else
	{
		return false;
	}
}

void Commander::print() const//print commander details
{
	cout << "commander" << endl << "ID: " << this->id << endl;
	cout << "first name: " << this->privete_name << endl;
	cout << "last name: " << this->familiy_name << endl;
	cout << "num operations: " << this->specials_event << endl;
	if (this->specials_event > 0)//print the grades only if heve spacial operations
	{
		cout << "grades: ";
		for (int i = 0; i < specials_event; i++)
		{
			cout << military_assessment[i] << " ";
		}
		cout << endl;
	}
	cout << "combat: ";//print if combat or not
	if (combat)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

Commander::Commander(Commander& c): PrivateSoldier(c)//copy ctor(call private soldier copy ctor)
{
	combat = c.combat;
}

Commander::Commander(Commander && c)//move constractor
{
	this->familiy_name = c.getLastName();
	this->id = c.get_id();
	this->privete_name = c.getFirstName();
	this->specials_event = c.get_specials_event();
	this->military_assessment = c.military_assessment;
	c.military_assessment = nullptr;
	combat = c.combat;
}

void Commander::set_combat(bool c)//set if combat
{
	combat = c;
}
