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
void infix(BNode<T>* root,ofstream& WriteFile)
{	if(root!=NULL)
	{	infix(root->GetLeft(),WriteFile);
		WriteFile<<root->GetData();
		infix(root->GetRight(),WriteFile);}}

template <typename T>
void prefix(BNode<T>* root,ofstream& WriteFile)
{	if(root!=NULL)
	{	WriteFile<<root->GetData();
		prefix(root->GetLeft(),WriteFile);
		prefix(root->GetRight(),WriteFile);}}

template <typename T>
void postfix(BNode<T>* root,ofstream& WriteFile)
{	if(root!=NULL)
	{	postfix(root->GetLeft(),WriteFile);
		postfix(root->GetRight(),WriteFile);
		WriteFile<<root->GetData();}}

int main()
{	string path;
	cout<<"Enter a file path to the binary tree character keys: ";
	getline(cin,path);
	ifstream ReadFile(path);

	BNode<char>* root;
	char c;
	while(ReadFile.get(c))
	{	append(root,c);}

	ofstream WriteFile1("WriteFile1.txt");
	infix(root,WriteFile1);
	WriteFile1.close();

	ofstream WriteFile2("WriteFile2.txt");
	prefix(root,WriteFile2);
	WriteFile2.close();

	ofstream WriteFile3("WriteFile3.txt");
	postfix(root,WriteFile3);
	WriteFile3.close();

	return 0;}
