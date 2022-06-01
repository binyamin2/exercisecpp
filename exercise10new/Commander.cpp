#include<iostream>
#include "PrivateSoldier.h"
#include "Commander.h"

using namespace std;

Commander::~Commander()
{
	PrivateSoldier::~PrivateSoldier();
}

bool Commander::medal() const
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

void Commander::print() const
{
	cout << "commander" << endl << "ID: " << this->id << endl;
	cout << "first name: " << this->privete_name << endl;
	cout << "last name: " << this->familiy_name << endl;
	cout << "num operations: " << this->specials_event << endl;
	if (this->specials_event > 0)
	{
		cout << "grades: ";
		for (int i = 0; i < specials_event; i++)
		{
			cout << military_assessment[i] << " ";
		}
		cout << endl;
	}
	cout << "combat: ";
	if (combat)
		cout << "yes" << endl;
	else
		cout << "no" << endl;
}

Commander::Commander(Commander& c): PrivateSoldier(c)
{
	combat = c.combat;
}

Commander::Commander(Commander && c)
{
	this->familiy_name = c.getLastName();
	this->id = c.get_id();
	this->privete_name = c.getFirstName();
	this->specials_event = c.get_specials_event();
	this->military_assessment = c.military_assessment;
	c.military_assessment = nullptr;
	combat = c.combat;
}

void Commander::set_combat(bool c)
{
	combat = c;
}
