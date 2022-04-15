/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 6 question 2

the file is definition of class "RoundList.h" (this class is sun of class "List")
and declaration of is methods.*/

#pragma once
#include <iostream>
#include "List.h"
using namespace std;

class RoundList : public List
{
public:
	RoundList() : List() {}//ctor
	~RoundList();//detor
	RoundList( RoundList & rl);//copy ctor
	RoundList( RoundList&& rl); //move ctor
	
	void add(int value);//add organ to first
	void addToEnd(int value);//add organ to the end
	int search(int n);//return the value in index n
	void removeFirst();//remove first elemnt
	int firstElement() const;//return first elemnt
	friend ostream& operator <<(ostream& os, RoundList& rl);//cout
	void clear();//clear the List


};


