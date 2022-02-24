// prefix to postfix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
#include<stack>
using namespace std;
bool isOperand(char c)
{
	if ((c >= 'a'&&c <= 'z') || (c >= 'A'&&c <= 'Z'))
		return true;
	else
		return false;
}
bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '/' || c == '*' || c == '^')
		return true;
	else
		return false;
}
string prefixtopostfix(stack <string> s,string prefix )
{
	for (int i = prefix.length() - 1; i >= 0; i--)
	{
		if (isOperand(prefix[i]))
		{
			string op(1, prefix[i]);
			s.push(op);
		}
		else if(isOperator(prefix[i]))
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			s.push(op1 + op2 + prefix[i]);
		}
	}
	return s.top();
}

int main()
{
	string prefix;
	stack<string> s;
	cout << "enter prefix exp" << endl;
	cin >> prefix;
	string postfix = prefixtopostfix(s, prefix);
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
