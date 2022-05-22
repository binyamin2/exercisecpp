/*
binyamin shapira 208965863.

course : cadna c++.
exercise 8 question 2.

*/
#include "QueueStack.h"
#include <iostream>
#include <string>
using namespace std;


QueueStack::QueueStack()
{
	this->data = new StackVector<int>(100);//constractor the stack with capacity 100.
}

void QueueStack::clear()
{
	while (!this->data->isEmpty())//while the Stack not empty.
	{
		this->data->pop();
	}
}

int QueueStack::dequeue()
{
	int value = 0;
	StackVector <int> stacktemp(100);
	while (!this->data->isEmpty())//while this-> Stack not empty.
	{
		stacktemp.push(this->data->pop());//pop from this->stack into stacktemp
	}
	if (!stacktemp.isEmpty())//!stacktemp.isEmpty()
	{
		value = stacktemp.pop();//save the vlaue
	}
	while (!stacktemp.isEmpty())//return the value into this->stack
	{
		this->data->push(stacktemp.pop());
	}
	return value;
}

void QueueStack::enqueue(int value)
{
	this->data->push(value);//inside
	return;
}

int QueueStack::front()
{
	int value = 0;
	StackVector <int> stacktemp(100);
	while (!this->data->isEmpty())//while this-> Stack not empty.
	{
		stacktemp.push(this->data->pop());//pop from this->stack into stacktemp
	}
	if (!stacktemp.isEmpty())//!stacktemp.isEmpty()
	{
		value = stacktemp.top();//save the vlaue
	}
	while (!stacktemp.isEmpty())//return the value into this->stack
	{
		this->data->push(stacktemp.pop());
	}
	
	return value;
}

bool QueueStack::isEmpty() const
{
	if (this->data->isEmpty())//check if stack empty
	{
		return true;
	}
	return false;
}

