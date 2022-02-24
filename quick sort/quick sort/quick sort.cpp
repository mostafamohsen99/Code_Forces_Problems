// quick sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<algorithm>
using namespace std;
int partition(int arr[], int s, int e) {
	int pivot = arr[e];
	int pindex = s;
	for (int i = s; i < e; i++)
	{
		if (arr[i] <= pivot)
		{
			swap(arr[i], arr[pindex]);
			pindex++;
		}
	}
	swap(arr[e], arr[pindex]);
	return pindex;
}

void quicksort(int arr[], int s, int e)
{
	if (s < e)
	{
		int p;
	 p = partition(arr, s, e);
		quicksort(arr, s, p - 1);
		quicksort(arr, p + 1, e);
	}
}
int main()
{
	int arr[10];
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	quicksort(arr, 0, 9);
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
