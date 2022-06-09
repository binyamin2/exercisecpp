#pragma once
#include<ostream>
using namespace std;

class myException : public exception
{
	virtual const char* what() const throw()
	{

		return "My exception happened";
	}

public:
	string str;
	myException()

};