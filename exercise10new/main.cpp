#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
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
void add(_________);    //����\� �����- ������ �� �����  
void printMedalList(_________);   //����\� �����- ������ �� �����  
Soldier* highesttSociometricScore(_________);   //����\� �����- ������ �� �����  

int main()
{
	Soldier* s;
	________________   // ����� �� ������ �� ����� �� ������
		int op;
	cout << "enter 0-7\n";
	cin >> op;
	while (op != EXIT)
	{
		switch (op)
		{
		case ADD_NEW_SOLDIER:add(____________);  //����� ���� ���						
			break;
		case DESERVES_MEDAL:printMedalList(____________);  //����� ���� ������ ���"�
			break;
		case HIGHEST_SOCIOMETRIC:   //����� �� ����� ��� ���� ��������� ���� ����� 
			s = highestSociometricScore(_____); // ����\� �����-����� �� �����
			cout << "Officer with the highest sociometric score: ";
			cout << s->getFirstName() << ' ' << s->getLastName() << endl;

			break;
		case PRIVATE_MEDAL_COUNT:  cout << "number of privates that received medals: ";
			________________ //����� ���� ������ ���"� ��������
				cout << endl;
			break;
		case NONCOMBAT_COMMANDER: cout << "list of noncombat commanders: ";    //����� �����(�� ����� �����) ������� ������� ����� �����
			________________
				cout << endl;
			break;
		case SUPER_SOLDIER:
			if (______________) // ���� ���� ������ ����� �- 15 ������ ������

				cout << "there is at least one soldier that did more than 15 operations\n";
			else
				cout << "no soldier did more than 15 operations\n";
			break;
		case REMOVE_OFFICER://����� ��������/����� �� �� ������ ������ ����� ������ ��� ������� ������
			________________
				________________ //����� �� ������ ���� ����� �������
				break;
		};
		cout << "enter 0-7\n";
		cin >> op;
	}
	return 0;
}
