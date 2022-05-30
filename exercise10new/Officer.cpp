#include <iostream>
#include "Soldier.h"
#include "Officer.h"
#include <string>
using namespace std;

bool Officer::medal()const
{
	if (specials_event > 2 && sociometric_score > 92)
		return true;
	else
		return false;
}

Officer Officer::(Officer& o)
	{

	} 

void Officer::print()const
{
	cout << "ID: " << id << endl;
	cout << "first name: " << privete_name << endl;
	cout << "last name: " << familiy_name << endl;
	cout << "num operations: " << specials_event << endl;
	cout << "sociometric score: " << sociometric_score << endl;
	cout << "i";
}

string Officer::soldierType()
{
	return "Officer ";
}

float Officer::get_sociometric_score()const
{
	return sociometric_score;
}