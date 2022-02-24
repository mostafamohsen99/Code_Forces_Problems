// circular linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	node(int k,int d)
	{
		key = k;
		data = d;
	}
};
class circularlinkedlist
{

public:
	node *head;
	circularlinkedlist()
	{
		head = NULL;
	}
	circularlinkedlist(node *n)
	{
		head = n;
	}
	node* nodeexists(int k)
	{
		node *temp = NULL;
		node *ptr = head;
		if (ptr == NULL)
			return temp;
		do
		{
			{
				if ((ptr->key) == k)
					temp = ptr;
				ptr = ptr->next;
			}
			return temp;
		} while (ptr != head);
	}
	void appendnode(node *n)
	{
		if (nodeexists(n->key) != NULL)
			cout << "node existed with key value=" << n->key;
		else
		{
			if (head == NULL)
			{
				head = n;
				n->next = head;
				cout << "node appended" << endl;
			}
			else
			{
				node *ptr = head;
				while ((ptr->next) != head)
				{
					ptr = ptr->next;
				}
				ptr->next = n;
				n->next = head;
				cout << "node appended" << endl;
			}
		}
	}
		void prependnode(node *n)
		{
			if (nodeexists(n->key) != NULL)
			{
				cout << "node exists with key value=" << n << endl;
			}
			else
			{
				if (head == NULL)
				{
					head = n;
					n->next = head;
					cout << "node prepended at first" << endl;
				}
				else
				{

					node*ptr = head;
					while (ptr->next != head)
					{
						ptr = ptr->next;
					}
					ptr->next = n;
					n->next = head;
					head = n;
				}
			}
	}
		void insertnodeafterkey(int k, node *n)
		{
			node *ptr = nodeexists(k);
			if (ptr == NULL)
				cout << "the value of key" << k << "is not found" << endl;
			else
			{
				if (nodeexists(n->key) != NULL)
				{
					cout << "the value of key in the list" << endl;
				}
				else
				{
					node *newnode = ptr->next;
					if (ptr->next == head)
					{
						ptr->next = n;
						n->next = head;
						cout << "instered at end" << endl;
					}
					else
					{
						ptr->next = n;
						n->next = ptr->next;
						cout << "inserted at middle" << endl;

					}
				}
			}
		}
		void deletebykey(int k)
		{
			node *ptr = nodeexists(k);
			if (ptr == NULL)
			{
				cout << "there is no deleted item" << endl;
			}
			else
			{
				if (ptr == head)
				{
					if (head->next == head)
					{
						head = NULL;
						cout << "node un-linked" << endl;
					}
					else
					{
						node *ptr1 = head;
						while (ptr1->next != head)
						{
							ptr1 = ptr1->next;
						}
						ptr1->next = head->next;
						head = head->next;
						cout << "un-linked with key value" << k << endl;
					}
				}
				else
				{
					node *temp = NULL;
					node *prevptr = ptr;
					node *currentptr = ptr->next;
					while (currentptr != NULL)
					{
						if (currentptr->key == k)
						{
							temp = currentptr;
							currentptr = NULL;
						}
						currentptr = currentptr->next;
						prevptr = prevptr->next;
					}
					prevptr->next = temp->next;
				}
			}
		}
void updateNodeByKey(int k, int new_data) {

	node * ptr = nodeexists(k);
	if (ptr != NULL) {
		ptr -> data = new_data;
		cout << "Node Data Updated Successfully" << endl;
	}
	else {
		cout << "Node Doesn't exist with key value : " << k << endl;
	}

}

// 7th printing
void printList() {
	if (head == NULL) {
		cout << "No Nodes in Circular Linked List";
	}
	else {
		cout << endl << "head address : " << head << endl;
		cout << "Circular Linked List Values : " << endl;

		node * temp = head;

		do {
			cout << "(" << temp -> key << "," << temp -> data << "," << temp -> next << ") --> ";
			temp = temp -> next;
		} while (temp != head);
	}

}

};

int main() {

	circularlinkedlist obj;
	int option;
	int key1, k1, data1;
	do {
		cout << "\nWhat operation do you want to perform? Select Option number. Enter 0 to exit." << endl;
		cout << "1. appendNode()" << endl;
		cout << "2. prependNode()" << endl;
		cout << "3. insertNodeAfter()" << endl;
		cout << "4. deleteNodeByKey()" << endl;
		cout << "5. updateNodeByKey()" << endl;
		cout << "6. print()" << endl;
		cout << "7. Clear Screen" << endl << endl;

		cin >> option;
		node * n1 = new node();
		//Node n1;

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Append Node Operation \nEnter key & data of the Node to be Appended" << endl;
			cin >> key1;
			cin >> data1;
			n1 -> key = key1;
			n1 -> data = data1;
			obj.appendnode(n1);
			//cout<<n1.key<<" = "<<n1.data<<endl;
			break;

		case 2:
			cout << "Prepend Node Operation \nEnter key & data of the Node to be Prepended" << endl;
			cin >> key1;
			cin >> data1;
			n1 -> key = key1;
			n1 -> data = data1;
			obj.prependnode(n1);
			break;

		case 3:
			cout << "Insert Node After Operation \nEnter key of existing Node after which you want to Insert this New node: " << endl;
			cin >> k1;
			cout << "Enter key & data of the New Node first: " << endl;
			cin >> key1;
			cin >> data1;
			n1 -> key = key1;
			n1 -> data = data1;

			obj.insertnodeafterkey(k1, n1);
			break;

		case 4:

			cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
			cin >> k1;
			obj.deletebykey(k1);

			break;
		case 5:
			cout << "Update Node By Key Operation - \nEnter key & NEW data to be updated" << endl;
			cin >> key1;
			cin >> data1;
			obj.updateNodeByKey(key1, data1);

			break;
		case 6:
			obj.printList();

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
