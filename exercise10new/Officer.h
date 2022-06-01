#pragma once
#include <iostream>
#include "Soldier.h"
#include <string>

using namespace std;

/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

file for officer class   .*/

class Officer : public Soldier
{
	float sociometric_score;
public:
	//ctor
	Officer(int id, string privete_name, string familiy_name, int specials_event,float sociometric_score):Soldier( id,  privete_name,  familiy_name, specials_event)
	{
		this->sociometric_score = sociometric_score;
	}
	Officer(Officer& o);
	virtual ~Officer() {};//dtor
	bool medal()const override;
	void print()const override;
	string soldierType() const override;
	float get_sociometric_score()const;
	
};
