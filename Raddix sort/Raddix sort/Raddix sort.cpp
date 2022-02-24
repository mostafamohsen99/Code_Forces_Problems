// Raddix sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
int getmax(int arr[], int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
void countingsort( int arr[], int size,int div)
{
	int range = 10;
	int countingsort [10];
	int *ouputarr = new int[size];
	for (int i = 0; i < 10; i++)
	{
		countingsort[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		countingsort[(arr[i]/div)%10]++;
	}
	for (int i = 1; i < 10; i++)
	{
		countingsort[i] = countingsort[i] + countingsort[i - 1];
	}
	for (int i = size-1; i >= 0; i--)
	{
		ouputarr[--countingsort[(arr[i] / div) % 10] ] = arr[i];
	}
	for (int i = 0; i < size; i++)
	{
		arr[i] = ouputarr[i];
	}
	
}
void Raddixsort(int arr[], int size)
{
	int m=getmax(arr, size);
	for (int div = 1; div<=m; div *= 10)
	{
		countingsort(arr,size,div);
	}
	
}

int main()
{
	int size;
	cin >> size;
	int *arr = new int[size];
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	Raddixsort(arr, size);
	for(int i = 0; i < size; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
	
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
