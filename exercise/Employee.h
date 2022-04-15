#pragma once
#include <iostream>
#include<string>//
using namespace std;

/*oz asban 207565607
binyamin shapira
c++
homework 6 question 1
build a class of employee and also fulltime & parttime that inherits from imployee and add more qualities on him */

class Employee
{
protected:
	//data
	string name;
	int id;
	int seniority;
	float pay;
public:
	Employee (string n, int i, int s);//ctor
	Employee();//empty ctor
	Employee(const Employee& em);//copy ctor
	//get/set functions
	int getId();
	int getSeniority();
	string getName();
	float getPay();
	void setId(int id);
	void setSeniority(int sen);
	void setName(string name);
	void setPay(float pay);
	float salaryAfterBonus();//caculate the bonus for the employee
	//iostrem functions
	friend istream& operator>>(istream& is, Employee& em);//cin
	friend ostream& operator<<(ostream& os, Employee& em);//cout
};

