/*
binyamin shapira 208965863.
oz asban 207565607.

we make together.

course : cadna c++.
exercise 6 question 2.

the program checks the classs "RoundList.h".
*/
#include "RoundList.h"
#include <iostream>
using namespace std;

enum CHOICES {
	EXIT, ADD, ADD_TO_END, REMOVE_FIRST, SEARCH, CLEAR, EMPTY, PRINT
};

int main() {
	RoundList roundList;
	int choice;
	cout << "Enter your choice: \n";
	cin >> choice;
	while (choice != EXIT) {
		int num;
		switch (choice) {
		case ADD:
			cout << "Enter a number: \n";
			cin >> num;
			roundList.add(num);
			break;
		case ADD_TO_END:
			cout << "Enter a number: \n";
			cin >> num;
			roundList.addToEnd(num);
			break;
		case REMOVE_FIRST:
			roundList.removeFirst();
			break;
		case SEARCH:
			cout << "Enter a number: ";
			cin >> num;
			cout << roundList.search(num) << endl;
			break;
		case CLEAR:
			roundList.clear();
			break;
		case EMPTY:
			if (roundList.isEmpty())
				cout << "Empty" << endl;
			else
				cout << "Not empty" << endl;
			break;
		case PRINT:
			cout << roundList << endl;
			break;
		default: cout << "ERROR!" << endl;
		}
		cout << "Enter your choice: \n";
		cin >> choice;
	}
	return 0;
}

/*
Enter your choice:
1
Enter a number:
10
Enter your choice:
1
Enter a number:
11
Enter your choice:
2
Enter a number:
20
Enter your choice:
2
Enter a number:
21
Enter your choice:
7
11 10 20 21
Enter your choice:
3
Enter your choice:
7
10 20 21
Enter your choice:
4
Enter a number: 2
21
Enter your choice:
5
Enter your choice:
7

Enter your choice:
8
ERROR!
Enter your choice:
0

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise6-2.exe (process 6652) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .


*/