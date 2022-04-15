#include<iostream>
using namespace std;
#include "List.h"

/*
binyamin shapira 208965863.
oz asban 207565607.

we make together

course : cadna c++.
exercise 6 question 2.
the file is definition of methods of class "List.h"
*/


//------------------------------------------------
//  class Link implementation
//------------------------------------------------
List::Link::Link(int val, Link* nxt) : value(val), next(nxt)
{}


List::Link::Link(const Link& source) : value(source.value), next(source.next)
{}


//--------------------------------------------
//  class List implementation
//--------------------------------------------
List::List() : head(nullptr)
{
	// no further initialization
}

List::List(const List& l)//constractor List
{
	Link* src, * trg;
	if (l.head == nullptr)//if the list empty
		head = nullptr;
	else//not empty
	{
		head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = head;
		while (src->next != nullptr)
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
}

List& List::operator=(const List& l)
{
	Link* src, * trg;
	if (l.head == nullptr)//the List empty
		this->head = nullptr;
	else//not empty
	{
		this->head = new Link((l.head)->value, nullptr);
		src = l.head;
		trg = this->head;
		while (src->next != nullptr)//while not finish
		{
			trg->next = new Link((src->next)->value, nullptr);
			src = src->next;
			trg = trg->next;
		}
	}
	return *this ;
	
}

void List::insert(int key)
{
	Link* current_organ = this->head;
	if(this->isEmpty())//if the list empty
	{
		current_organ = new Link(key, nullptr);
		this->head = current_organ;
		return;
	}
		
	
	if (current_organ->value < key)//if key bigger from one elemnt
	{
		Link* new_link = new Link(key, current_organ);
		this->head = new_link;
		return;
	}
	while (current_organ->next != nullptr && current_organ->next->value > key)//check when insert the elment or if it came to finish
	{
		current_organ = current_organ->next;
	}
	if (current_organ ->next == nullptr)//if it is need to insert in the end of the list
		current_organ ->next = new Link(key, nullptr);
	else//if it is need to insert in the middle of the List
	{
		Link* new_link = new Link(key, current_organ ->next);
		current_organ->next = new_link;
	}
	return;
}

void List::remove(int key)
{
	Link* l1 = this->head;
	if (this->isEmpty())//if the List empty
	{
		throw "value not found";
	}
	if (l1->value == key)//if the first List is == key
	{
		this->head = l1->next;
		delete l1;//delete Dynamic assignment of first elemnt
		return;
	}
	while ( l1->next != nullptr)//As long as it did not reach the end
	{
		if (l1->next->value == key)
		{
			Link* temp = l1->next;//for delete in the future
			l1->next = l1->next->next;
			delete temp;//delete Dynamic assignment of the elemnt
			return;
		}
		l1 = l1->next;
	}
	throw "value not found";

}


List::~List()
{
	clear();
}


void List::clear()
{
	// empty all elements from the List
	Link* theNext;
	for (Link* p = head; p != nullptr; p = theNext)
	{
		// delete the element pointed to by p
		theNext = p->next;
		p->next = nullptr;
		delete p;
	}
	// mark that the List contains no elements
	head = nullptr;
}



bool List::isEmpty() const
{
	// test to see if the List is empty
	// List is empty if the pointer to the head
	// Link is null
	return head == nullptr;
}

void List::add(int val)
{
	//Add a new value to the front of a Linked List
	head = new Link(val, head);
	if (head == nullptr)
		throw "failed in memory allocation";
}

int List::firstElement() const
{
	// return first value in List
	if (isEmpty())
		throw "the List is empty, no first Element";
	return head->value;
}

bool  List::search(const int& val) const
{
	// loop to test each element
	for (Link* p = head; p != nullptr; p = p->next)
		if (val == p->value)
			return true;
	// not found
	return false;
}


void List::removeFirst()
{
	// make sure there is a first element
	if (isEmpty())
		throw "the List is empty, no Elements to remove";
	// save pointer to the removed node
	Link* p = head;
	// reassign the first node
	head = p->next;
	p->next = nullptr;
	// recover memory used by the first element
	delete p;
}

ostream& operator<<(ostream& os, List& l)
{
	List::Link *link1 = l.head;
	while (!(link1 == nullptr))//As long as it did not reach the end
	{
		os << link1->value << " ";
		link1 = link1->next;
	}
	return os;
}

istream& operator>>(istream& is, List& l)
{
	int temp;
	is >> temp;
	l.head = new List::Link(temp,nullptr) ;
	List::Link* ptr = l.head;
	is >> temp;
	while (temp < ptr->value)//As long as it in the order
	{
		ptr->next = new List::Link(temp, nullptr);
		ptr = ptr->next;
		is >> temp;
	}
	return is;
	
}
