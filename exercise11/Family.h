#pragma once
#include <iostream>
#include <cstring>

/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 11

family class      .*/

using namespace std;
class Family
{
	int f_num;
	char f_name[20];
	int num_of_people;
	int Phone_num;
	short activities;

public:
	Family()//empty ctor
	{
		this->f_num =0;
		for (int i = 0; i < 20; i++)
		{
			this->f_name[i] = '\0';
		}
		this->num_of_people = 0;
		this->Phone_num = 0;
		this->activities = 0;
	}
	Family(int f_num , char f_name[] , int num_o_p , int phone_n , short activities=0 )//ctor
	{
		this->f_num = f_num;
		for (int i = 0; i < 20; i++)
		{
			this->f_name[i] = f_name[i];
		}
		this->num_of_people = num_o_p;
		this->Phone_num = phone_n;
		this->activities = activities;
	}

	//get and set funcs
	int get_f_num() { return f_num; }
	char* get_f_name() { return f_name; }
	int get_num_of_people() { return num_of_people; }
	int get_Phone_num() { return Phone_num; }
	short get_activities() { return  activities; }

	void set_f_num(int t) { f_num = t; }
	void set_f_name(char t[]) 
	{
		for (int i = 0; i < 20; i++)
			this->f_name[i] = t[i];
	}
	void set_num_of_people(int t) { num_of_people = t; }
	void set_Phone_num(int t) { Phone_num = t; }
	void set_activities(int t) { activities = t; }
	
};
