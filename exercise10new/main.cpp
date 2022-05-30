#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
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
void add(_________);    //השלם\י פרמטר- ווקטור או רשימה  
void printMedalList(_________);   //השלם\י פרמטר- ווקטור או רשימה  
Soldier* highesttSociometricScore(_________);   //השלם\י פרמטר- ווקטור או רשימה  

int main()
{
	Soldier* s;
	________________   // הצהרה על ווקטור או רשימה של חיילים
		int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(____________);  //הוספת חייל חדש						
			break;
		case DESERVES_MEDAL:printMedalList(____________);  //הדפסת פרטי הזכאים לצל"ש
			break;
		case HIGHEST_SOCIOMETRIC:   //הדפסת שם הקצין בעל ציון סוציומטרי גבוה ביותר 
			s = highestSociometricScore(_____); // השלם\י פרמטר-וקטור או רשימה
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;

			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			________________ //הדפסת מספר הזכאים לצל"ש בטירונים
				cout << endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //הדפסת רשימת(שם משפחה ופרטי) החיילים המפקדים שאינם בקרבי
			________________
				cout << endl;
			break;
		case SUPER_SOLDIER:
			if (______________) // קיים חייל שהשתתף יובתר מ- 15 מבצעים צבאיים

				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER://מחיקה מהווקטור/רשימה של כל החיילם קצינים שאינם השתתפו כלל במבצעים צבאיים
			________________
				________________ //הדפסת כל הרשימה לאחר מחיקת האיברים
				break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
