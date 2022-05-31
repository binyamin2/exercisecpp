#include <iostream>
#include "Soldier.h"
#include "Officer.h"
#include <string>
using namespace std;

Officer::Officer(Officer& o)
{
	id = o.get_id();
	privete_name = o.getFirstName();
	familiy_name = o.getLastName();
	specials_event = o.get_specials_event();
	sociometric_score = o.get_sociometric_score();
}

bool Officer::medal()const
{
	if (specials_event > 2 && sociometric_score > 92)
		return true;
	else
		return false;
}



void Officer::print()const
{
	cout << "ID: " << id << endl;
	cout << "first name: " << privete_name << endl;
	cout << "last name: " << familiy_name << endl;
	cout << "num operations: " << specials_event << endl;
	cout << "sociometric score: " << sociometric_score << endl;
}

string Officer::soldierType() const
{
	return "Officer ";
}

float Officer::get_sociometric_score()const
{
	return sociometric_score;
}