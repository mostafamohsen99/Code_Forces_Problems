// Shaas and Oskols.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	int wires;
	cin >> wires;
	int *a = new int[wires];
	for (int i = 0; i < wires; i++)
	{
		cin >> a[i];
	}
	int shots;
	int x, y;
	cin >> shots;
	for (int i = 1; i <= shots; i++)
	{
		cin >> x >> y;
		if (x == 1)
		{
			a[1] = a[1] + (a[0] - y);
			a[0] = 0;
		}
		if (x == wires)
		{
			a[x - 2] = a[x - 2] + (y - 1);
			a[x - 1] = 0;
		}
		if (x != 1 && x != wires)
		{
			a[x - 2] = a[x - 2] + (y - 1);
			a[x] = a[x] + (a[x - 1] - y);
			a[x - 1] = 0;
		}

	}
	for (int i = 0; i < wires; i++)
	{
		cout << a[i] << endl;
	}
	delete[] a;

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
