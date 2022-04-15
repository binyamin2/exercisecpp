#include <iostream>
#include<string>
#include"Employee.h"//
using namespace std;
/*oz asban 207565607
binyamin shapira 
c++
homework 6 question 1
build a class of employee and also fulltime & parttime that inherits from imployee and add more qualities on him */

Employee::Employee(string n, int i, int s)//ctor
{
	this-> name = n;
	this-> id = i;
	this-> seniority = s;
	this-> pay = 0;
	if (s < 0)
	{
		throw "ERROR";
	}
}
Employee::Employee()//empty ctor
{
	name = '\0';
	id = 0;
	seniority = 0;
	pay = 0;
}
Employee::Employee(const Employee& em)//copy ctor
{
	this->id = em.id;
	this->seniority = em.seniority;
	this->pay = em.pay;
	this->name = em.name;
}
float Employee:: salaryAfterBonus()//caculate the bonus for the employee
{
	if (seniority <= 5)
		 pay += 500;
	else
		pay += 0.25 * pay;
	return pay;
}
istream& operator>>(istream& is, Employee& em)//cin for employee
{
	cout << "Enter employee details:" << endl;
	is >> em.name;
	is >> em.id;
	is >> em.seniority;
	if (em.seniority < 0)
	{
		throw "ERROR";
	}
	return is;
}
ostream& operator<<(ostream& os, Employee& em)//cout for employee
{
	os << "Employee: " << em.name << endl;
	os << "Employee ID: " << em.id << endl;
	os << "Years Seniority: " << em.seniority;
	return os;
}
//get and set func for all the data
int Employee::getId()
{
	return id;
}
int Employee::getSeniority()
{
	return seniority;
}
string Employee::getName()
{
	return name;
}
float Employee::getPay()
{
	return pay;
}
void Employee::setId(int id)
{
	this->id = id;
}
void Employee::setSeniority(int sen)
{
	seniority = sen;
	if (sen < 0)
	{
		throw "ERROR";
	}
}
void Employee::setName(string name)
{
	this->name = name;
}
void Employee::setPay(float pay)
{
	this->pay = pay;
}