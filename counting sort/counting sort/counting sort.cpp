// counting sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int main()
{
	cout << "enter 10 numbers from 0 to " << 5 << endl;
	int arr[10];
	int outputarr[10];
	int arr1[5];
	for (int i = 0; i < 10; i++)
		cin >> arr[i];
	for (int i = 0; i < 5; i++)
	{
		arr1[i] = 0;
	}
	for (int i = 0; i < 10; i++)
	{
		++arr1[arr[i]];
	}
	for (int i = 1; i < 5; i++)
	{
		arr1[i] = arr1[i - 1] + arr1[i];
	}

	for (int i = 0; i < 10; i++)
	{
		outputarr[--arr1[arr[i]]] = arr[i];
	}
	for (int i = 0; i < 10; i++)
	{
		arr[i] = outputarr[i];
	}
	for (int i = 0; i < 10; i++)
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
