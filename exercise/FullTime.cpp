#include <iostream>
#include<string>
#include"Employee.h"
#include"FullTime.h"//
using namespace std;

/*oz asban 207565607
binyamin shapira
c++
homework 6 question 1
build a class of employee and also fulltime & parttime that inherits from imployee and add more qualities on him */

float FullTime::salary()//calculate the salary per monthg
{
	return salaryPerYear / 12;
}

FullTime::FullTime(string n, int i, int s, float salaryPerYear)//ctor
{
	Employee(n, i, s);//use employee ctor 
	this->salaryPerYear = salaryPerYear;
	pay = this->salary();
}
FullTime::FullTime()//empty ctor
{
	salaryPerYear = 0;
}
FullTime::FullTime(const FullTime& f)//copy ctor
{
	id = f.id;
	name = f.name;
	seniority = f.seniority;
	salaryPerYear = f.salaryPerYear;
	pay = f.pay;
}
istream& operator>>(istream& is, FullTime& f)//cin operator for fulltime employee
{
	cout << "Enter employee details:" << endl;
	is >> f.name;
	is >> f.id;
	is >> f.seniority;
	is >> f.salaryPerYear;
	f.pay = f.salary();
	if (f.seniority < 0)
	{
		throw "ERROR";
	}
	return is;
}
ostream& operator<<(ostream& os, FullTime& f)//cout operator for fulltime employee
{
	os << "Employee: " << f.name << endl;
	os << "Employee ID: " << f.id << endl;
	os << "Years Seniority: " << f.seniority << endl;
	os << "Salary per Month: " << f.pay<<endl;
	return os;
}

