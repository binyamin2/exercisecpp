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
	void deleteDuplicates();
private:
	void add(class Tree<T>::Node* current, T val);
	bool search(class Tree<T>::Node* current, T val);
	void remove(class Tree<T>::Node*& current, T val);
	typename Tree<T>::Node* min(class Tree<T>::Node* current);
	typename Tree<T>::Node* searchReturnAddress(class Tree<T>::Node* current, T val);
	void process(T val) override;
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
		return search(current->right, val);
	else
		return search(current->left, val);
}

template<class T>
T SearchTree<T>::successor(T val)
{
	typename tree<T>::Node* succ = this->Tree<T>::root;
	int x;
	if ( succ->right!= nullptr)
	{
		succ = min(succ->right);
		return succ ->value;
	}
	else
	{
		typename tree<T>::Node* p1 = succ->parent;
		
		while (p1 != nullptr && succ == p1->right)
		{
			succ = p1;
			p1 = succ->parent;
		}
		return p1->value;
	}

	return T();
}

template<class T>
typename Tree<T>::Node* SearchTree<T>::min(class Tree<T>::Node* current)
{
	typename tree<T>::Node* temp = current;
	while (temp->left != nullptr)
	{
		temp = temp->left;
	}
	return temp;
}

template<class T>
void SearchTree<T>::deleteDuplicates()
{
	this->inOrder();
}

template<class T>
void SearchTree<T>::process(T val)
{
	typename tree<T>::Node* organ = this->searchReturnAddress(Tree<T>::root, val);

	if (organ->left != nullptr)
	{
		typename tree<T>::Node* second = this->searchReturnAddress(organ->left, val);
		while (second)
		{
			typename tree<T>::Node* temp = second->left;
			this->remove(second, val);
			second = this->searchReturnAddress(temp, val);
		}
	
	}
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
	typename tree<T>::Node* find = this->searchReturnAddress(current, val);

	if (find == nullptr)
	{
		throw "the tree not have son with this value";
	}
	if (find->left == nullptr && find->right == nullptr)
	{
		typename tree<T>::Node* parent1 = find->parent;
		if (parent1 -> right == find)
		{
			delete parent1->right;
		}
		else
		{
			delete parent1->left;
		}
	}
	else if (find->left != nullptr && find->right != nullptr)
	{
		int x = this->successor(find->value);
		typename tree<T>::Node* succ = this->searchReturnAddress(find, x);
		find->value = succ->value;

		typename tree<T>::Node* parent1 = succ->parent;
		if (parent1->right == succ)
		{
			delete parent1->right;
		}
		else
		{
			delete parent1->left;
		}
		

	}
	else if (find->left != nullptr)
	{
		typename tree<T>::Node* parent1 = find->parent;

		if (parent1->left == find)
		{
			parent1->left = find->left;
			delete find;
		}
		else
		{
			parent1->right = find->left;
			delete find;
		}
	}
	else if (find->right != nullptr)
	{
		if (parent1->left == find)
		{
			parent1->left = find->right;
			delete find;
		}
		else
		{
			parent1->right = find->right;
			delete find;
		}
	}
	
}
