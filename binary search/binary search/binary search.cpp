// binary search.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int binarysort(int arr[],int num)
{
	int left, right, mid = 0;
	left = 0;
	right = 9;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid]==num)
		{
			return mid;
		}
		else if (arr[mid] < num)
		{
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}
	return -1;
}
int main()
{
	int arr[10];
	int num;
	int left, right, mid = 0;
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	cin >> num;
	int m=binarysort(arr, num);
	if (m == -1)
		cout << "number is not exist" << endl;
	else
		cout << "number is exist in "<<m<<"th   position" << endl;
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
