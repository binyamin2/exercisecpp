/*
binyamin shapira 208965863.
oz asban 207565607.

we make together.

course : cadna c++.
exercise 6 question 1 .

the file is declaration of class "PartTime"

*/
#include "PartTime.h"//
#include <iostream>
#include<string>
using namespace std;

PartTime::PartTime(string name, int id, int seniority, int hoursOfWork, float payPerHour)
{
	Employee(name, id, seniority);//ctor of class Employee
	this->hoursOfWork = hoursOfWork;
	this->payPerHour = payPerHour;
	this->salary();
	if (hoursOfWork < 0)//if the num of hours is negative
	{
		throw "ERROR";
	}
}

PartTime::PartTime(const PartTime& pt)
{
	Employee(pt.name, pt.id, pt.seniority);
	this->hoursOfWork = pt.hoursOfWork;
	this->payPerHour = pt.payPerHour;
	this->pay = pt.pay;

}

void PartTime::setHoursOfWork(int hoursOfWork)
{
	 this->hoursOfWork = hoursOfWork;
	 if (hoursOfWork < 0)//if the num of hours is negative
	 {
		 throw "ERROR";
	 }
}

istream& operator>>(istream& is, PartTime& pt)
{
	cout << "Enter employee details:" << endl;
	is >> pt.name;
	is >> pt.id;
	is >> pt.seniority;
	is >> pt.hoursOfWork;
	is >> pt.payPerHour;
	pt.salary();
	if (pt.hoursOfWork < 0 || pt.seniority < 0)//if the num of hours is negative or years seniority is negative
	{
		throw "ERROR";
	}
	return is;
}

ostream& operator<<(ostream& os, PartTime& pt)
{
	os << "Employee: " << pt.name << endl;
	os << "Employee ID: " << pt.id << endl;
	os << "Years Seniority: " << pt.seniority << endl;
	os << "hours:" << pt.hoursOfWork << endl;
	os << "Salary per Month:" << pt.pay <<endl ;
	return os;
}
