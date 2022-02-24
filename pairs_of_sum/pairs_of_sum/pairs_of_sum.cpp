// pairs_of_sum.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
	unsigned int size;
	int num, num1, num2, c1 = 0, c2 = 0, sum = 0, counter = 0, sum1 = 0;
	int arr[100000];
	cin >> size;
	cin >> num;
	for (int i = 0; i < size; i++)
	{
		cin >> arr[i];
	}
	vector <int > v(arr, arr + size);
	vector <int>::iterator begin_1, end_1;
	sort(v.begin(), v.end());
	begin_1 = v.begin();
	end_1 = v.end() - 1;
	while (begin_1 != end_1)
	{
		if ((*begin_1) + (*end_1) == num)
		{
			num1 = (*begin_1);
			num2 = (*end_1);
			if (num1 == num2)
			{
				while (begin_1 != end_1)
				{
					end_1--;
					counter++;
				}
				for (int i = counter; i > 0; i--)
				{
					sum += i;
				}
			}
			else
			{
				c1 = 1;
				c2 = 1;
				while ((*begin_1) == num1)
				{
					begin_1++;
					if (*(begin_1) == num1)
						c1++;
				}
				begin_1--;
				while ((*end_1) == num2)
				{
					end_1--;
					if ((*end_1) == num2)
						c2++;
				}
				sum1 += (c1*c2);
			}
		}
		else if ((*begin_1) + (*end_1) < num)
			begin_1++;
		else
			end_1--;
	}
	cout << sum1+sum << endl;
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
