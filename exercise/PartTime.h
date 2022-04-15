/*
 binyamin shapira 208965863.
 oz asban 207565607.

 we make together.

course : cadna c++.
exercise 6 question 1.
the file is definition of class "PartTime". the class "PartTime" is sun of the class "Employee".
and declaration of is methods.
*/
#pragma once
#include <iostream>//
#include<string>
#include"Employee.h"
using namespace std;

class PartTime:public Employee
{

private:
	int hoursOfWork;
	float payPerHour;

public:

	PartTime(string name, int id, int seniority, int hoursOfWork, float payPerHour);//ctor
	PartTime() : Employee(), hoursOfWork(0) , payPerHour(0) {}//ctor defult
	PartTime(const PartTime& pt);//copy ctor
	int getHoursOfWork() { return hoursOfWork; };//get "hw"
	int getpayPerHour() { return hoursOfWork; };//get "ph"
	void setHoursOfWork(int hoursOfWork);//set "hw"
	void setpayPerHour(int payPerHour) { this->payPerHour = payPerHour; };//set "ph"
	void salary() { setPay(this->hoursOfWork * this->payPerHour); };//calculates the salary

	friend istream& operator >>(istream& is, PartTime& pt);//operator >>
	friend ostream& operator <<(ostream& os, PartTime& pt);//operator <<
};

