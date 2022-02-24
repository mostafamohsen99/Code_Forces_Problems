// insertion sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;

void insertionsort(int arr[])
{
	int key = 0;
	int j = 0;
	for (int i = 1; i <= 4; i++)
	{
		 key = arr[i];
		 j = i - 1;
		 while (j >= 0 && arr[j] > key)
		 {
			 arr[j + 1] = arr[j];
			 j--;
		 }
		 arr[j + 1] = key;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << arr[i] << endl;
	}
}
int main()
{
	int arr[5] = { 9,7,10,6,8 };
	insertionsort(arr);
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
