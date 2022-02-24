// single linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
using namespace std;
class node
{
public:
	int key;
	int data;
	node *next;
	node()
	{
		next = NULL;
	}
	node(int k, int d)
	{
		key = k;
		data = d;
	}
};
class singlylinkedlist
{
public:
	node *head;
	singlylinkedlist()
	{
		head = NULL;
	}
	singlylinkedlist(node *n)
	{
		head = n;
	}
	//1.check if node exists using key value
	node* nodeexists(int k)
	{
		node *temp = NULL;
		node *ptr = head;
		while (ptr != NULL)
		{
			if (ptr->key == k)
			{
				temp = ptr;
			}
			ptr = ptr->next;
		}
		return temp;
}
	//2.append
	void appendnode(node *n)
	{
		if (nodeexists(n->key) != NULL)
			cout << "node already exists with key value" << n->key << endl;
		else
		{
			if (head == NULL)
			{
				head = n;
			}
			else
			{
				node *ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				ptr->next = n;
			}
		}
	}
		void prependnode(node *n)
		{
			if (nodeexists(n->key) != NULL)
			{
				cout << "node already exists with key=" << n->key << endl;
			}
			else
			{
				n->next = head;
				head = n;
				cout << "node prepended" << endl;
			}
		}
		void insertnode(int k,node *n)
		{
			node *ptr = nodeexists(k);
			if (ptr == NULL)
			{
				cout << "there is no value with" << k << endl;
			}
			else
			{
				if (nodeexists(n->key) != NULL)
				{
					cout << "node already exists with key value=" << n->key << endl;
				}
				else
				{
					n->next = ptr->next;
					ptr->next = n;
					cout << "node instered" << endl;
				}
			}
	}
		void deletenode(int k)
		{
			if (head == NULL)
				cout << "this is empty list";
			else if (head != NULL)
			{
				if (head->key == k)
				{
					head = head->next;
					cout << "Node UN-LINKED" << endl;
				}
				else
				{
					node*temp = NULL;
					node *prevptr = head;
					node* currentptr = head->next;
					while (currentptr != NULL)
					{
						if (currentptr->key == k)
						{
							temp = currentptr;
							currentptr = NULL;
						}
						else
						{
							prevptr = prevptr->next;
							currentptr = currentptr->next;
						}
					}
					if (temp != NULL)
					{
						prevptr->next = temp->next;
						cout << "Node un-linked with key value" << k << endl;
					}
					else
					{
						cout << "node doesn't exist with" << k << endl;
					}
				}
			}
		}
			void updatenodebykey(int k, int d)
			{
				node *ptr = nodeexists(k);
				if (ptr == NULL)
				{
					cout << "node doesn't exist with keyvalue" << k << endl;
				}
				else
				{
					ptr->data = d;
					cout << "node data updated successfully" << endl;
				}
			}
void display()
{
	if (head == NULL)
	{
		cout << "this is empty linked list" << endl;
	}
	else
	{
		node *temp = head;
		while (temp != NULL)
		{
			cout << temp->key << "    " << temp->data << endl;
			temp = temp->next;
		}
	}
}

};
int main()
{
	singlylinkedlist s1;
	int key, data, k;
	int option;
	do
	{
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl << endl;
		cin >> option;
		node *n1 = new node();
		switch (option)
		{
		case 0:
			break;
		case 1:
			cout << "enter key and data" << endl;
			cin >> key;
			cin >> data;
			n1->data = data;
			n1->key = key;
			s1.appendnode(n1);
			break;
		case 2:
			cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
			cin >> key;
			cin >> data;
			n1->key = key;
			n1->data = data;
			s1.prependnode(n1);
			break;
		case 3:
			cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key;
			cin >> data;
			n1->key = key;
			n1->data = data;

			s1.insertnode(k, n1);
			break;
		case 4:
			cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
			cin >> k;
			s1.deletenode(k);
			break;
		case 5:
			cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
			cin >> key;
			cin >> data;
			s1.updatenodebykey(key, data);
			break;
		case 6:
			s1.display();
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
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
