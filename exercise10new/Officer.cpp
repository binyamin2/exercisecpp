#include <iostream>
#include "Soldier.h"
#include "Officer.h"
#include <string>
using namespace std;

/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

file for officer class implementation   .*/

Officer::Officer(Officer& o)//copy ctor
{
	id = o.get_id();
	privete_name = o.getFirstName();
	familiy_name = o.getLastName();
	specials_event = o.get_specials_event();
	sociometric_score = o.get_sociometric_score();
}

bool Officer::medal()const//return true if should get medal
{
	if (specials_event > 2 && sociometric_score > 92)
		return true;
	else
		return false;
}



void Officer::print()const//print officer details
{
	cout << "officer " << endl;
	cout << "ID: " << id << endl;
	cout << "first name: " << privete_name << endl;
	cout << "last name: " << familiy_name << endl;
	cout << "num operations: " << specials_event << endl;
	cout << "sociometric score: " << sociometric_score << endl;
}

string Officer::soldierType() const
{
	return "officer";
}

float Officer::get_sociometric_score()const//get sociometric score
{
	return sociometric_score;
}