// problem3(Waytoolongwords).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<string>
using namespace std;
int main()
{
	string str[100];
	int m;
	int k;
	char y, t;
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> str[i];
	}
	for (int i = 0; i < m; i++)
	{
		k = 0;
		if (str[i].length()> 10)
		{
			k = str[i].length() - 2;
			y = str[i][0];
			t = str[i][str[i].length() - 1];
			str[i] = "";
			str[i].push_back(y);
			str[i] += to_string(k);
			str[i].push_back(t);

		}
	}
	for (int i = 0; i < m; i++)
	{
		cout << str[i] << endl;
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
