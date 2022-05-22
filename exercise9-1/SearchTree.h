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
		return search(this->root, value);
	}
	void remove(T value)
	{
		if (search(root, value))
			remove(this->root, value);
	}
	T successor(T val);
private:
	class Tree<T>::Node* min(class Tree<T>::Node* current);
	void add(class Tree<T>::Node* current, T val);
	bool search(class Tree<T>::Node* current, T val);
	void remove(class Tree<T>::Node*& current, T val);
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

template<class T>
T SearchTree<T>::successor(T val)
{
	return T();
}

template<class T>
class Tree<T>::Node* SearchTree<T>::min(class Tree<T>::Node* current)
{
	typename tree<T>::Node* temp = current;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}

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
	if (!this->root)
	{
		this->root = new class Tree<T>::Node(val);
		this->root->parent = nullptr;
		return;
	}
	add(this->root, val);
}

template <class T>
void SearchTree<T>::remove(class Tree<T>::Node*& current, T val)
{
	//Homework
	// Node* p = SearchNode (current, val)
	// 3 cases:
	//1. 
	//2.
	//3.
}
