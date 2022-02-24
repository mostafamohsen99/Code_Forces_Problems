// balanced_parenthesis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
class stack
{
	char par[1000];
	int top = -1;
public:
	void push(char m)
	{
		top++;
		par[top] = m;
	}
	void pop()
	{
		top--;
	}
	char topvalue()
	{
		return par[top];
	}
	int top_index()
	{
		return top;
	}
};
bool balancing(string a)
{
	stack s1;
	for (int j = 0; j < a.length(); j++)
	{
		if (a[j] == '(' || a[j] == '{' || a[j] == '[' || a[j] == '<')
		{
			s1.push(a[j]);
		}
		else if (a[j] == ')')
		{
			if (s1.topvalue() == '(')
				s1.pop();
			else
				return false;
		}
		else if (a[j] == ']')
		{
			if (s1.topvalue() == '[')
				s1.pop();
			else
				return false;
		}
		else if (a[j] == '}')
		{
			if (s1.topvalue() == '{')
				s1.pop();
			else
				return false;
		}
		else if (a[j] == '>')
		{
			if (s1.topvalue() == '<')
				s1.pop();
			else
				return false;
		}
	}
	if (s1.top_index ()== -1)
		return true;
	else
		return false;
}
int main()
{
	int n;
	string arr[1000];
	bool k[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		k[i]=balancing(arr[i]);
	}
	for (int i = 0; i < n; i++)
	{
		if (k[i] == true)
			cout << "YES" << endl;
		else if (k[i] == false)
			cout << "NO" << endl;
	}
	if (n == 0 || n == -1)
	{
		cout << "NO";
	}
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
