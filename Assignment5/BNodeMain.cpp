#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include "BNode.h"
using namespace std;
using namespace ds;

template <class T>
void append(BNode<T>*& root,const T& data)
{
	if(root == NULL)
	{
		root = new BNode<T>(data);
	}
	else if(root->GetLeft() == NULL)
	{
		root->SetLeft(new BNode<T>(data));
	}
	else if(root->GetRight() == NULL)
	{
		root->SetRight(new BNode<T>(data));
	}
	else if((root->GetLeft()->GetLeft() == NULL) || (root->GetLeft()->GetRight() == NULL))
	{
		append(root->GetLeft(),data);
	}
	else
	{
		append(root->GetRight(),data);
	}
}

template <typename T>
BNode<T>* detachLast(BNode<T>*& root)
{
	if(root == NULL)
	{
		return NULL; 
	}
	else if(root->IsLeaf())
	{
		BNode<T>* tmp = root;
		root = NULL;
		return tmp;  
	}
	else if(root->GetRight() == NULL)
	{
		BNode<T>* tmp = root->GetLeft();
		root->SetLeft(NULL);
		return tmp;
	}
	else if(root->GetLeft()->IsLeaf())
	{
		BNode<T>* tmp = root->GetRight();
		root->SetRight(NULL);
		return tmp;
	}
	else if(root->GetRight()->IsLeaf()) 
	{
		return detachLast(root->GetLeft());
	}
	else
	{
		return detachLast(root->GetRight());
	}
}

template <typename T>
bool search(BNode<T>* root,const T& data)
{
	if(root == NULL)
	{
		return false;
	}
	else if(root->GetData() == data)
	{
		return true;
	}
	else
	{
		return (search(root->GetLeft(),data) || search(root->GetRight(),data));
	}
}

template <typename T>
void infix(BNode<T>* root)
{
	if(root != NULL)
	{
		infix(root->GetLeft());
		std::cout << root->GetData() << " ";
		infix(root->GetRight());
	}
}

template <typename T>
void prefix(BNode<T>* root)
{
	if(root != NULL)
	{
		std::cout << root->GetData() << " ";
		prefix(root->GetLeft());
		prefix(root->GetRight());
	}
}

template <class T>
void postfix(BNode<T>* root)
{
	if(root != NULL)
	{
		postfix(root->GetLeft());
		postfix(root->GetRight());
		std::cout << root->GetData() << " ";
	}
}

int main()
{	BNode<char>* root=new BNode<char>(NULL);
	string path;
	char c;

	cout<<"Enter a file path to the binary tree character keys: ";
	getline(cin,path);
	ifstream ReadFile(path);

	while(ReadFile.get(c))
	{	append(root,c);}

	return 0;}
