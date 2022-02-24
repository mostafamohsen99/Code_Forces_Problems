// selection sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;
int main()
{
	int arr[5];
	int min;
	for (int i = 0; i < 5; i++)
	{
		cin >> arr[i];
	}
/*	for (int i = 0; i < 4; i++)
	{
		min = i;
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[j] < arr[min])
			{
				min = j;
			}
		}
		if (min != i);
		{
			swap(arr[min], arr[i]);
		}
	}*/
	for (int i = 0; i < 4; i++)
	{
		for (int j = i + 1; j < 5; j++)
		{
			if (arr[j] < arr[i])
			{
				swap(arr[j], arr[i]);
			}
		}

	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
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
