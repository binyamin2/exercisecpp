/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 9 question 2

the file is definition of class template "SearchTree" (this class is sun of class "Tree")
and declaration of is methods          .*/

#pragma once
#include <iostream>
#include "Tree.h"
using namespace std;

template <class T>
class SearchTree : public Tree<T>
{
public:
	// protocol for search trees
	void add(T value);
	bool search(T value)
	{
		return search(this->Tree<T>::root, value);
	}
	void remove(T value)
	{
		if (!this->search(value))
			throw "not exist";
		remove(Tree<T>::root, value);
	}
	T successor(T val);
	void deleteDuplicates();
private:
	typename Tree<T>::Node* successor(typename Tree<T>::Node* current, T val);
	void add(class Tree<T>::Node* current, T val);
	bool search(class Tree<T>::Node* current, T val);
	void remove(typename Tree<T>::Node* current, T val);
	//void remove(class Tree<T>::Node*& current, T val);
	typename Tree<T>::Node* min(class Tree<T>::Node* current);
	typename Tree<T>::Node* searchReturnAddress(class Tree<T>::Node* current, T val);
	void processST(T val);
	void inOrderST(class Tree<T>::Node* current);
	typename Tree<T>::Node* returnPoint(typename Tree<T>::Node* p, T val);
};


template <class T>
bool SearchTree<T>::search(class Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return false; // not found
	if (current->value == val)
		return true;
	if (current->value < val)
		return search(current->right, val);
	else
		return search(current->left, val);
}

template <class T>
typename Tree<T>::Node* SearchTree<T>::searchReturnAddress(class Tree<T>::Node* current, T val)
{
	// see if argument value occurs in tree
	if (!current)
		return nullptr; // not found
	if (current->value == val)
		return current;
	if (current->value < val)
		return searchReturnAddress(current->right, val);
	else
		return searchReturnAddress(current->left, val);
}

//return adress of the successor
//it function i was'nt do alonly so i was help at my freind.
template <class T>
typename Tree<T>::Node* SearchTree<T>::successor(typename Tree<T>::Node* current, T val)
{
	typename Tree<T>::Node* temp;

	if (current->value == val)
	{
		if (current->right)
		{
			return min(current->right);
		}

		temp = current->parent;
		while (temp != nullptr && current == temp->right)
		{
			current = temp;
			temp = current->parent;
		}

		return temp;
	}

	if (current->value < val) // continue to scan the tree until come to value
		return successor(current->right, val);
	return successor(current->left, val);
}

//return min value of the current tree
template<class T>
typename Tree<T>::Node* SearchTree<T>::min(class Tree<T>::Node* current)
{
	typename Tree<T>::Node* temp = current;
	if (temp == nullptr)//if not have son
		throw "nullptr not have min";
	while (temp->left != nullptr)//run until left
	{
		temp = temp->left;
	}
	return temp;
}

//deleteDuplicates
template<class T>
void SearchTree<T>::deleteDuplicates()
{
	//set to another function
	this->inOrderST(Tree<T>::root);
}

//process of deleteDuplicates
//i assume that "equally value" is in left son.
template<class T>
void SearchTree<T>::processST(T val)
{
	typename Tree<T>::Node* organ = this->searchReturnAddress(Tree<T>::root, val);

	if (organ->left != nullptr)//check in left son
	{
		typename Tree<T>::Node* second = this->searchReturnAddress(organ->left, val);
		while (second)//until not have "equally value"
		{
			typename Tree<T>::Node* temp = second->left;
			this->remove(second, val);
			second = this->searchReturnAddress(temp, val);
		}

	}
}
//process of deleteDuplicates the in order
template<class T>
void SearchTree<T>::inOrderST(class Tree<T>::Node* current)
{
	if (current)
	{
		processST(current->value);
		inOrderST(current->left);
		inOrderST(current->right);
	}
}

//function add
template <class T>
void SearchTree<T>::add(class Tree<T>::Node* current, T val)
{
	if (current->value < val) // Add to right subtree
		if (!current->right)
		{
			current->right = new class Tree<T>::Node(val);
			current->right->parent = current;
			return;
		}
		else
			add(current->right, val);
	else // Add to left subtree
		if (!current->left)
		{
			current->left = new class Tree<T>::Node(val);
			current->left->parent = current;
			return;
		}
		else
			add(current->left, val);
}

template <class T>
void SearchTree<T>::add(T val)
{
	// Add value to binary search tree 
	if (!this->Tree<T>::root)
	{
		this->Tree<T>::root = new class Tree<T>::Node(val);
		this->Tree<T>::root->parent = nullptr;
		return;
	}
	add(this->Tree<T>::root, val);
}


// the function removes node
//it function i was'nt do alonly so i was help at my freind.
template <class T>
void SearchTree<T>::remove(typename Tree<T>::Node* current, T val)
{
	if (current)//if not the root
	{
		current = returnPoint(current, val);
		typename Tree<T>::Node* temp;

		if (!current->left && !current->right)//not have son
		{
			if (current == current->parent->left)
			{
				current->parent->left = nullptr;
			}
			else
			{
				current->parent->right = nullptr;
			}
			delete current;;
			return;
		}

		// if have 2 son
		if (current->left && current->right)
		{
			temp = successor(current, val);
			current->value = temp->value;
			remove(temp, temp->value);
			return;
		}

		// if have only one son
		if (current->left)
		{
			temp = current->left;
		}
		else
		{
			temp = current->right;
		}

		temp->parent = current->parent;
		if (temp->parent)
		{
			if (current->parent->left == current)
			{
				current->parent->left = temp;
			}
			else
			{
				current->parent->right = temp;
			}
		}
		else //if it the root so we update the root
		{
			this->root = temp;
		}
		delete current;
		return;
	}
}

//return adress of the node withe the value
template <class T>
typename Tree<T>::Node* SearchTree<T>::returnPoint(typename Tree<T>::Node* p, T val)
{
	if (p == nullptr)
		return NULL;
	if (p->value == val)
		return p;
	if (p->value < val)
		return returnPoint(p->right, val);
	return returnPoint(p->left, val);
}

// the function returns the successor to val
//it function i was'nt do alonly so i was help at my freind.
template <class T>
T SearchTree<T>::successor(T val)
{
	if (!this->search(val))
		throw "no exist";

	typename Tree<T>::Node* temp = successor(Tree<T>::root, val); // temp= pointer to the successor
	if (temp == nullptr)
		throw "no successor";
	return temp->value;
}