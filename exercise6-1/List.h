/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.

exercise 6 question 2

the file is definition of class "List.h"
and declaration of is methods.*/

#pragma once
#include <iostream>
using namespace std;

class List
{
protected:
	//--------------------------------------------
	//  inner class link
	//  a single element for the linked List 
	//--------------------------------------------
	class Link
	{
	public:
		// constructor
		Link(int linkValue, Link* nextPtr);
		Link(const Link&);
		// data areas
		int value;
		Link* next;
	};	//end of class Link
public:
	// constructors
	List();
	List(const List&);
	~List();

	// operations
	void add(int value);//add link to list
	int firstElement() const;//return first elemnt
	bool search(const int& value) const;//serch value in the list
	bool isEmpty() const;//check if the list is empty
	void removeFirst();//remove first elemnt
	void clear();//clear the list
	List& operator=(const List& l);//operator =
	friend ostream& operator << (ostream& os, List& l);//operator output
	friend istream& operator >> (istream& is, List& l);//operator input
	void insert(int key);//insert elemnt in the array
	void remove(int key);//rem0ve elemnt from array


protected:
	// data field
	Link* head;
};

