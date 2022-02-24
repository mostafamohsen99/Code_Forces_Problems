// infix to postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<stack>
using namespace std;
int precedence(char m)
{
	if (m == '+' || m == '-')
		return 1;
	else if (m == '*' || m == '/')
		return 2;
	else if (m == '^')
		return 3;
	else
		return -1;
}
bool isoperator(char x)
{
	if (x == '+' || x == '-' || x == '/' || x == '*' || x == '^')
		return true;
	else
		return false;
}
string infixtopostfix(string infix_exp, stack<char> st)
{
	string postfix_exp = "";
	for (int i = 0; i < infix_exp.length(); i++)
	{
		if ((infix_exp[i] >= 'a'&&infix_exp[i] <= 'z') || (infix_exp[i] >= 'A'&&infix_exp[i] <= 'Z'))
		{
			postfix_exp += infix_exp[i];
		}
		else if (infix_exp[i] == '(')
		{
			st.push(infix_exp[i]);
		}
		else if (infix_exp[i] == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				postfix_exp += st.top();
				st.pop();
			}
			if (st.top() == '(')
			{
				st.pop();
			}
		}
		else if (isoperator(infix_exp[i]))
		{
			if (st.empty())
			{
				st.push(infix_exp[i]);
			}
			else if (precedence(st.top())<precedence(infix_exp[i]))
			{
				st.push(infix_exp[i]);
			}
			else if (precedence(st.top()) == precedence(infix_exp[i]) && infix_exp[i] == '^')
			{
				st.push(infix_exp[i]);
			}
			else
			{
				while (!st.empty() && (precedence(st.top()) >= precedence(infix_exp[i])))
				{
					postfix_exp += st.top();
					st.pop();
				}
				st.push(infix_exp[i]);
			}
		}
	}
	while (!st.empty())
	{
		postfix_exp += st.top();
		st.pop();
	}
	return postfix_exp;
}
int main()
{
	string infix;
	stack <char> s;
	cout << "enter infix expression" << endl;
	cin >> infix;
	string postfix = infixtopostfix(infix, s);
	cout << "post fix expression is" << endl;
	cout << postfix << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
