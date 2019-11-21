#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BNode.h"
using namespace std;
using namespace ds;

template <class T>
void Insert(BNode<T>*& root,T value)
{	if(root==NULL)
	{	root=new BNode<T>(value);}
	else if(value>=root->GetData())
	{	Insert(root->GetRight(),value);}
	else
	{	Insert(root->GetLeft(),value);}}
/*
template <class T>
int Height(BNode<T>* root,int max)
{	if(root==NULL || root->IsLeaf())
	{	return max;}
	else
	{	max+=1;
		if(Height(root->GetLeft(),max)>Height(root->GetRight(),max))
		{	return 
*/
template <class T>
bool IsFull(BNode<T>* root)
{	if(root==NULL)
	{	return true;}
	else if(root->IsLeaf())
	{	return true;}
	else if(root->GetLeft()!=NULL && root->GetRight()!=NULL)
	{	return IsFull(root->GetLeft()) && IsFull(root->GetRight());}
	else
	{	return false;}}

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

template <class T,class Process>
void infixFunction(BNode<T>* root,Process F)
{	if(root!=NULL)
	{	infixFunction(root->GetLeft());
		F(root->GetData());
		infixFunction(root->GetRight());}}

template <class T>
void Print(const T& data)
{	cout<<data<<"\n";}

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
/*
template <class T>
T MinimumValue(BNode<T>* root) //recursively
{	if(root==NULL)
	{	throw "Empty Tree";}
	else if(root->GetLeft()==NULL)
	{	return root->GetData();}
	else
	{	return MinimumValue(root->GetLeft());}}
*/
template <class T>
T MinimumValue(BNode<T>* root) //iteratively
{	if(root==NULL)
	{	throw "Empty Tree";}
	BNode<T>* tmp=root;
	while(tmp->GetLeft()!=NULL)
	{	tmp=tmp->GetLeft();}
	return tmp->GetData();}
/*
template <class T>
T MaximumValue(BNode<T>* root) //recursively
{       if(root==NULL)
        {       throw "Empty Tree";}
        else if(root->GetRight()==NULL)
        {       return root->GetData();}
        else
        {       return MaximumValue(root->GetRight());}}
*/
template <class T>
T MaximumValue(BNode<T>* root) //iteratively
{	if(root==NULL)
        {       throw "Empty Tree";}
	BNode<T>* tmp=root;
        while(tmp->GetRight()!=NULL)
        {       tmp=tmp->GetRight();}
        return tmp->GetData();}

template <class T>
T Range(BNode<T>* root)
{	if(root==NULL)
	{	return -1;}
	else
	{	return MaximumValue(root)-MinimumValue(root);}}

int main()
{
/*	srand(time(NULL));
	BNode<int>* value = NULL;

	for(int i = 0;i < 10;i += 1)
	{
		append(value,(rand() % 24 + 5));
		infix(value);
		std::cout << "\n";
		postfix(value);
		std::cout << "\n";
		prefix(value);
		std::cout << "\n\n";
	}

	std::cout << *detachLast(value) << "\n";

	Clear(value);
*/
	BNode<int>* tmp;
	Insert(tmp,3);
        Insert(tmp,10);
        Insert(tmp,21);
        Insert(tmp,30);
        Insert(tmp,4);
        Insert(tmp,1);
        Insert(tmp,9);
        Insert(tmp,2);
	infix(tmp);
	cout<<"\n";
	infixFunction(tmp,Print);
//	cout<<"Max: "<<MaximumValue(tmp)<<"\n";
//	cout<<"Min: "<<MinimumValue(tmp)<<"\n";
//	cout<<"Range: "<<Range(tmp)<<"\n";

	return 0;
}
