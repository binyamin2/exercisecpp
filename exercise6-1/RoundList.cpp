#include<iostream>
using namespace std;
#include "RoundList.h"
/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 6 question 2.
the file is definition of methods of class "RoundList.h"
*/

RoundList::~RoundList()
{
	if (this->isEmpty())
	{
		return;
	}

	this->clear();//clear

}

RoundList::RoundList(RoundList& rl)//copy ctor
{
	Link *link1 = rl.head;

	if (this->isEmpty())
	{
		this ->head = nullptr;
		return;
	}
	while (link1->next != rl.head)//while not return to the place of the head(the finish)
	{
		this->addToEnd(link1->next->value);//add the next organ
		link1 = link1->next;
	}
	this->addToEnd(rl.head->value);//add the last organ
	return;
}

RoundList::RoundList( RoundList&& rl)//move ctor
{
	this->head = rl.head;
	rl.head = nullptr;
	return;
}

void RoundList::add(int value)
{
	if (this->isEmpty())//if the list is empty
	{
		this->head = new Link(value, head);
		head->next = head;
		return;
	}
	else//not empty
	{
		Link *l1 = this->head->next;
		this->head->next = new Link(value, l1);
		if (!this->head->next)//if the dinymic alocation not good
		{
			throw "ERROR in the alocation";
		}
		return;
	}
}

void RoundList::addToEnd(int value)
{
	if (this->isEmpty())//if the list is empty
	{
		this->head = new Link(value, head);
		head->next = head;
		return;
	}
	else//if not empty
	{
		this->head->next = new Link(value, this->head->next);
		if (!this->head->next)//if the dinymic alocation not good
		{
			throw "ERROR in the alocation";
		}
		this->head = head->next;
		return;
	}
}

int RoundList::search(int n)
{
	if (this->isEmpty())//if empty
		return -1;
	Link* l1 = head->next;
	for (int i = 0; i < n; i++)//run in the List round until "n"
	{
		l1 = l1->next;
	}
	return l1->value;
	return 0;
}

void RoundList::removeFirst()
{
	if (this->isEmpty())
		return;
	if (this->head == this->head->next)//if the list is one organ
	{
		if (this ->head)//if not == nullptr
		{
			delete this->head;
			this->head = nullptr;
			return;
		}
	}
	//list with num of organ > 1
	Link *link1 = this ->head->next->next;
	if (this->head->next)//if not == nullptr
	{
	delete this->head->next;
	this->head->next = link1;
	}
	return;
}

int RoundList::firstElement() const
{
	if (this->isEmpty())
			throw "the List is empty, no first Element";
	return this->head->next->value;
}

void RoundList::clear()
{
	if (this->isEmpty())//if empty
	{
		return;
	}
	else
	//i chenges the list to be list one direction and i use in the metod "clear" of the class "List". 
	{
		Link* link1 = this->head;
		this->head = this->head->next;
		link1->next = nullptr;
		List::clear();
	}
}

ostream& operator<<(ostream& os, RoundList& rl)
{
	if (rl.isEmpty())
	{
		return os;
	}
	List::Link *link1 = rl.head;
	while (link1->next != rl.head)
	{
		os << link1->next->value << " ";
		link1 = link1->next;
	}
	os << rl.head->value;


	return os;
}
