// postfix to infix.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<stack>
#include<string>
using namespace std;
bool isOperator(char c)
{
	if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
		return true;
	else
		return false;
}
string postfixtoinfix(stack<string> s,string postfix)
{
	string infix;
	for (int i = 0; i < postfix.length(); i++)
	{
		if ((postfix[i] >= 'a'&&postfix[i] <= 'z') || (postfix[i] >= 'A'&&postfix[i] <= 'Z'))
		{
			string op(1,postfix[i]);
			//string op("postfix[i]");
			s.push(op);
		}
		else if (isOperator(postfix[i]))
		{
			string op1 = s.top();
			s.pop();
			string op2 = s.top();
			s.pop();
			string exp = '(' + op2 + postfix[i] + op1 + ')';
			s.push(exp);
		}
	}
	return s.top();
}
int main()
{
	string infix, postfix;
	stack<string> s;
	cout << "enter postfix expression:" << endl;
	cin >> postfix;
	infix = postfixtoinfix(s, postfix);
	cout << "infix expression" << endl;
	cout << infix << endl;

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
