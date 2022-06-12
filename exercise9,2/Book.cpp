#include<iostream>
#include<string>
#include "Book.h"
/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 9 question 2

book class implementation      .*/

using namespace std;

Book::Book(int code, string author_n, string book_n)//ctor
{
	this->code = code;
	author_name = author_n;
	book_name = book_n;
}
//*****************operators implemantation********************//
bool Book::operator!=(const Book& b) const
{
	if (code != b.code || author_name != b.author_name || book_name != b.book_name)//return true if not all data equal
		return true;
	else
		return false;
}

bool Book::operator==(const Book& b) const//return true if all data equal
{
	return!(*this != b);
}

bool Book::operator>=(const Book& b) const//lexicogrficly first name then author then code
{
	if (this->book_name >= b.book_name)
		return true;
	else
		return false;
}

bool Book::operator<=(const Book& b) const//lexicogrficly first name then author then code
{
	if (this->book_name <= b.book_name)
		return true;
	else
		return false;
}

bool Book::operator>(const Book& b) const//lexicogrficly first name then author then code
{
	if (this->book_name > b.book_name)
		return true;
	else if((this->book_name < b.book_name))
		return false;
	else
	{
		if (this->author_name > b.author_name)
			return true;
		else if ((this->author_name < b.author_name))
			return false;
		else
		{
			if (this->code > b.code)
				return true;
			else
				return false;
		}
	}
}

bool Book::operator<(const Book& b) const//lexicogrficly first name then author then code
{
	if (this->book_name < b.book_name)
		return true;
	else if ((this->book_name > b.book_name))
		return false;
	else
	{
		if (this->author_name < b.author_name)
			return true;
		else if ((this->author_name > b.author_name))
			return false;
		else
		{
			if (this->code < b.code)
				return true;
			else
				return false;
		}
	}
}

ostream& operator<<(ostream& os,const Book& b)
{
	os << b.code <<" "<< b.book_name << " " << b.book_name;
	return os;
}

istream& operator>>(istream& is, Book& b)
{
	is >> b.code >> b.author_name >> b.book_name;
	return is;
}
