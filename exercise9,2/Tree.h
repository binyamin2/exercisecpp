/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.

exercise 9 2

the file is definition of class template "Tree"
and declaration of is methods
and the difinition.*/

#pragma once
#include "QueueVector.h"
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Tree
{
protected:
	class Node //inner class
	{
	public:
		Node* left;
		Node* right;
		Node* parent;
		T value;
		Node(T val) : value(val), left(nullptr), right(nullptr), parent(nullptr) {
		}
		Node(T val, Node* l, Node* r)
			: value(val), left(l), right(r), parent(nullptr) {}
	}; //end of Node class 
	Node* root;
public:
	Tree() { root = nullptr; } // initialize tree
	virtual ~Tree();
	bool isEmpty() const;
	void clear() { clear(root); root = nullptr; }
	void preOrder() { preOrder(root); }
	void inOrder() { inOrder(root); }
	void postOrder() { postOrder(root); }
	int height() { return height(root); }
	void reflect() { reflect(root); }
	void breadthScan() { breadthScan(root); }

	virtual void process(T val) { cout << val << endl; }
	virtual void add(T val) = 0;
	virtual bool search(T val) = 0;
	virtual void remove(T val) = 0;
private://
	void clear(Node* current);
	void preOrder(Node* current);
	void inOrder(Node* current);
	void postOrder(Node* current);
	int height(Node* current);
	void reflect(Node* current);
	void breadthScan(Node* current);
	int maxi(int t1, int t2);
};

//implementation of tree
template <class T>
Tree<T>::~Tree() // deallocate tree
{
	if (root != nullptr)
		clear(root);
}
template <class T>
void Tree<T>::clear(Node* current)
{
	if (current)
	{ // Release memory associated with children
		if (current->left)
			clear(current->left);
		if (current->right)
			clear(current->right);
		delete current;
	}
}
template <class T>
bool Tree<T>::isEmpty() const
{
	return root == nullptr;
}

// preOrder processing of tree rooted at current
template <class T>
void Tree<T>::preOrder(class Tree<T>::Node* current)
{ // visit Node, left child, right child
	if (current)
	{
		// process current Node
		process(current->value);
		// then visit children
		preOrder(current->left);
		preOrder(current->right);
	}
}

// postOrder processing of tree rooted at current
template <class T>
void Tree<T>::postOrder(class Tree<T>::Node* current)
{ // visit left child, right child, node
	if (current)
	{
		postOrder(current->left);
		postOrder(current->right);
		process(current->value);
	}
}

// inOrder processing of tree rooted at current
template <class T>
void Tree<T>::inOrder(class Tree<T>::Node* current)
{ // visit left child, Node, right child
	if (current)
	{
		inOrder(current->left);
		process(current->value);
		inOrder(current->right);
	}
}


template <class T>
int Tree<T>::height(Node* current)//returns the height of the tree
{
	if (current == nullptr)
		return -1;
	else
		return this->maxi(height(current->left), height(current->right)) + 1;
}

template <class T>
void Tree<T>::reflect(Node* current)//reflect every node in the tree 
{
	if (current == nullptr)
		return;
	reflect(current->left);
	reflect(current->right);
	Node* temp = current->left;
	current->left = current->right;
	current->right = temp;

}

template <class T>
void Tree<T>::breadthScan(Node* current)//breadth scan the tree
{
	// Base Case
	if (root == NULL)
		return;

	// Create an empty queue for level order traversal
	QueueVector <Node*> q(50);

	// Enqueue Root and initialize height
	q.enqueue(root);

	while (q.isEmpty() == false)
	{
		// Print front of queue and remove it from queue
		Node* tempn = q.front();
		cout << tempn->value << " ";
		q.dequeue();

		/* Enqueue left child */
		if (tempn->left != NULL)
			q.enqueue(tempn->left);

		/*Enqueue right child */
		if (tempn->right != NULL)
			q.enqueue(tempn->right);
	}
}

template<class T>
int Tree<T>::maxi(int t1, int t2)//returns the maximum betwen t1 and t2
{
	{
		if (t1 > t2)
			return t1;
		else
			return t2;
	}

}

