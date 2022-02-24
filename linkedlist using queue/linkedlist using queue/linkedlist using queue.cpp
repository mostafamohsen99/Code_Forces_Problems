// linkedlist using queue.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
		key = 0;
		data = 0;
		next = NULL;
	}
	node(int key, int data)
	{
		this->key = key;
		this->data = data;
		next = NULL;
	}
};
class queue
{
public:
	node *front;
	node *rear;
	queue()
	{
		front = NULL;
		rear = NULL;
	}
	bool isempty()
	{
		if (rear == NULL && front == NULL)
			return true;
		else
			return false;
	}
	bool Nodekeyexists(node *n)
	{
		node *temp = front;
		bool exist = false;
		while (temp != NULL)
		{
			if (temp->key == n->key)
			{
				exist = true;
				break;
			}
			temp = temp->next;
		}
		return exist;
	}
	void enqueue(node *n)
	{
		if (isempty())
		{
			front = n;
			rear = n;
			cout << "node enqueued successfully" << endl;
		}
		else if (Nodekeyexists(n))
		{
			cout << "the node already exists with this key value" << endl;
		}
		else
		{
			node *temp = rear;
			temp->next = n;
			rear = n;
			cout << "node enqueued successfully" << endl;
		}
	}
	node* dequeue()
	{
		node *temp = NULL;
		if (isempty())
		{
			cout << "stack under flow" << endl;
			return temp;
		}
		else
		{
			if (rear == front)
			{
				temp = front;
				rear = NULL;
				front = NULL;
				return temp;
			}
			else
			{
				temp = front;
				front = front->next;
				return temp;
			}
		}
	}
	int count()
	{
		int count = 0;
		node *temp = front;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void display()
	{
		if (isempty())
		{
			cout << "queue is empty" << endl;
		}
		else
		{
			node *temp = front;
			while (temp != NULL)
			{
				cout << "(" << temp->key << "," << temp->data << ")";
				temp = temp->next;
			}
			cout << endl;
		}
	}

};

int main() {
	queue q;
	int option, key, data;

	do {
		cout << "What operation do you want to perform?"
			<< "Select Option number. Enter 0 to exit." << endl;
		cout << "1. Enqueue()" << endl;
		cout << "2. Dequeue()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. count()" << endl;
		cout << "5. display()" << endl;
		cout << "6. Clear Screen" << endl << endl;
		cin >> option;

		//Node n1 = new Node();
		node * new_node = new node();


		switch (option) {
		case 0:
			break;
		case 1:
			cout << "ENQUEUE Function Called -" << endl;
			cout << "Enter KEY and VALUE of NODE to ENQUEUE "
				<< "in the Queue"
				<< endl;
			cin >> key;
			cin >> data;
			new_node->key = key;
			new_node->data = data;
			q.enqueue(new_node);
			break;
		case 2:
			cout << "DEQUEUE Function Called - " << endl;
			new_node = q.dequeue();
			cout << "Dequeued Value is: (" << new_node->key << ","
				<< new_node->data << ")";
			delete new_node;
			cout << endl;

			break;
		case 3:
			cout << "isEmpty Function Called - " << endl;
			if (q.isempty())
				cout << "Queue is Empty" << endl;
			else
				cout << "Queue is NOT Empty" << endl;
			break;
		case 4:
			cout << "Count Function Called - " << endl;
			cout << "No of nodes in the Queue: " << q.count()
				<< endl;
			break;
		case 5:
			cout << "Display Function Called - " << endl;
			q.display();
			cout << endl;
			break;

		case 6:
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
