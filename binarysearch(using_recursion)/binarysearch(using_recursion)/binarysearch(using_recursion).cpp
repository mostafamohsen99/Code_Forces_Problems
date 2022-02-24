// binarysearch(using_recursion).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int binarysearch(int a[], int m, int left, int right)
{
	if (left <= right)
	{
		if (left == right)
		{
			if (m == a[left])
				return left;
			else
				return -1;
		}
		int mid = (left + right) / 2;
		if (m == a[mid]) return mid;
		else if (m > a[mid])
			return binarysearch(a, m, mid + 1, right);
		else if (m < a[mid])
			return binarysearch(a, m, left, mid - 1);
	}
	else
		return -1;
}
int main()
{
	int arr[12] = {-1,4,6,10,14,23,29,33,45,56,62,70 };
	int m = -2;
	int index = binarysearch(arr, m, 0, 11);
	cout << index << endl;
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
