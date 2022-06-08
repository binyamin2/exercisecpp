/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.

exercise 9 1

the main check the operation in the class  "SearchTree.h"     .*/

#include <iostream>
using namespace std;
#include "SearchTree.h"
enum { END, ADD, SEARCH, REMOVE, BREADTHSCAN, HEIGHT, SUCCESSOR, DELETEDUP, REFLECT };
int main()
{
	SearchTree<int> T1;
	cout << "enter 10 numbers:\n";
	int x, y, z;
	for (int i = 0; i < 10; i++)
	{
		cin >> x;
		T1.add(x);
	}
	cout << "inorder: ";
	T1.inOrder();
	cout << "\nenter 0-8:\n";
	cin >> x;
	while (x != END)
	{
		switch (x)
		{
		case ADD: cout << "enter a number: ";
			cin >> y;
			T1.add(y);
			cout << "after adding " << y << ": ";
			T1.inOrder();
			cout << endl;
			break;
		case SEARCH: cout << "enter a number: ";
			cin >> y;
			if (T1.search(y))
				cout << "exist" << endl;
			else
				cout << "does not exist" << endl;
			break;
		case REMOVE:cout << "enter a number: ";
			cin >> y;
			try
			{
				T1.remove(y);
				cout << "after removing " << y << ": ";
				T1.inOrder();
				cout << endl;
			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case BREADTHSCAN: cout << "breadth first scan: ";
			T1.breadthScan();
			cout << endl;
			break;
		case HEIGHT:cout << "height of tree: " << T1.height() << endl;
			break;
		case SUCCESSOR:cout << "enter a number: ";
			cin >> y;
			try
			{
				z = T1.successor(y);
				cout << "successor of " << y << " is: " << z << endl;

			}
			catch (const char* str)
			{
				cout << str << endl;
			}
			break;
		case DELETEDUP: cout << "after deleting duplicates: ";
			T1.deleteDuplicates();
			T1.inOrder();
			cout << endl;
			break;
		case REFLECT:T1.reflect();
			cout << "reflected tree: ";
			T1.inOrder();
			T1.reflect();
			cout << endl;
			break;
		}
		cout << "enter 0-8:\n";
		cin >> x;
	}
	return 0;
}


/*
enter 10 numbers:
6 8 7 12 36 32 42 24 28 17
inorder: 6 7 8 12 17 24 28 32 36 42
enter 0-8:
1
enter a number: 3
after adding 3: 3 6 7 8 12 17 24 28 32 36 42
enter 0-8:
2
enter a number: 4
does not exist
enter 0-8:
3
enter a number: 6
after removing 6: 3 7 8 12 17 24 28 32 36 42
enter 0-8:
4
breadth first scan: 7 3 8 12 36 32 42 24 17 28
enter 0-8:
5
height of tree: 6
enter 0-8:
6
enter a number: 2
no exist
enter 0-8:
7
after deleting duplicates: 3 7 8 12 17 24 28 32 36 42
enter 0-8:
8
reflected tree: 42 36 32 28 24 17 12 8 7 3
enter 0-8:
0

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise9-1.exe (process 22028) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/