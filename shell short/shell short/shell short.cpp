// shell short.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
void shellsort(int arr[],int size)
{ 
	for (int gap=size/2; gap >0; gap/=2)
	{
		for (int j= gap; j < size; j++)
		{
			int temp = arr[j];
			int i = 0;
			for (i = j; (i>=gap)&&(arr[i - gap] > temp); i-= gap)
			{
				arr[i] = arr[i - gap];
			}
			arr[i] = temp;
		}
	}
}


int main()
{
	int arr[8];
	for (int i = 0; i < 8; i++)
	{
		cin >> arr[i];
	}
	shellsort(arr,8);
	for (int i = 0; i < 8; i++)
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
