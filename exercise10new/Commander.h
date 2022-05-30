#pragma once
#include<iostream>
#include "PrivateSoldier.h"
using namespace std;

class Commander :public PrivateSoldier
{
	bool combat;
public:
	Commander(int id, string privete_name, string familiy_name, int specials_event, bool combat) :
		PrivateSoldier(id, privete_name, familiy_name, specials_event), combat(combat) {};
	virtual ~Commander() override;
	virtual string soldierType() const override { return "Commander"; };
	virtual bool medal()const override;
	virtual void print()const override;
	Commander(Commander& c);
	Commander(Commander&& c);
	void set_combat(bool c);
};