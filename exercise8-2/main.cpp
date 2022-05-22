/*
binyamin shapira 208965863.

course : cadna c++.
exercise 8 question 2.

the program checks the currect of the class "QueueStack".
for the Stack i use at the class tamplate "StackVector" from question 1. 
*/

#include <iostream>
#include "QueueStack.h"
using namespace std;
int main() {
	Queue* Q;
	int num;
	Q = new QueueStack();
	cout << "enter 5 numbers: " << endl;
	try {
		for (int i = 0; i < 5; i++) {
			cin >> num;
			Q->enqueue(num);
		}
	}
	catch (const char* msg)
	{
		cout << msg;
	}
	cout << "first in queue is: " << Q->front() << endl;
	cout << "removing first 2 elements:" << endl;
	cout << Q->dequeue() << ' ';
	cout << Q->dequeue() << endl;
	cout << "first in queue is: " << Q->front() << endl;
	Q->enqueue(8);
	Q->enqueue(9);
	cout << "emptying out the queue: " << endl;
	while (!Q->isEmpty())
		cout << Q->dequeue() << " ";
	cout << endl;
	return 0;
}

/*
enter 5 numbers:
1 2 3 4 5
first in queue is: 1
removing first 2 elements:
1 2
first in queue is: 3
emptying out the queue:
3 4 5 8 9

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise8-2.exe (process 3636) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .
*/