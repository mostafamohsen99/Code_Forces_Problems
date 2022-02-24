// problem4(Even_odd).cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include<string>
int main()
{
	unsigned long long n, k;
	int counter = 1;
	bool a = 1;
	cin >> n >> k;
	vector <unsinged long long> arr;
	arr.resize(1000000000000);
	for (int i = 0; i <= (n/2); i++)
	{
		arr[i] = counter;
		if (n == counter + 1)
			break;
		counter += 2;
	}
	counter = 2;
	for (int i = n/2; i < n; i ++)
	{
		if ((n%2!=0)&&a==1)
		{
			i = i + 1;
			a = 0;
		}
		arr[i] = counter;
		counter += 2;
	}
	cout << arr[k-1] << endl;

    
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
