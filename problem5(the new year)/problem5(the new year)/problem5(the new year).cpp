// problem5(the new year).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

int main()
{
	int x, y, z;
	int distance = 0;
	int middle = 0;
	int largest = 0;
	int smallest = 0;
	int result = 0;
	cin >> x >> y >> z;
	if (x >=y)
	{
		if (y >= z)
		{
			largest = x;
			middle = y;
			smallest = z;
		}
		else
		{
			if (x >= z)
			{
				largest = x;
				middle = z;
				smallest = y;
			}
			else
			{
				largest = z;
				middle = x;
				smallest = y;
			}
		}
	}
	else
	{
		if (x >= z)
		{
			largest = y;
			middle = x;
			smallest = z;
		}
		else
		{
			if (y >= z)
			{
				largest = y;
				middle = z;
				smallest = x;
			}
			else
			{
				largest = z;
				middle = y;
				smallest = x;
			}
		}
	}
	result = (largest - middle) + (middle - smallest);
	cout << result;
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
