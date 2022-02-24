// banking record.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include<string>
using namespace std;
class bank
{
private:
	int accountnumber;
	string firstname;
	string lastname;
	int balance;
	int counter = 0;
	int accountarr[50];
	string firstarr[50];
	string lastarr[50];
	int balancearr[50];
	bool f = false;
public:
	void read_data()
	{
		bool b = false;
		cout << "Enter Account Number" ;
		cin >> accountnumber;
		cout << "Enter first name";
		cin >> firstname;
		cout << "Enter last name";
		cin >> lastname;
		cout << "Enter Balance";
		cin >> balance;
		for (int i = 0; i < counter; i++)
		{
			if (accountnumber == accountarr[i])
			{
				b = true;
				accountarr[i] = accountnumber;
				firstarr[i] = firstname;
				lastarr[i] = lastname;
				balancearr[i] = balance;
				break;
			}

		}
		if (b == false)
		{
			accountarr[counter] = accountnumber;
			firstarr[counter] = firstname;
			lastarr[counter] = lastname;
			balancearr[counter] = balance;
			counter++;
		}
	}
	void show_data()
	{
		int a;
		bool b = false;
		cout << "Enter Record Number to show:";
		cin >> a;
		for (int i = 0; i < counter; i++)
		{
			if (a == accountarr[i])
			{
				b = true;
				cout << accountarr[i] << endl;
				cout << firstarr[i] << endl;
				cout << lastarr[i] << endl;
				cout << balancearr[i] << endl;
				break;
			}
		}
		if (b == false)
		{
			cout << "Error in Opening!File not found" << endl;
		}

	
	}
	void search_data( )
	{
		int m;
		bool a = false;
		cout << "there are" << counter  << "Records on a file" << endl;
		cout << "Enter the Record number to search:";
		cin >> m;
		for (int i = 0; i < counter; i++)
		{
			if (m == accountarr[i])
			{
				cout << "account number" << m << "is found" << endl;
				a = true;
				break;
			}
		}
		if(a==false)
		{
			cout << "Error in Opening!File not found" << endl;
		}
	}
	void Edit_Data()
	{
		int k;
		bool a = false;
		cout << "There are" << counter  << "Record in the file" << endl;
		cout << "Enter Record number to edit";
		cin >> k;
		for (int i = 0; i < counter; i++)
		{
			if (k == accountarr[i])
			{
			 a = true;
				cout << "Record" << k << "has the following data" << endl;
				cout << "Account Number:" << accountarr[i] << endl;
				cout << "Firstname:" << firstarr[i] << endl;
				cout << "Lastname" << lastarr[i] << endl;
				cout << "Current Balance" << balancearr[i] << endl;
				cout << "-------------------" << endl;
				cout << "Enter Data to Modify" << endl;
				cout << "Enter Account number";
				cin >> accountarr[i];
				cout << "Enter First Name";
				cin >> firstarr[i];
				cout << "Enter last name";
				cin >> lastarr[i];
				cout << "Enter Balance";
				cin >> balancearr[i];
				break;
			}
		}
		if (a == false)
		{
			cout << "Error in Opening!File not found" << endl;
		}
		
	}
	void delete_data()
	{
		int k;
		bool a = false;
		cout << "There are" << counter  << "Record in the file" << endl;
		cout << "Enter Record number to delete";
		cin >> k;
		for (int i = 0; i < counter; i++)
		{
			if (k == accountarr[i])
			{
				 a = true;
				 f = true;
				for (int j = i; j < counter-1; j++)
				{
					accountarr[j] = accountarr[j + 1];
					firstarr[j] = firstarr[j + 1];
					lastarr[j] = lastarr[j + 1];
					balancearr[j] = balancearr[j + 1];
				}
				break;
			}
		}
		if (f == true)
		{
			counter--;
			f = false;
		}
		if (a == false)
		{
			cout << "Error in Opening!File not found" << endl;
		}


	}
};

int main()
{
	bank s;
	int x;
	int m;
	cout << "***Account Information System" << endl;
	cout << "select one operation below" << endl;
	cout << "1-->Add record to file" << endl;
	cout << "2-->Show record from file" << endl;
	cout << "3-->Search Record from file" << endl;
	cout << "4-->Update Record" << endl;
	cout << "5-->Delete Record" << endl;
	cout << "6-->Quit" << endl;
	while (1)
	{
		cout << "Enter your choice";
		cin >> x;
		if (x == 1)
		{
			s.read_data();
		}
		if (x == 2)
		{
			s.show_data();
		}
		if (x == 3)
		{
			s.search_data();
		}
		if (x == 4)
		{
			s.Edit_Data();
		}
		if (x == 5)
		{
			s.delete_data();
		}
		if (x == 6)
		{
			break;
		}
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
