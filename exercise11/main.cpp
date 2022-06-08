#include "Family.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <exception>


using namespace std;

enum { EXIT, ADD, DEL, COUNT, UPDATE, WAITING, PRINT };

enum ACTIVITY {
	NONE, //  טרם בחר חוג
	SWIMMING,          // שחיה 
	GYMNATSTICS,         // התעמלות קרקע
	DANCE = 4,     // מחול
	ART = 8,    // אומנות
	SELF_DEFENSE = 16, // הגנה עצמית
	MUSIC = 32, // מוסיקה
	DRAMA = 64, // דרמה
	BASKETBALL = 128 // כדור סל
};

void setFile(fstream& file);
void add(fstream& file);
 void add(fstream& file);
 void del(fstream& file, int fum_num);


void handleCount(fstream& file) {
	int snum;
	cout << "enter activity number to count:\n";
	cout << "Choices are:\n1 SWIMMING\n2 GYMNASTICS\n3 DANCE\n4 ART\n5 SELF DEFENSE \n6 MUSIC \n7 DRAMA\n8 BASKETBALL\n";
	cin >> snum;
	cout << "there are ";
	switch (snum) {
	case 1:
		cout << count(file, SWIMMING);
		break;
	case 2:
		cout << count(file, GYMNATSTICS);
		break;
	case 3:
		cout << count(file, DANCE);
		break;
	case 4:
		cout << count(file, ART);
		break;
	case 5:
		cout << count(file, SELF_DEFENSE);
		break;
	case 6:
		cout << count(file, MUSIC);
		break;
	case 7:
		cout << count(file, DRAMA);
		break;
	case 8:
		cout << count(file, BASKETBALL);
		break;
	}
	cout << " families registered\n";
}


int main()
{
	queue<Family> q;

	queue<Family> jv;
	ofstream f1("families.txt");
	if (!f1)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	f1.close();

	fstream file;
	file.open("families.txt", ios::binary | ios::in | ios::out);
	if (!file)
	{
		cout << "ERROR: couldn't open file\n";
		return 0;
	}
	setFile(file);
	file.clear();

	int choice;
	int snum;
	int cnum;
	cout << "Choices are:\n0 to exit\n1 to add a family\n2 to delete a family\n3 to  count number of families signed up\n4 to update the activities of a family \n5 print the waiting list \n6 to print a family\n";
	cout << "enter 0-6:\n";
	cin >> choice;
	while (choice)
	{
		try {
			switch (choice)
			{
			case ADD://add to the file
				add(file);
				break;
			case DEL://delete from file
				cout << "enter number of family to delete:\n";
				cin >> snum;
				del(file, snum);
				break;
			case COUNT:
				handleCount(file);
				break;
			case UPDATE://update the list of classes of a family
				cout << "enter number of family to update:\n";
				cin >> snum;
				update(file, snum, jv);
				break;
			case WAITING://update the list of classes of a waiting family
				waiting(jv);
				break;

			case PRINT://print the details of a specific family
				cout << "enter number of family to print:\n";
				cin >> snum;
				print(file, snum);
				break;
			default:
				cout << "ERROR: invalid choice\n";

			}
		}// try
		catch (exception& e) {
			cout << e.what();
		}
		cout << "\nenter 0-6:\n";
		cin >> choice;

	}
	file.close();
	return 0;
}

void setFile(fstream& file)
{
	Family family1;
	for (int i = 0; i < 100; i++)
	{
		file.write((char*)&family1, sizeof(Famliy));
	}

	return;


}

void add(fstream& file)
{
	int f_num;
	char f_nam[20];
	int num_o_p;
	int fhone;

	Family ftemp;
	cin >> f_num >> f_nam >> num_o_p >> fhone;

	file.seekg(f_num * sizeof(Family));
	file.read((char*)&ftemp, sizeof(Family));
	
	if (ftemp.get_f_num() > 100 ||   )
	{

	}
	if (ftemp.get_f_num() == 0)
	{

	}
	Family(f_num, f_nam, num_o_p, fhone);


}



void del(fstream& file,int fum_num)
{
	
	
	if (fum_num < 1 || fum_num >> 100)
	{

	}//throw;
		Family ftemp, fzero;
		file.seekg(fum_num * sizeof(Family));
		file.read((char*)&ftemp, sizeof(Family));
		if (ftemp.get_f_num() == 0)
		{
			//throw
		}
		file.seekp(fum_num * sizeof(Family));
		file.write((char*)&fzero, sizeof(Family));
		file.clear();
}