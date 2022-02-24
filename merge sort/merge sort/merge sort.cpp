// merge sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
void merge(int arr[], int l, int m, int r)
{
	int temp[5];
	int i = l;
	int k = l;
	int j = m + 1;
	while (i <= m && j <= r)
	{
		if (arr[i] >= arr[j])
		{
			temp[k] = arr[j];
			j++;
			k++;
		}
		else
		{
			temp[k] = arr[i];
			i++;
			k++;
		}
	}
	while (i <= m)
	{
		temp[k] = arr[i];
		i++;
		k++;
	}
	while (j <= r)
	{
		temp[k] = arr[j];
		k++;
		j++;
	}
	for (int i = l; i <= r; i++)
	{
		arr[i] = temp[i];
	}
}

void mergesort(int arr[], int l, int r)
{
	if (l < r)
	{
		int m;
		 m = (l + r) / 2;
		mergesort(arr, l, m);
		mergesort(arr, m + 1, r);
		merge(arr, l, m, r);
	}

}

int main()
{
	int arr[5] = { 9,7,3,6,2 };
	mergesort(arr, 0, 4);
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
