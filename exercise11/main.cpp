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
void del(fstream& file, int fum_num);
int count(fstream& file, enum ACTIVITY activiti);
void update(fstream& file, int fam_num, queue<Family> &jv);
void help_updute(fstream& file, queue<Family>& jv, char answer, enum ACTIVITY ac, Family& ftemp, Family& family);
void print(fstream& file, int fam_num);

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
		file.write((char*)&family1, sizeof(Family));
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
		if (ftemp.get_f_num() > 100 || ftemp.get_f_num() < 0)
		{
			throw runtime_error("ERROR: Invalid family number");
		}
		if (ftemp.get_f_num() == 0)
		{
			Family(f_num, f_nam, num_o_p, fhone);
			file.seekp(f_num * sizeof(Family));
			file.write((char*)&ftemp, sizeof(Family));

		}
		else
		{
			throw runtime_error("ERROR: Family is already in the file");
		}
	


}



void del(fstream& file,int fum_num)
{
	
	
	if (fum_num < 1 || fum_num >> 100)
	{
		throw runtime_error("ERROR: Invalid family number");

	}
		Family ftemp, fzero;
		file.seekg(fum_num * sizeof(Family));
		file.read((char*)&ftemp, sizeof(Family));
		if (ftemp.get_f_num() == 0)
		{
			throw runtime_error("ERROR: Family is not in the file");
		}
		file.seekp(fum_num * sizeof(Family));
		file.write((char*)&fzero, sizeof(Family));
		file.clear();
}
int count(fstream& file, enum ACTIVITY activiti)
{
	Family ftemp;
	int sum = 0;
	while(!file.eof())
	{
		file.read((char*)&ftemp, sizeof(Family));
		if (ftemp.get_activities() & activiti)
			sum++;
	}
	file.clear();
	return sum;
	
	
}

void update(fstream& file, int fam_num, queue<Family>& jv)
{

	if (fam_num < 1 || fam_num >> 100)
	{
		throw runtime_error("ERROR: Invalid family number");
	}
	Family ftemp;
	file.seekg(fam_num * sizeof(Family));
	file.read((char*)&ftemp, sizeof(Family));
	if (ftemp.get_f_num() == 0)
	{
		throw runtime_error("ERROR: Family is not in the file");

	}
	char answer;
	//copy ftemp to family and change the activitis to zero
	Family family(ftemp);
	family.set_activities(0);

	cout << "Do you want to register for swimming?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, SWIMMING,ftemp,family);
	cout << "Do you want to register for gymnastics?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, GYMNATSTICS, ftemp, family);
	cout << "Do you want to register for dance?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, DANCE, ftemp, family);
	cout << "Do you want to register for art?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, ART, ftemp, family);
	cout << "Do you want to register for self defense?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, SELF_DEFENSE, ftemp, family);
	cout << "Do you want to register for music?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, MUSIC, ftemp, family);
	cout << "Do you want to register for drama?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, DRAMA, ftemp, family);
	cout << "Do you want to register for basketball?" << endl;
	cin >> answer;
	help_updute(file, jv, answer, BASKETBALL, ftemp, family);

	jv.push(family);//push the family with all the activiti they want to register.
	file.seekp(fam_num * sizeof(Family));
	file.write((char*)&ftemp, sizeof(Family));
	file.clear();
	return;
}

void help_updute(fstream& file, queue<Family>& jv, char answer, enum ACTIVITY ac, Family& ftemp,Family& family)
{
	if (answer == 'N' || answer == 'n')
	{
		return;
	}
	else if(answer == 'Y' || answer == 'y')
	{
		if (count(file,ac) < 10) //if have place in the activiti
		{
			ftemp.set_activities(ftemp.get_activities() | ac);//or with ac
		}
		else//if not have place in the activiti
		{
			family.set_activities(family.get_activities() | ac);//add to the activitis the bit of "ac"
		}
	}
	else
	{
	throw runtime_error("ERROR: Invalid response");
	}
	return;
}


void print(fstream& file, int fam_num)
{
	if (fam_num < 1 || fam_num >> 100)
	{
		throw runtime_error("ERROR: Invalid family number");
	}
	Family ftemp;
	file.seekg(fam_num * sizeof(Family));
	file.read((char*)&ftemp, sizeof(Family));
	if (ftemp.get_f_num() == 0)
	{
		throw runtime_error("ERROR: Family is not in the file");
	}
	else
	{
		cout << "family name : " << ftemp.get_f_name() << endl;
		cout << "number of persons : " << ftemp.get_num_of_people() << endl;
		cout << "phone number : " << ftemp.get_Phone_num() << endl;
		if (ftemp.get_activities() & SWIMMING)
			cout << "SWIMMING" << endl;
		if (ftemp.get_activities() & GYMNATSTICS)
			cout << "GYMNATSTICS" << endl;
		if (ftemp.get_activities() & DANCE)
			cout << "DANCE" << endl;
		if (ftemp.get_activities() & ART)
			cout << "ART" << endl;
		if (ftemp.get_activities() & SELF_DEFENSE)
			cout << "SELF_DEFENSE" << endl;
		if (ftemp.get_activities() & MUSIC)
			cout << "MUSIC" << endl;
		if (ftemp.get_activities() & DRAMA)
			cout << "DRAMA" << endl;
		if (ftemp.get_activities() & BASKETBALL)
			cout << "BASKETBALL" << endl;

	}
	return;

}
