#pragma once
#include<iostream>
#include "PrivateSoldier.h"
using namespace std;

/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

file for comander class   .*/

class Commander :public PrivateSoldier
{
	bool combat;
public:
	Commander(int id, string privete_name, string familiy_name, int specials_event, bool combat) :
		PrivateSoldier(id, privete_name, familiy_name, specials_event), combat(combat) {};//ctor
	virtual ~Commander() override {};//dtor
	virtual string soldierType() const override { return "commander"; };
	virtual bool medal()const override;
	virtual void print()const override;
	Commander(Commander& c);
	Commander(Commander&& c);
	void set_combat(bool c);
	bool get_combat() { return this->combat; };
};