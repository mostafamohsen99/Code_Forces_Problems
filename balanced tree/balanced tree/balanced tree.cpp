// balanced tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<algorithm>
using namespace std;
bool sign = true;
class node
{
public:
	int data;
	node *left;
	node *right;
	node(int m)
	{
		data = m;
		left = NULL;
		right = NULL;
	}
};
node *head = NULL;
void insert(int m)
{
	node *newnode = new node(m);
	if (head == NULL)
		head = newnode;
	else
	{
		node *ptr = head;
		bool a = true;
		bool b = true;
		while (1)
		{
			if ((ptr->data) < (newnode->data))
			{
				if (ptr->right == NULL)
				{
					ptr->right = newnode;
					a = false;
				}
				else
					ptr = ptr->right;
				if (a == false)
					break;
			}
			else if ((ptr->data) > (newnode->data))
			{
				if (ptr->left == NULL)
				{
					ptr->left = newnode;
					b = false;
				}
				else
					ptr = ptr->left;
				if (b == false)
					break;
			}
		}
	}
}
int depth(node *r);
bool isbalanced(node *head)
{
	int left;
	int right;
	if (head == NULL)
		return 1;
	 left = depth(head->left);
	 right = depth(head->right);
//	if (abs(left - right) <= 1 && isbalanced(head->left) && isbalanced(head->right))
	//	return 1;
	 if (abs(left - right) <= 1)
	 {
		 if (sign == false)
			 return 0;
		 return isbalanced(head->left);
		 return isbalanced(head->right);
	 }
	 else
	 {
		 sign = false;
		 return 0;
	 }
}
int depth(node *r)
{
	if (r == NULL)
		return 0;
	return 1 + max(depth(r->left), depth(r->right));

}
int main()
{
	int n;
	cin >> n;
	int arr[1000];
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	for (int i = 0; i < n; i++)
		insert(arr[i]);
	if (isbalanced(head))
		cout << "YES";
	else
		cout << "NO";
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
