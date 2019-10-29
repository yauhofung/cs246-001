#include <iostream>
#include "LinkedList2.h"
using namespace std;

int Sum(int data[]);
{	int sum=0;
	for(int i=0;i<size;i+=1)
	{	sum+=data[i];}
	return sum;}

int Sum(Node<int>*root)
{	int sum=0;
	for(Node<T>*tmp=root;tmp!=NULL;tmp=tmp->GetLink())
	{	sum+=tmp->GetData();}
	return sum;}

int Sum(DNode<int>*root)
{	int sum=0;
	for(DNode<T>*tmp=root;tmp!=NULL;tmp=tmp->GetNext())
	{	sum+=tmp->GetData();}
	return sum;}
