/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.

exercise 9 quesion 1

the file is definition of class "Queue" absract
and declaration of is methods.*/

#pragma once
#include <iostream>
using namespace std;
template <class T>
class Queue
{
public:
	virtual ~Queue() {};
	virtual void clear() = 0;
	virtual void enqueue(T value) = 0;
	virtual T dequeue() = 0;
	virtual T front() = 0;
	virtual bool isEmpty() const = 0;
};
