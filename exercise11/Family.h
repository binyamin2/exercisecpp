#pragma once
#include <iostream>
#include <cstring>

using namespace std;
class Family
{
	int f_num;
	char f_name[20];
	int num_of_people;
	int Phone_num;
	short activities;

public:
	Family(int f_num = 0, char f_name[] = { '\0'}, int num_o_p = 0, int phone_n = 0, short activities = 0)
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
	Family(Family& family) {
		this->f_num = family.f_num; strcpy(this->f_name, family.f_name); this->num_of_people = family.num_of_people;
	this->Phone_num = family.Phone_num; this->activities = family.activities;
	}//copyctor

	int get_f_num() { return f_num; }
	char* get_f_name() { return f_name; }
	int get_num_of_people() { return num_of_people; }
	int get_Phone_num() { return Phone_num; }
	short get_activities() { return  activities; };

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
