// Mode(new).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<math.h>
using namespace std;

int partition(int arr[], int low, int high)
{
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++)
	{

		if (arr[j] <= pivot)
		{
			i++;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);
	return (i + 1);
}

void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{

		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
int main()
{
	int longest = 1;
	int number;
	int modnum = 1;
	bool result = false;
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	for (int j = 0; j < n - 1; j++)
	{
		if (arr[j] == arr[j + 1])
		{
			result = true;
			//cout<<j<<' '<<arr[j]<<endl;
			longest++;
			//cout<<longest<<endl;
			if (longest >= modnum)
			{
				modnum = longest;
				//cout<<modnum<<endl;
				number = arr[j];
				//cout<<number<<endl;
			}
		}
		else
		{
			longest = 1;
		}
	}
	if (result == false)
	{
		number = arr[n - 1];
	}
	cout << number;
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
