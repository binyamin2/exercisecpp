/*
binyamin shapira 208965863.

course : cadna c++.
exercise 8 question 1.

*/
#include "StackVector.h"
#include <iostream>
#include <string>
using namespace std;

string infixToPostfix(string infix);//infixToPostfix return string
float calcPostfix(string postfix);//calcPostfix return float

int main()
{


	string exp;
	cout << "enter an infix expression as a string" << endl;
	cin >> exp;
	string postfix = infixToPostfix(exp);
	cout << "in postfix form: " << postfix << endl;
	cout << "calculated value: " << calcPostfix(postfix) << endl;
	return 0;
}



string infixToPostfix(string infix)
{
	int size = infix.size();
	string postfix;
	StackVector<char> stack1(100);
	char ch;
	for (int i = 0; i < size; i++)//for size of the infix
	{
		ch = infix[i];
		if (ch == '(')//if '('
		{
			stack1.push(ch);
		}
		else if (ch == ')')//if '('
		{
			while (!stack1.isEmpty() && stack1.top() != '(')//while not empty and stack1.top() != '(' 
			{
				postfix += stack1.pop();
				postfix += ' ';
			}
			stack1.pop();// pop '('
		}
		else if (ch == '-' || ch == '+')
		{
			if (!stack1.isEmpty())// if not empty
			{
				while (stack1.top() == '*' || stack1.top() == '/')
				{
					postfix += stack1.pop();
					postfix += ' ';
				}
			}
			stack1.push(ch);
		}
		else if (ch == '*' || ch == '/')// if ch == '*' || ch == '/'
		{
			stack1.push(ch);
		}
		else if (ch >= '0' && ch <= '9')// if (ch >= '0' && ch <= '9')
		{
			ch = infix[i];
			postfix += ch;
			while (infix[i+1] != '\0' && infix[i + 1] >= '0' && infix[i + 1] <= '9')
			//if the string not finish and the next char is number
			{
				i++;
				ch = infix[i];
				postfix += ch;
				
			}
			postfix += ' ';
		}
	}
	while (!stack1.isEmpty())
	{
		if (stack1.top() == '(')//if stack1.top() == '(' 
		{
			stack1.pop();
		}
		else
		{
			postfix += stack1.pop();
			postfix += ' ';
		}
		
	}
	return postfix;
}

float calcPostfix(string postfix)
{
	float sum = 0;
	int size = postfix.size();
	StackVector<int> stack1(100);
	
	for (int i = 0; i < size; i++)
	{
		if (postfix[i] >= '0' && postfix[i] <= '9')//if number
		{
			string str = postfix.substr(i);//inside the str the postfix from postfix[i] 
			int size2 = str.find(' ');//find the size of the number 
			string s_temp;//for take the number
			for (int i1 = 0; i1 < size2; i1++)//for size of the number
			{
				s_temp += str[i1];
			}
			int num = stoi(s_temp);//string to int !
			stack1.push(num);
			i += size2 - 1;//i + size the number - 1

		}
		else if (postfix[i] == '+'|| postfix[i] == '-' || postfix[i] == '*' || postfix[i] == '/')
		{
			float num2 = stack1.pop();
			float num1 = stack1.pop();
			if (postfix[i] == '+')
			{
				sum = num1 + num2;
			}
			else if (postfix[i] == '-')
			{
				sum = num1 - num2;
			}
			else if (postfix[i] == '*')
			{
				sum = num1 * num2;
			}

			else if (postfix[i] == '/')
			{
				sum = num1 / num2;
			}
			stack1.push(sum);
		}
	
	}

	return stack1.pop();
}

/*
enter an infix expression as a string
(5+3)*((20/10)+(8-6)
in postfix form: 5 3 + 20 10 / 8 6 - + ( *
calculated value: 32

C:\Users\binyamin\OneDrive - g.jct.ac.il\sadnac++\exercise\exercise\Debug\exercise8-1.exe (process 10816) exited with code 0.
To automatically close the console when debugging stops, enable Tools->Options->Debugging->Automatically close the console when debugging stops.
Press any key to close this window . . .

*/

