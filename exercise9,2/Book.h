#pragma once
#include<iostream>
#include<string>

/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 9 question 2

book class         .*/

using namespace std;

class Book
{//data
	int code;
	string author_name;
	string book_name;
public:
	//operators
	Book(int code = 0, string author_n = "\0", string book_n = "\0");
	bool operator !=(const Book& b)const;
	bool operator ==(const Book& b)const;
	bool operator >=(const Book& b)const;
	bool operator <=(const Book& b)const;
	bool operator >(const Book& b)const;
	bool operator <(const Book& b)const;
	friend ostream& operator << (ostream& os,const Book& b);
	friend istream& operator >> (istream& is, Book& b);
};
