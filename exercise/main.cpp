/*
binyamin shapira 208965863.
oz asban 207565607.

we make together.

course : cadna c++.
exercise 6 question 1.

the program checks num of operation in Employee.
and check is sun :"FullTime.h" "PartTime.h"
*/
#include "Employee.h"
#include "FullTime.h"
#include "PartTime.h"
#include <iostream>
using namespace std;

int main()
{
	FullTime arrF[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrF[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	PartTime arrP[3];
	for (int i = 0; i < 3; i++)
	{
		try
		{
			cin >> arrP[i];
		}
		catch (const char* str)
		{
			cout << str << endl;
			i--;
		}
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrF[i];
		cout << "After Bonus: " << arrF[i].salaryAfterBonus() << endl;
	}


	for (int i = 0; i < 3; i++)
	{
		cout << arrP[i];
		cout << "After Bonus: " << arrP[i].salaryAfterBonus() << endl;
	}
	return 0;
}

/*
* Enter employee details:
moshe  1234 3 36000
Enter employee details:
moshe  1234 3 36000
Enter employee details:
moshe  1234 3 36000
Enter employee details:
aharon  5678 4 160 35
Enter employee details:
aharon  5678 4 160 35
Enter employee details:
aharon  5678 4 160 35
Employee: moshe
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000
After Bonus: 3500
Employee: moshe
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000
After Bonus: 3500
Employee: moshe
Employee ID: 1234
Years Seniority: 3
Salary per Month: 3000
After Bonus: 3500
Employee: aharon
Employee ID: 5678
Years Seniority: 4
hours:160
Salary per Month:5600
After Bonus: 6100
Employee: aharon
Employee ID: 5678
Years Seniority: 4
hours:160
Salary per Month:5600
After Bonus: 6100
Employee: aharon
Employee ID: 5678
Years Seniority: 4
hours:160
Salary per Month:5600
After Bonus: 6100

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise6.exe (process 9756) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/