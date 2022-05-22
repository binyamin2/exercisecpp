#pragma once
/*
binyamin shapira 208965863

course : cadna c++.

exercise 8 question 2

the file is definition of class "Stack" abstract
and declaration of is methods.*/
template <class T>
class Stack
{
public:
    virtual void clear() = 0;
    virtual bool isEmpty() const = 0;
    virtual T pop() = 0;
    virtual void push(T value) = 0;
    virtual T top() const = 0;
};
