// 2ndproblem(stringtask).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<string>
using namespace std;
int main()
{
	string str;
	cin >> str;
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] >= 'A'&&str[i] <= 'Z')
		{
			str[i] += 32;
		}
	}
	for (int i = 0; i < str.length(); i++)
	{
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u' || str[i] == 'y')
		{
			str.erase(i, 1);
			i--;
		}
	}
	for (int i = 0; i <str.length(); i+=2)
	{
		str.insert(i, ".");
	}
	cout << str << endl; 
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
