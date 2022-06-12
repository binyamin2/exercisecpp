#include <iostream>
#include "SearchTree.h"
#include"Book.h"
using namespace std;
/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 9 question 2

bulde a tree of book and manage the tree with his functions   .*/

int main()
{
	SearchTree<Book> books;
	char op;
	cout << "enter a-e" << endl;
	cin >> op;
	while (op != 'e')//if e return
	{
		try
		{
			if (op == 'a')//add book
			{
				cout << "enter a book:" << endl;
				Book b;
				cin >> b;
				books.add(b);
			}
			else if (op == 'b')//delete book
			{
				cout << "enter a book:" << endl;
				Book b;
				cin >> b;
				books.remove(b);
			}
			else if (op == 'c')//search abook
			{
				cout << "enter a book:" << endl;
				Book b;
				cin >> b;
				if (books.search(b))
					cout << "exist" << endl;
				else
					cout << "not exist" << endl;
			}
			else if (op == 'd')//print alll books lexicograpicly
			{
				books.inOrder();
			}
			else//invalid input
				throw "error";
		}
		catch (const char* msg)
		{
			cout << msg << endl;
		}
		cout << "enter a-e" << endl;
		cin >> op;
	}
	return 0;
}