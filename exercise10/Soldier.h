/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.

exercise 7

the file is definition of class "point"
and declaration of is methods.*/
#pragma once
#include<iostream>
using namespace std;

class Soldier
{
	//data
protected:
	int id;
	string privete_name;
	string familiy_name;
	int specials_event;

public:
	Soldier(int id, string privete_name, string familiy_name, int specials_event) : id(id)
		, privete_name(privete_name), familiy_name(familiy_name), specials_event(specials_event) {};//ctor

	virtual ~Soldier() {};//dtor
	virtual bool medal()const = 0;//virtual func
	virtual void print() const = 0;//virtual func
	virtual string soldierType() const = 0;//virtual func
	int get_id() { return this->id; }
	string get_privite_name() { return this->privete_name; }
	string get_family_name() { return this->familiy_name; }
	int get_specials_event() { return this->specials_event; }

};