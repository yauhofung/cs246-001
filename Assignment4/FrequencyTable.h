#ifndef FREQUENCYTABLE_H
#define FREQUENCYTABLE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Pair.h"
#include "Node.h"
using namespace std;

class FrequencyTable
{	private:
		Node<Pair<char,int> >* head;
	public:
		FrequencyTable()
		{	head=NULL;}

		FrequencyTable(const FrequencyTable<char,int>& obj)
		{	head=Copy(obj.head);}

		FrequencyTable<char,int>& operator=(const FrequencyTable<char,int>& rhs)
		{	if(this!=&rhs)
			{	Clear(head);
				head=Copy(rhs.head);}
			return *this;}

		~FrequencyTable()
		{	Clear(head);}

		void AddCharacter(const char& key)
		{	if(head==NULL)
			{	head=new Node<Pair<char,int> >(Pair<char,int>(key,1));}
			else
			{	Node<Pair<char,int>>* tmp=head;
				while(tmp->GetLink()!=NULL && tmp->GetData().GetKey()!=key)
				{	tmp=tmp->GetLink();}
				if(tmp->GetLink()==NULL)
				{	tmp->SetLink(new Node<Pair<char,int> >(Pair<char,int>(key,value)));}
				else
				{	tmp->GetData().GetData()+=1;}}}

		string ToString() const
		{	stringstream out;
			out<<"[";
			for(Node<Pair<char,int>>* tmp=head;tmp!=NULL;tmp=tmp->GetLink())
			{	out<<tmp->GetData();
				if(tmp->GetLink()!=NULL)
				{	out<<",";}}
			out<<"]";
			return out.str();}

		friend ostream& operator<<(ostream& out,const FrequencyTable<char,int>& obj)
		{	out<<obj.ToString();
			return out;}};

#endif
