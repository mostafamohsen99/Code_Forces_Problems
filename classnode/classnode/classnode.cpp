// classnode.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
class node
{
	int data;
	node * next;
public:
	node() 
	{
		data = 0;
		next = NULL;
	}
	node(int d)
	{
		data = d;
		next = NULL;
	}
	int getdata()
	{
		return data;
	}
	void setdata(int d)
	{
		data = d;
	}
	node* getnext()
	{
		return next;
	}
	void setnext(node *n)
	{
		next = n;
	}
	friend class list;
};
class list {
	node *chain;
public:
	list(int d)
	{
		chain = new node(d);
	}
	 void additem(int a);
};
void list::additem(int a)//item in the first
{
	node *temp = new node(a);
	temp->next = chain;
	chain = temp;
}
int main()
{
	node n1, n2(70);
	n1.setnext(&n2);
	node *chain =&n1;
	cout << chain->getdata()<<endl;
	cout<<chain->getnext();
	chain = chain->getnext();
	cout << chain->getdata();


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
