#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Node.h"
using namespace std;
using namespace ds;

class HashTable
{	Node<int>* data[28];
	int hash(int n)
	{	return n%28;}
	public:
		HashTable()
		{	for(int i=0;i<28;i+=1)
			{	data[i]=NULL;}}
		~HashTable()
		{	for(int i=0;i<28;i+=1)
			{	Clear(data[i]);}}

		void Insert(int value)
		{	int index=hash(value);
			if(data[index]==NULL)
			{	data[index]=new Node<int>(value);}
			else
			{	Node<int>* tmp=new Node<int>(value);
				tmp->SetLink(data[index]);
				data[index]=tmp;}}

		bool Search(int value)
		{	int index=hash(value);
			for(Node<int>* tmp=data[index];tmp!=NULL;tmp=tmp->GetLink())
			{	if(tmp->GetData()==value)
				{	return true;}}
			return false;}

		void Remove(int value)
		{	int index=hash(value);
			Node<int>* prev=NULL;
			Node<int>* tmp=data[index];
			while(tmp!=NULL && tmp->GetData()!=value)
			{	prev=tmp;
				tmp=tmp->GetLink();}
			if(tmp!=NULL)
			{	prev->SetLink(tmp->GetLink());
				delete tmp;
				tmp=NULL;}}

		bool IsEmpty(int value)
		{	return data[hash(value)]==NULL;}};

#endif
