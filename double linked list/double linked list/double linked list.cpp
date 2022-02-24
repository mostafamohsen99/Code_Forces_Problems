// double linked list.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
	node *previous;
	node()
	{
		next = NULL;
		previous = NULL;
	}
	node(int key, int data)
	{
		this->key = key;
		this->data = data;
	}
};
class doublylinkedlist
{
public:
	node *head;
	doublylinkedlist()
	{
		head == NULL;
	}
	doublylinkedlist(node *n)
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
				temp = ptr;
			ptr = ptr->next;
		}
		return temp;
	}
	//2.Append node to list
	void appendnode(node *n)
	{
		if (nodeexists(n->key) != NULL)
			cout << "node exists with key=" << n->key;
		else
		{
			if (head == NULL)
			{
				head = n;
				cout << "node appended" << endl;
			}
			else
			{
				node *ptr = head;
				while (ptr->next != NULL)
				{
					ptr = ptr->next;
				}
				n->previous = ptr;
				ptr->next = n;
				n->next = NULL;
				cout << "node appended" << endl;
			}
		}
	}
	void prependnode(node *n)
	{
		if (nodeexists(n->key) != NULL)
		{
			cout << "the node is represented with key value" << (n->key) << endl;
		}
		else
		{
			if(head==NULL)
				{
				head = n;
				cout << "node prepended" << endl;
				}
			else
			{
				n->next = head;
					head->previous = n;
					head = n;
					cout << "node prepended" << endl;
			}
		}
	}
	void insertnodebykey(int k, node *n)
	{
		node *ptr = nodeexists(k);
		if (ptr == NULL)
		{
			cout << "there is no key with value" << k << endl;
		}
		else
		{
			node *newnode = ptr->next;
			if (nodeexists(n->key) != NULL)
			{
				cout << "node exists with key value" << n->key << endl;
			}
			else
			{
				if (newnode == NULL)
				{
					newnode->previous = ptr;
					ptr->next = newnode;
					cout << "node inserted at the end" << endl;
				}
				else
				{
					n->previous = ptr;
					ptr->next = n;
					n->next = newnode;
					newnode->previous = n;
					cout << "node inserted in between" << endl;
				}

			}
		}
	}
	void deletenodebykey(int k)
	{
		node *ptr = nodeexists(k);
		if (k == NULL)
		{
			cout << "no node exists with key=" << k << endl;
		}
		else
		{
			if (head == NULL)
			{
				cout << "this is empty list" << endl;
			}
			else if ((head->key) == k)
			{
				head = head->next;
				cout << "node deleted at the beginning" << endl;
			}
			else
			{
				node *currentptr = ptr->next;
				node *prevptr = ptr->previous;
				prevptr->next = currentptr;
				currentptr->previous = prevptr;
				cout << "node deleted at the middle" << endl;
			}
		}
	}
	void updateNodeByKey(int k, int d) {

		node * ptr = nodeexists(k);
		if (ptr != NULL) {
			ptr->data = d;
			cout << "Node Data Updated Successfully" << endl;
		}
		else {
			cout << "Node Doesn't exist with key value : " << k << endl;
		}

	}

	// 7th printing
	void printList() {
		if (head == NULL) {
			cout << "No Nodes in Doubly Linked List";
		}
		else {
			cout << endl << "Doubly Linked List Values : ";
			node *temp = head;

			while (temp != NULL) {
				cout << "(" << temp -> key << "," << temp -> data << ") <--> ";
				temp = temp->next;
			}
		}

	}

};

int main() {

	doublylinkedlist obj;
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

			obj.insertnodebykey(k1, n1);
			break;

		case 4:

			cout << "Delete Node By Key Operation - \nEnter key of the Node to be deleted: " << endl;
			cin >> k1;
			obj.deletenodebykey(k1);

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
