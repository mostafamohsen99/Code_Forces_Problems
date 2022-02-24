// sumk(nlogn).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int num1 = 0, num2 = 0;
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
int sum(int arr[], int n, int K)
{
	int i = 0;
	int j = n - 1;
	while (i <= j)
	{
		if (arr[i] + arr[j] == K)
		{
			num1 = arr[i];
			num2 = arr[j];
			return 1;
		}
		else if (arr[i] + arr[j] < K)
			i = i + 1;
		else
			j = j - 1;
	}
	return -1;
}
int main()
{
	int k, n;
	int summ;
	cin >> n;
	int *arr = new int[n];
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	quickSort(arr, 0, n - 1);
	summ = sum(arr, n, k);
	if (summ == -1)
	{
		cout << "No";
	}
	else
	{
		cout << "Yes" << endl;
		cout << num1 << " " << num2 << endl;
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
