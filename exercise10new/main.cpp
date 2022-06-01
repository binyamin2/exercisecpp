/*
binyamin shapira 208965863
oz asban 207565607.

we make together

course : cadna c++.
exercise 10

the main check the operation in the class         .*/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include"Commander.h"
#include "Officer.h"
#include "PrivateSoldier.h"
#include "Soldier.h"

using namespace std;


enum option {
	EXIT,	//	סיום התוכנית
	ADD_NEW_SOLDIER,	//	הוספת חייל חדש
	DESERVES_MEDAL,	//	הדפסת פרטי כל החיילים הזכאים לצל"ש
	HIGHEST_SOCIOMETRIC,	//הדפסת שם (משפחה ופרטי) של  החייל בעל ציון סוציומטרי מקסימלי 
	PRIVATE_MEDAL_COUNT,	//	הדפסת מספר החיילים הטירוניים הזכאים לצל"ש
	NONCOMBAT_COMMANDER,	//	הדפסת שמות (משפחה ופרטי) של המפקדים שאינם בקרבי
	SUPER_SOLDIER,   //הדפסת הודעה מתאימה, האם קיים חייל שהשתתף ביותר מ- 15  מבצעים צבאיים
	REMOVE_OFFICER,	//	מחיקת כל החיילים הקצינים שלא השתתפו כלל במבצע צבאי
};
void add(list<Soldier*> & listSoldier);    //השלם\י פרמטר- ווקטור או רשימה  
void printMedalList(list<Soldier*> listSoldier);   //השלם\י פרמטר- ווקטור או רשימה  
Soldier* highestSociometricScore(list<Soldier*> listSoldier);   //השלם\י פרמטר- ווקטור או רשימה  

int main()
{
	Soldier* s;
	list<Soldier*> listSoldier;// הצהרה על ווקטור או רשימה של חיילים
		int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(listSoldier);  //הוספת חייל חדש						
			break;
		case DESERVES_MEDAL:printMedalList(listSoldier);  //הדפסת פרטי הזכאים לצל"ש
			break;
		case HIGHEST_SOCIOMETRIC:   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
			s = highestSociometricScore(listSoldier); // השלם\י פרמטר-וקטור או רשימה
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;

			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			cout << count_if(listSoldier.begin(), listSoldier.end(), [](Soldier* sd) {return sd->soldierType() == "private" &&
				sd->medal(); }); //הדפסת מספר הזכאים לצל"ש בטירונים
				cout << endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			for_each(listSoldier.begin(), listSoldier.end(), [](Soldier* sd) {if (sd->soldierType() == "commander" && !((Commander*)sd)->get_combat())
				cout << sd->getFirstName() << ' ' << sd->getLastName() << endl; });
				cout << endl;
			break;
		case SUPER_SOLDIER:
			if (any_of(listSoldier.begin(), listSoldier.end(), [](Soldier* sd) {return sd->get_specials_event() > 15; })) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים

				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER://מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			listSoldier.remove_if( []( Soldier*  sd){return (sd->soldierType() == "officer" && sd->get_specials_event() == 0); });
			for_each(listSoldier.begin(),listSoldier.end(), [](Soldier* sd) {sd->print(); }); //הדפסת כל הרשימה לאחר מחיקת האיברים
				break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
} 

void add(list<Soldier*> &listSoldier)
{
	int type, id, numOfOperations;
	string f_name, l_name;
	bool is_combat;
	float s_score;
	cout << "choose a soldier\n";
	cout << "enter 1 to add a private\n";
	cout << "enter 2 to add a commander\n";
	cout << "enter 3 to add an officer\n";
	cin >> type;
	cout << "enter id, first name, last name and number of operations\n";
	cin >> id >> f_name >> l_name >> numOfOperations;
	Soldier* news;
	if (type == 1)//privite soldier
	{
		news =new PrivateSoldier(id, f_name, l_name, numOfOperations);
		if (numOfOperations)//if numOfOperations != 0
		{
			cout << "enter " << numOfOperations << " grades\n";
			((PrivateSoldier*)news)->set_array();//inside function to insert the value
		}
		listSoldier.push_back(news);
	}
	else if (type == 2)//commander
	{

		news =new Commander (id, f_name, l_name, numOfOperations, 1);
		if (numOfOperations)//if numOfOperations != 0
		{
			cout << "enter " << numOfOperations << " grades\n";
			((Commander*)news)->set_array();//inside function to insert the value
		}

		cout << "enter 1 if the soldier is combat and 0 if not\n";
		cin >> is_combat;
		((Commander*)news) ->set_combat(is_combat);
		listSoldier.push_back(news);
	}
	else//officer
	{
		cout << "enter the sociometric score\n";
		cin >> s_score;
		news = new Officer(id, f_name, l_name, numOfOperations, s_score);
		listSoldier.push_back(news);
	}
	

}

void printMedalList(list<Soldier*>  listSoldier)
{
	typedef list<Soldier*>::iterator ILS;
	for (ILS it = listSoldier.begin(); it !=listSoldier.end(); it++)
	{
		if ((*it)->medal() )//if return bool
		{
			(*it)->print();
			cout << endl;
		}
	}
}

Soldier* highestSociometricScore(list<Soldier*> listSoldier)
{

	float max = -1;
	Soldier* temp = nullptr;
	for (list<Soldier*>::iterator it = listSoldier.begin(); it !=listSoldier.end(); it++)//for run on all the list
	{
		if ((*it)->soldierType() == "officer")
		{
			if (((Officer*)(*it))->get_sociometric_score() > max)//if its Officer update the max sociometric and the pointer
			{
				temp = *it;
				max = ((Officer*)(*it))->get_sociometric_score();
			}
		}
	}
	if (max == -1)//if there is no Officers return null
	{
		return nullptr;
	}
	return temp;
}


/*
enter 0-7
1 1 111 aaa aaa 3 100 95 98 1 2 222 bbb bbb 0 1
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
enter id, first name, last name and number of operations
enter 3 grades
enter 0-7
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
enter id, first name, last name and number of operations
enter 1 if the soldier is combat and 0 if not
enter 0-7
 1 3 333 ccc ccc 0 100
choose a soldier
enter 1 to add a private
enter 2 to add a commander
enter 3 to add an officer
enter id, first name, last name and number of operations
enter the sociometric score
enter 0-7
3
Officer with the highest sociometric score: ccc ccc
enter 0-7
4
number of privates that received medals: 0
enter 0-7
7
private
ID: 111
first name: aaa
last name: aaa
num operations: 3
grades: 100 95 98
commander
ID: 222
first name: bbb
last name: bbb
num operations: 0
combat: yes
enter 0-7
2
enter 0-7
0

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise10new.exe (process 13204) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/