#include<iostream>
using namespace std;

class node {
	public:
	int data;
	node * right;
	node * left;
	node(int value)
		{
			data = value;
			right = NULL;
			left = NULL;
		}
	};
	
class BiST{
	public:
	node * root;
	BiST()
		{
			root = NULL;
		}
	void insert (int value)
		{
			if(root == NULL)
			root = new node(value);
			else insert2(value, root);
		}
	void insert2(int value, node * current)
		{
			if (value < current -> data)
				{
					if(current -> left == NULL)
					current -> left = new node(value);
					else 
					insert2(value, current -> left);
				}
			else 
				{
					if (current -> right == NULL)
					current -> right = new node(value);
					else insert2(value, current -> right);
				}
		}
	void display2(node* current)
		{
			if(current -> left != NULL)
			{display2(current -> left);}
			cout << current->data<<",";
			if(current -> right != NULL)
			{display2(current -> right);}
		}
	void display()
		{
			if(root == NULL)
				cout<< "The tree is empty\n";
			
			else display2(root);
			cout<<endl;
		}
	node * search(int value)
		{
			node * m = search2(value, root);
			if(m == NULL) 
			{cout<< "THis element is not present in the tree\n";
			return m;}	
			else return search2(value, root); 
		}
	node * search2(int value, node * current)
		{
			if(current->data == value)
			{return current;}
			else if(value < current -> data)
				{
					if (current -> left == NULL)
					return NULL;
					else search2(value, current -> left);
				}
			else
				{
					if(current -> right == NULL)
					return NULL;
					else search2(value, current -> right);
				}
		}
	
	};
	

int main()
	{
		BiST t1;
		//for(int i=0; i< 10; i++)
		//{
		//	t1.insert(i);
		//}
		//
		t1.display();
		t1.insert(2);
		t1.insert(26);
		t1.display();
		t1.insert(7);
		t1.insert(4);
		t1.insert(98);
		t1.insert(1);
		t1.insert(5);
		t1.display();
		node*n1 = t1.search(1); 
		return 0;
	}	
	
	
	
	
	
	
