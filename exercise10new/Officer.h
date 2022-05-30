#pragma once
#include <iostream>
#include "Soldier.h"
#include <string>

using namespace std;

class Officer : public Soldier
{
	float sociometric_score;
public:
	Officer(int id, string privete_name, string familiy_name, int specials_event,float sociometric_score):Soldier( id,  privete_name,  familiy_name, specials_event)
	{
		this->sociometric_score = sociometric_score;
	}
	Officer(Officer& o);
	virtual ~Officer() {};//dtor
	bool medal()const override;
	void print()const override;
	string soldierType();
	float get_sociometric_score()const;
	
};
