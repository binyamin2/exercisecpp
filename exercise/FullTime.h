#pragma once
#include <iostream>
#include<string>//
#include"Employee.h"

using namespace std;

/*oz asban 207565607
binyamin shapira
c++
homework 6 question 1
build a class of employee and also fulltime & parttime that inherits from imployee and add more qualities on him */

class FullTime :public Employee
{
	//data
	float salaryPerYear;
public:
	FullTime(string n, int i, int s, float salaryPerYear);//ctor
	FullTime();//empty ctor
	FullTime(const FullTime& f);//copyctor
	float salary();//calculate the salary per month
	friend istream& operator>>(istream& is, FullTime& f);//cin perator
	friend ostream& operator<<(ostream& os, FullTime& f);//cout operator


};
