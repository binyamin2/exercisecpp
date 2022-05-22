/*
binyamin shapira 208965863

course : cadna c++.

exercise 8 question 2

the file is definition of class "QueueStack" ,the son of class "Stack",
and declaration of its methods.
for the Stack i use at the class tamplate "StackVector" from question 1.
*/

#pragma once
#include "Queue.h"
#include "StackVactor.h"
#include <iostream>
using namespace std;
class QueueStack : public Queue
{
protected:
	StackVector <int>* data;//template int
public:
	QueueStack();
	void clear() override;
	int dequeue() override;
	void enqueue(int value) override;
	int front() override;
	bool isEmpty() const override;
};

