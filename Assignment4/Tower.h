#ifndef TOWER_H
#define TOWER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
using namespace std;

class Tower
{	private:
		Node<int>* top;
	public:
		Tower()
		{	top=NULL;}
		Tower(const Tower& obj)
		{	top=Copy(obj.top);}
		Tower& operator=(const Tower& rhs)
		{	if(this!=&rhs)
			{	Clear(top);
				top=Copy(rhs.top);}
			return *this;}
		~Tower()
		{	Clear(top);
			top=NULL;}

		bool IsEmpty() const
		{	return top==NULL;}

		const int& Top() const
		{	if(top!=NULL)
			{	return top->GetData();}
			throw "Empty Stack";}

		void AddDisk(int value)
		{	if(top==NULL)
			{	top=new Node<int>(value);}
			else if(value<top->GetData())
			{	Node<int>* tmp=new Node<int>(value);
				tmp->SetLink(top);
				top=tmp;}
			else
			{	throw "Invalid addition\n";}}

		int RemoveDisk()
		{	if(top==NULL)
			{	return NULL;}
			else
			{	int data=top->GetData();
				Node<int>* tmp=top;
				top=top->GetLink();
				delete tmp;
				tmp=NULL;
				return data;}}

		int Size()
		{	int count=0;
			Node<int>* tmp=top;
			while(tmp!=NULL)
			{	count+=1;
				tmp=tmp->GetLink();}
			return count;}

		string ToString() const
		{	stringstream out;
			out<<"[";
			for(Node<int>* tmp=top;tmp!=NULL;tmp=tmp->GetLink())
			{	out<<*tmp;
				if(tmp->GetLink()!=NULL)
				{	out<<",";}}
			out<<"]";
			return out.str();}

		friend ostream& operator<<(ostream& out,const Tower& obj)
		{	out<<obj.ToString();
			return out;}};

#endif
