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
	EXIT,	//	���� �������
	ADD_NEW_SOLDIER,	//	����� ���� ���
	DESERVES_MEDAL,	//	����� ���� �� ������� ������ ���"�
	HIGHEST_SOCIOMETRIC,	//����� �� (����� �����) ��  ����� ��� ���� ��������� ������� 
	PRIVATE_MEDAL_COUNT,	//	����� ���� ������� ��������� ������ ���"�
	NONCOMBAT_COMMANDER,	//	����� ���� (����� �����) �� ������� ����� �����
	SUPER_SOLDIER,   //����� ����� ������, ��� ���� ���� ������ ����� �- 15  ������ ������
	REMOVE_OFFICER,	//	����� �� ������� ������� ��� ������ ��� ����� ����
};
void add(list<Soldier*> & listSoldier);    //����\� �����- ������ �� �����  
void printMedalList(list<Soldier*> listSoldier);   //����\� �����- ������ �� �����  
Soldier* highestSociometricScore(list<Soldier*> listSoldier);   //����\� �����- ������ �� �����  

int main()
{
	Soldier* s;
	list<Soldier*> listSoldier;// ����� �� ������ �� ����� �� ������
		int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(listSoldier);  //����� ���� ���						
			break;
		case DESERVES_MEDAL:printMedalList(listSoldier);  //����� ���� ������ ���"�
			break;
		case HIGHEST_SOCIOMETRIC:   //����� �� ����� ��� ���� ��������� ���� ����� 
			s = highestSociometricScore(listSoldier); // ����\� �����-����� �� �����
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;

			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			cout << count_if(listSoldier.begin(), listSoldier.end(), [](Soldier* sd) {return sd->soldierType() == "private" &&
				sd->medal(); }); //����� ���� ������ ���"� ��������
				cout << endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //����� �����(�� ����� �����) ������� ������� ����� �����
			for_each(listSoldier.begin(), listSoldier.end(), [](Soldier* sd) {if (sd->soldierType() == "commander" && !((Commander*)sd)->get_combat())
				cout << sd->getFirstName() << ' ' << sd->getLastName() << endl; });
				cout << endl;
			break;
		case SUPER_SOLDIER:
			if (any_of(listSoldier.begin(), listSoldier.end(), [](Soldier* sd) {return sd->get_specials_event() > 15; })) // ���� ���� ������ ����� �- 15 ������ ������

				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER://����� ��������/����� �� �� ������ ������ ����� ������ ��� ������� ������
			listSoldier.remove_if( []( Soldier*  sd){return (sd->soldierType() == "officer" && sd->get_specials_event() == 0); });
			for_each(listSoldier.begin(),listSoldier.end(), [](Soldier* sd) {sd->print(); }); //����� �� ������ ���� ����� �������
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
	if (type == 1)
	{
		news =new PrivateSoldier(id, f_name, l_name, numOfOperations);
		if (numOfOperations)
		{
			cout << "enter " << numOfOperations << " grades\n";
			((PrivateSoldier*)news)->set_array();
		}
		listSoldier.push_back(news);
	}
	else if (type == 2)
	{

		news =new Commander (id, f_name, l_name, numOfOperations, 1);
		if (numOfOperations)
		{
			cout << "enter " << numOfOperations << " grades\n";
			((Commander*)news)->set_array();
		}

		cout << "enter 1 if the soldier is combat and 0 if not\n";
		cin >> is_combat;
		((Commander*)news) ->set_combat(is_combat);
		listSoldier.push_back(news);
	}
	else
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
		if ((*it)->medal() )
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