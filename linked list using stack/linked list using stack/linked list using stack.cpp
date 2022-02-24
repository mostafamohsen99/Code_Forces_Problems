// linked list using stack.cpp : This file contains the 'main' function. Program execution begins and ends there.
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
class stack
{
public:
	node *top;
	stack()
	{
		top = NULL;
	}
	bool isempty()
	{
		if (top == NULL)
			return true;
		else
			return false;
	}
	bool Checkifnodeexist(node *n)
	{
		node *temp = top;
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
	void push(node *n)
	{
		if (isempty())
		{
			top = n;
			cout << "node pushed successfully" << endl;
		}
		else if (Checkifnodeexist(n))
		{
			cout << "node already exists with this key value" << endl;

		}
		else
		{
			n->next = top;
			top = n;
			cout << "node pushed" << endl;

		}
	}
	node* pop()
	{
		node *temp = NULL;
		if (isempty())
		{
			cout << "stack under flow" << endl;
			return temp;
		}
		else
		{
			temp = top;
			top = top->next;
			return temp;
		}
	}
	node *peek()
	{
		if (isempty())
		{
			cout << "stack under flow" << endl;
			return NULL;
		}
		else
		{
			return top;
		}
	}
	int count()
	{
		int count = 0;
		node *temp = top;
		while (temp != NULL)
		{
			count++;
			temp = temp->next;
		}
		return count;
	}
	void display()
	{
		node *temp = top;
		while (temp != NULL)
		{
			cout << "(" << temp->key <<","<< temp->data << ")";
			temp = temp->next;
		}
	}
};


int main()
{
	stack s1;
	int option;
	int key, data;
	do {
		cout << "what operation do you want to perform" << endl;
		cout << "1.push" << endl;
		cout << "2.pop" << endl;
		cout << "3.isempty" << endl;
		cout << "4.peek" << endl;
		cout << "5.count" << endl;
		cout << "6.display" << endl;
		cout << "7.clear screen" << endl;
		node *newnode = new node();
	cin >> option;
	switch (option)
	{
	case 0:
		break;
	case 1:
		cout << "enter key&data values" << endl;
		cin >> key >> data;
		newnode->key = key;
		newnode->data = data;
		s1.push(newnode);
		break;
	case 2:
		newnode = s1.pop();
		cout << "top of stack is" << newnode->key << newnode->data << endl;
		delete newnode;
		cout << endl;
		break;
	case 3:
		if (s1.isempty())
		{
			cout << "stack is empty";
		}
		else
		{
			cout << "stack is not empty";
		}
		break;
	case 4:
		if (s1.isempty())
		{
			cout << "stack is empty" << endl;
		}
		else
		{
			newnode = s1.peek();
			cout << "top stack is" << newnode->key << "" << newnode->data << endl;
		}
		break;
	case 5:
		cout << "no of nodes on the stack" << s1.count() << endl;
		break;
	case 6:
		s1.display();
		cout << endl;
		break;
	case 7:
		system("cls");
		break;
	default:
		cout << "Enter proper option number" << endl;
	}
}	while (option != 0);
}
/*#include<iostream>

using namespace std;

class Node {
public:
	int key;
	int data;
	Node * next;

	Node() {
		key = 0;
		data = 0;
		next = NULL;
	}
	Node(int k, int d) {
		key = k;
		data = d;
		next = NULL;
	}
};

class Stack {
public:
	Node * top;

	Stack() {
		top = NULL;
	}

	bool isEmpty() {
		if (top == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	bool checkIfNodeExist(Node * n) {
		Node * temp = top;
		bool exist = false;
		while (temp != NULL) {
			if (temp -> key == n -> key) {
				exist = true;
				break;
			}
			temp = temp -> next;
		}
		return exist;
	}

	void push(Node * n) {
		if (top == NULL) {
			top = n;
			cout << "Node  PUSHED successfully" << endl;
		}
		else if (checkIfNodeExist(n)) {
			cout << "Node already exist with this Key value." <<
				"Enter different Key value" << endl;
		}
		else {
			Node * temp = top;
			top = n;
			n -> next = temp;
			cout << "Node  PUSHED successfully" << endl;
		}

	}

	Node * pop() {
		Node * temp = NULL;
		if (isEmpty()) {
			cout << "stack underflow" << endl;
			return temp;
		}
		else {
			temp = top;
			top = top -> next;
			return temp;
		}
	}
	Node * peek() {
		//Node *temp = NULL;
		if (isEmpty()) {
			cout << "stack underflow" << endl;
			return NULL;
		}
		else {
			return top;
		}
	}
	int count() {
		int count = 0;
		Node * temp = top;
		while (temp != NULL) {
			count++;
			temp = temp -> next;
		}
		return count;
	}
	void display() {
		cout << "All values in the Stack are :" << endl;
		Node * temp = top;
		while (temp != NULL) {
			cout << "(" << temp -> key << "," << temp -> data << ")" << " -> " <<
				endl;
			temp = temp -> next;
		}
		//cout<< "Total no of Nodes in the stack :" <<count()
		//<<endl;
		cout << endl;
	}

};

int main() {
	stack s1;
	int option, key, data;

	do {
		cout << "What operation do you want to perform?" <<
			"Select Option number. Enter 0 to exit." << endl;
		cout << "1. Push()" << endl;
		cout << "2. Pop()" << endl;
		cout << "3. isEmpty()" << endl;
		cout << "4. peek()" << endl;
		cout << "5. count()" << endl;
		cout << "6. display()" << endl;
		cout << "7. Clear Screen" << endl << endl;
		cin >> option;

		//Node n1 = new Node();
		node * new_node = new node();

		switch (option) {
		case 0:
			break;
		case 1:
			cout << "Enter KEY and VALUE of NODE to push in the stack" <<
				endl;
			cin >> key;
			cin >> data;
			new_node -> key = key;
			new_node -> data = data;
			s1.push(new_node);
			break;
		case 2:
			cout << "Pop Function Called - Poped Value: " << endl;
			new_node = s1.pop();
			cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")";
			delete new_node;
			cout << endl;

			break;
		case 3:
			if (s1.isempty())
				cout << "Stack is Empty" << endl;
			else
				cout << "Stack is not Empty" << endl;
			break;
		case 4:
			if (s1.isempty()) {
				cout << "Stack is Empty" << endl;
			}
			else {
				cout << "PEEK Function Called : " << endl;
				new_node = s1.peek();
				cout << "TOP of Stack is: (" << new_node -> key << "," << new_node -> data << ")" <<
					endl;
			}
			break;
		case 5:
			cout << "Count Function Called: " << endl;
			cout << "No of nodes in the Stack: " << s1.count() << endl;
			break;

		case 6:
			cout << "Display Function Called - " << endl;
			s1.display();
			cout << endl;
			break;
		case 7:
			system("cls");
			break;
		default:
			cout << "Enter Proper Option number " << endl;
		}

	} while (option != 0);

	return 0;
}*/



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
