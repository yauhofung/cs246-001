#ifndef SPOOLER_H
#define SPOOLER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Pair.h"
using namespace std;

class Spooler
{	private:
		Node<Pair<string,int> >* front;
		Node<Pair<string,int> >* back;
	public:
		Spooler()
		{	front=NULL;
			back=NULL;}
		Spooler(const Spooler& obj)
		{	Node<Pair<string,int> >* tmp=obj.front;
			if(tmp!=NULL)
			{	front=new Node<Pair<string,int> >(tmp->GetData());
				back=front;
				tmp=tmp->GetLink();
				while(tmp->NULL)
				{	back->SetLink(new Node<Pair<string,int> >(tmp->GetData()));
					tmp=tmp->GetLink();
					back=back->GetLink();}}}
		Spooler& operator=(const Spooler& rhs)
		{	if(this!=&rhs)
			{	Clear(front);
				back=NULL;
				Node<Pair<string,int> >* tmp=rhs.front;
				if(tmp!=NULL)
				{	front=new Node<Pair<string,int> >(tmp->GetData());
					back=front;
					tmp=tmp->GetLink();
					while(tmp!=NULL)
					{	back->SetLink(new Node<Pair<string,int> >(tmp->GetData()));
						tmp=tmp->GetLink();
						back=back->GetLink();}}}
			return *this;}
		~Spooler()
		{	Clear(front);
			front=NULL;
			back=NULL;}

		bool IsEmpty()
		{	return front==NULL;}

		void AddJob(Pair<string,int> job)
		{	if(front==NULL)
			{	front=new Node<Pair<string,int> >(job);
				back=front;}
			else
			{	back->SetLink(new Node<Pair<string,int> >(job));
				back=back->GetLink();}}

		Pair<string,int> ExecuteJob()
		{	if(front==NULL)
			{	return NULL;}
			else
			{	Pair<string,int> job=front->GetData();
				Node<Pair<string,int> >* tmp=front;
				front=front->GetLink();
				delete tmp;
				tmp=NULL;
				if(front==NULL)
				{	back=NULL;}
				return job;}}

		string Query()
		{	stringstream out;
			out<<"[";
			for(Node<Pair<string,int> >*tmp=front;tmp!=NULL;tmp=tmp->GetLink())
			{	out<<tmp->GetData();
				if(tmp->GetLink()!=NULL)
				{	out<<",";}}
			out<<"]";
			return out.str();}

		friend ostream& operator<<(ostream& out,const Spooler& obj)
		{	out<<obj.ToString();
			return out;}};

#endif
