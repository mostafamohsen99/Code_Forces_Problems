// sum k.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	int k, n;
	int num1, num2;
	bool result = false;
	cin >> n;
	int *arr = new int(n);
	cin >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}
	delete[] arr;
	/*for (int j = 0; j < n; j++)
	{
		for (int l = j + 1; l < n; l++)
		{
			//cout << arr[j] << endl;
			//cout << arr[l] << endl;
			if (arr[j] + arr[l] == k)
			{
				if (arr[l] >= arr[j])
				{
					num1 = arr[j];
					num2 = arr[l];
				}
				else
				{
					num1 = arr[l];
					num2 = arr[j];
				}
				result = true;
				break;
			}
		}
	}
	delete[] arr;
	if (result == false)
	{
		cout << "No";
	}
	else if (result == true)
	{
		cout << "Yes" << endl;
		cout << num1 << " " << num2 << endl;

	}
	*/
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
