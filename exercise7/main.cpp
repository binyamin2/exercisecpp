/*
binyamin shapira 208965863.
oz asban 207565607.

we make together.

course : cadna c++.
exercise 7.

the program checks the classs "Shape" and is son "Rectangle","Circle","Triangle" 
*/

#include "Rectangle.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>
using namespace std;


enum SHAPES { CIRCLE = 1, TRIANGLE = 3, RECTANGLE = 4 };
int main() {
	
	Point p;

	int numShapes, choice;
	cout << "How many shapes you would like to define?\n";
	cin >> numShapes;
	Shape** shapes = new Shape * [numShapes];
	for (int i = 0; i < numShapes; i++) {
		try//for check if radius <= 0
		{
		cout << "Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4\n";
		cin >> choice;
		switch (choice) {
		case CIRCLE:
			int radius;
			cout << "Enter radius :\n";
			cin >> radius;
			if (radius <=0)
			{
				throw "radius must be bigger than 0";
			}
			shapes[i] = new Circle(radius);
			break;
		case TRIANGLE:
			shapes[i] = new Triangle;
			break;
		case RECTANGLE:
			shapes[i] = new Rectangle;
			break;
		default:
			cout << "invalid input\n";
			i--;
		}
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}

	for (int i = 0; i < numShapes; i++)
	{
		cout << "points:" << *shapes[i] << " area is: " << shapes[i]->area() << endl;
		shapes[i]->printSpecial();
	}


return 0;
}

/*
How many shapes you would like to define?
3
Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4
1
Enter radius :
2
Enter values of 1 points:
(0,0)
Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4
3
Enter values of 3 points:
(0,0) (0,2) (2,2)
Which shape will you choose? Circle - 1, Triangle - 3, Rectangle - 4
4
Enter values of 4 points:
(0,0) (0,2) (2,2) (2,0)
points:(0,0) area is: 12.56
A canonical circle with a radius 2
points:(0,0)(0,2)(2,2) area is: 2
points:(0,0)(0,2)(2,2)(2,0) area is: 4
Square with side length 2

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise7.exe (process 8604) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/
