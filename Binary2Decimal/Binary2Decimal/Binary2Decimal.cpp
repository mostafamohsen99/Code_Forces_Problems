// Binary2Decimal.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
//#include<sstream>
#include<string>
#include<math.h>
using namespace std;
int main()
{
	unsigned long long sum = 0;
	//long double m;
	string str;
	//stringstream ss;
	getline(cin, str);
	//ss << m;
	//ss >> str;
	//cout << str << endl;
	//cout << str.length() << endl;

	for (int i = str.length(); i >= 0; i--)
	{
		if (str[i] == '1')
		{
			sum += pow(2, str.length() - 1 - i);
			//cout << "str1 [" << i << "]=1" << endl;
			//cout << sum << endl;
		}
		else if (str[i] == '0')
		{
			//cout << "str1 ["<<i<<"]=0" << endl;
			//cout << sum << endl;
			continue;
		}
	}
	//sum = pow(2, 50);
	cout << sum;

}
/*
void binary_to_decimal(int n)
{
	if (n <= 0)
		return;
	binary_to_decimal(n / 2);
	if (n % 2 == 0)
		cout << 0;
	else
		cout << 1;

}
void decimal_to_binary(int a)
{

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
