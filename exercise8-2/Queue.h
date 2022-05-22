#pragma once

/*
binyamin shapira 208965863

course : cadna c++.

exercise 8 question 2

the file is definition of class "Queue" abstract
and declaration of is methods.*/


class Queue
{
public:
    virtual void clear() = 0;
    virtual void enqueue(int value) = 0;
    virtual int dequeue() = 0;
    virtual int front() = 0;
    virtual bool isEmpty() const = 0;
};
