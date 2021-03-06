/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

 definition of is methods          .*/
#include<iostream>
#include "PrivateSoldier.h"
#include <algorithm>

using namespace std;

PrivateSoldier::~PrivateSoldier()
{
	if (this->military_assessment)//destractor dinamy array
	{
		delete[]this->military_assessment;
		this->military_assessment = nullptr;
	}
}

PrivateSoldier::PrivateSoldier(PrivateSoldier& ps)//copy constractor,  deep copy
{

	this->familiy_name = ps.getLastName();
	this->id = ps.get_id();
	this->privete_name = ps.getFirstName();
	this->specials_event = ps.get_specials_event();
	this->military_assessment = new int[ps.get_specials_event()];
	for (int i = 0; i < specials_event; i++)
	{
		this->military_assessment[i] = ps.get_grade(i);
	}
}

PrivateSoldier::PrivateSoldier(PrivateSoldier&& ps)//move constractor, not deep copy
{
	this->familiy_name = ps.getFirstName();
	this->id = ps.get_id();
	this->privete_name = ps.getLastName();
	this->specials_event = ps.get_specials_event();
	this->military_assessment = ps.military_assessment;
	ps.military_assessment = nullptr;
}

bool PrivateSoldier::medal() const
{

	if (this->specials_event >= 10)//this->specials_event >= 10
	{
		float sum = 0, averge = 0;

		for (int i = 0; i < this->specials_event; i++)//claculate the sum
			sum += this->military_assessment[i];
		averge = sum / this->specials_event;//calculate the averge
		if (averge > 95)
		{
			return true;
		}
	}

	return false;
}

void PrivateSoldier::print() const
{
	cout << "private" << endl << "ID: " << this->id << endl;
	cout << "first name: " << this->privete_name << endl;
	cout << "last name: " << this->familiy_name << endl;
	cout << "num operations: " << this->specials_event << endl;
	if (this->specials_event > 0)//if this->specials_event > 0
	{
		cout << "grades: ";
		for (int i = 0; i < specials_event; i++)
		{
			cout << military_assessment[i] << " ";
		}
		cout << endl;
	}
	return;
}

void PrivateSoldier::set_array()
{
	//inside in the array the value the times is acorrding the "specials_event" 
	for (int i = 0; i < this->get_specials_event(); i++)
	{
		cin >> this->military_assessment[i];
	}
}
