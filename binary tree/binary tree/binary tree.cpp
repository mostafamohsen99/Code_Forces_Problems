// binary tree.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
/*
method to calculate using tree*/
class node {
public:
	char data;
	node *left_root;
	node *right_root;
	bool is_numeric()
	{
		if (this->data >= '0'&&this->data <= '9')
		{
			return 1;
		}
		else return 0;
	}
	int to_numeric()
	{
		return data - 48;
	}
	int eval(int operator1, int operator2, char sign)
	{
		if (sign == '+')
			return operator1 + operator2;
		else if (sign == '-')
			return operator1 - operator2;
		else if (sign == '/')
			return operator1 / operator2;
		else if (sign == '*')
			return operator1 * operator2;
	}
	int evaluate(node *subtree_root)
	{
		if (subtree_root->is_numeric())
			return to_numeric();
		int left_value = evaluate(subtree_root->left_root);
		int right_value = evaluate(subtree_root->right_root);
		return eval(left_value, right_value, subtree_root->data);
	}

};
class tree
{
	int count_of_leaves(node *subtree_root)
	{
		if (subtree_root->left_root == nullptr&&subtree_root->right_root == nullptr)
		{
			return 1;
		}
		int leaves = 0;
		if (subtree_root->left_root != NULL)
		{
			leaves += count_of_leaves(subtree_root->left_root);
		}
		if (subtree_root->right_root != NULL)
		{
			leaves += count_of_leaves(subtree_root->right_root);
		}
		return leaves;

	}
public:
	int number_of_leaves()
	{
		
	}
};


int main()
{
    std::cout << "Hello World!\n";
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
