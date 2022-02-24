// infix to prefix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
bool isoperator(char m)
{
	if (m == '+' || m == '-' || m == '*' || m == '/' || m == '^')
		return true;
	else
		return false;
}
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
string infixtoprefix(stack<char> s, string infix)
{
	string prefix;
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
		}
		if (infix[i] == ')')
		{
			infix[i] = '(';
		}
	}
	for (int i = 0; i < infix.length(); i++)
	{
		if ((infix[i] >= 'a'&&infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z'))
		{
			prefix += infix[i];
		}
		else if (infix[i] == '(')
		{
			s.push(infix[i]);
		}
		else if (infix[i] == ')')
		{
			while (s.top() != '(' && (!s.empty()))
			{
				prefix += s.top();
				s.pop();
			}
			if (s.top() == '(')
				s.pop();
		}
		else if (isoperator(infix[i]))
		{
			if (s.empty())
				s.push(infix[i]);
			else if (precedence(infix[i]) > precedence(s.top()))
			{
				s.push(infix[i]);
			}
			else if ((precedence(infix[i]) == precedence(s.top())) && infix[i] == '^')
			{
				while ((precedence(infix[i]) == precedence(s.top())) && infix[i] == '^')
				{
					prefix += s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
			else if (precedence(infix[i]) == precedence(s.top()))
			{
				s.push(infix[i]);
			}
			else
			{
				while (!s.empty() && precedence(infix[i]) < precedence(s.top()))
				{
					prefix += s.top();
					s.pop();
				}
				s.push(infix[i]);
			}
		}
	}
	while (!s.empty())
	{
		prefix += s.top();
		s.pop();
	}
	reverse(prefix.begin(), prefix.end());
	return prefix;

}
int main()
{
	string infix;
	string prefix;
	stack <char> s;
	cout << "enter an expression" << endl;
	cin >> infix;
	prefix = infixtoprefix(s, infix);
	cout << prefix << endl;
}
/*#include <iostream>
#include <stack>
#include <algorithm>
#include<string>

using namespace std;
bool isOperator(char m)
{
	if (m == '+' || m == '-' || m == '*' || m == '/' || m == '^')
		return true;
	else
		return false;
}
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

string InfixToPrefix(stack<char> s, string infix)
{
	string prefix;
	reverse(infix.begin(), infix.end());
	for (int i = 0; i < infix.length(); i++)
	{
		if (infix[i] == '(')
		{
			infix[i] = ')';
		}
		if (infix[i] == ')')
		{
			infix[i] = '(';
		}
	}
	for (int i = 0; i < infix.length(); i++) {
		if ((infix[i] >= 'a' && infix[i] <= 'z') || (infix[i] >= 'A' && infix[i] <= 'Z')) {
			prefix += infix[i];
		}
		else if (infix[i] == '(') {
			s.push(infix[i]);
		}
		else if (infix[i] == ')') {
			while ((s.top() != '(') && (!s.empty())) {
				prefix += s.top();
				s.pop();
			}

			if (s.top() == '(') {
				s.pop();
			}
		}
		else if (isOperator(infix[i])) {
			if (s.empty()) {
				s.push(infix[i]);
			}
			else {
				if (precedence(infix[i]) > precedence(s.top())) {
					s.push(infix[i]);
				}
				else if ((precedence(infix[i]) == precedence(s.top()))
					&& (infix[i] == '^')) {
					while ((precedence(infix[i]) == precedence(s.top()))
						&& (infix[i] == '^')) {
						prefix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
				else if (precedence(infix[i]) == precedence(s.top())) {
					s.push(infix[i]);
				}
				else {
					while ((!s.empty()) && (precedence(infix[i]) < precedence(s.top()))) {
						prefix += s.top();
						s.pop();
					}
					s.push(infix[i]);
				}
			}
		}
	}

	while (!s.empty()) {
		prefix += s.top();
		s.pop();
	}

	reverse(prefix.begin(), prefix.end());
	return prefix;
}

int main()
{

	string infix, prefix;
	cout << "Enter a Infix Expression :" << endl;
	cin >> infix;
	stack<char> stack;
	cout << "INFIX EXPRESSION: " << infix << endl;
	prefix = InfixToPrefix(stack, infix);
	cout << endl
		<< "PREFIX EXPRESSION: " << prefix;

	return 0;
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
