#ifndef LINKEDLIST2_H
#define LINKEDLIST2_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class LinkedList
	{
	private:
		Node<T>* head;
		int size;
	public:
		LinkedList() : head(NULL), size(0) {}

		LinkedList(const LinkedList<T>& obj)
		{
			size = obj.size;
            head=Copy(obj.head);
		}

		LinkedList<T>& operator=(const LinkedList<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				Clear(head);
				head=Copy(rhs.head);
			}
			return *this;			
		}

		~LinkedList() 
		{
			Clear(head);
		}

		void InsertInFront(const T& data)
		{
			if(head == NULL)
			{
				head = new Node<T>(data);
			}
			else 
			{
				Node<T>* tmp = new Node<T>(data);
				tmp->SetLink(head);
				head = tmp;
			}
			size += 1;
		}

		void InsertInBack(const T& data)
		{
			if(head == NULL)
			{
				head = new Node<T>(data);
			}
			else
			{
				Node<T>* tmp=head;
				while(tmp->GetLink()!=NULL)
                {   tmp=tmp->GetLink();}
                tmp->SetLink(new Node<T>(data));
			}
			size += 1;
		}

        void InsertBefore(const T& value,const T& data)
        {   if(head!=NULL)
            {   if(head->GetData()==value)
                {   InsertInFront(data);}
                else
                {   Node<T>* tmp=head;
                    while(tmp->GetLink!=NULL&&tmp->GetLink()->GetData()!=value)
                    {   tmp=tmp->GetLink();}
                    if(tmp->GetLink()!=NULL)
                    {   Node<T>* nwdata=new Node<T>(data);
                        nwdata->SetLink(tmp->GetLink());
                        tmp->SetLink(nwdata);
                        size+=1;}}}}

        void InsertAfter(const T& value,const T& data)
        {   if(head!=NULL)
            {   Node<T>* tmp=head;
                while(tmp!=NULL&&tmp->GetData()!=value)
                {   tmp=tmp->GetLink();}
                if(tmp!=NULL)
                {   Node<T>* nwdata=new Node<T>(data);
                    nwdata->SetLink(tmp->GetLink());
                    tmp->SetLink(nwdata);
                    size+=1;}}}

		void RemoveFromFront() 
		{
			if(head!=NULL)
			{
				Node<T>*tmp=head;
				head=head->GetLink();
				delete tmp;
				tmp=NULL;
				size -= 1;
			}
		}

		void RemoveFromBack()
		{
			if(head!=NULL)
			{
				if(head->GetLink()==NULL)
				{
					delete head;
					head=NULL;
				}
				else
				{
					Node<T>*tmp=head;
					
					while(tmp->GetLink()->GetLink()!=NULL)
					{
						tmp = tmp->GetLink();
					}
					Node<T>*oldData=tmp->GetLink();
					tmp->SetLink(NULL);
					delete oldData;
					oldData=NULL;
				}
				
				size -= 1;
			}
		}
		void Remove(const T& value)
		{	if(head!=NULL)
			{	if(head->GetData()==value)
				{	RemoveFromFront();}
				else
				{	Node<T>*tmp=head;
					while(tmp->GetLink()!=NULL&&tmp->GetLink()->GetData()!=value)
					{	tmp=tmp->GetLink();}
					if(tmp->GetLink()!=NULL)
					{	Node<T>*oldData=tmp->GetLink();
						tmp->SetLink(oldData->GetLink());
						oldData->SetLink(NULL);
						delete oldData;
						oldData=NULL;
						size-=1;}}}}

		bool IsEmpty() const {return head == NULL;}

		int Length() const
		{	return size;}

		T& operator[](int index)
		{	if(index>=0&&index<size)
			{	Node<T>*tmp=head;
				for(int i=0;i<index;i+=1)
				{	tmp=tmp->GetLink();}
				return tmp->GetData();}
			throw "Out of Bound";}

		const T& operator[](int index) const
		{	if(index>=0&&index<size)
			{	Node<T>*tmp=head;
				for(int i=0;i<index;i+=1)
				{	tmp=tmp->GetLink();}
				return tmp->GetData();}
			throw "Out of Bound";}

		std::string ToString() const
		{
			std::stringstream out;

			out << "[";

			for(Node<T> *tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				out << *tmp;
				
				if(tmp->GetLink() != NULL)
				{
					out << ",";
				}
			}	
			
			out << "]";

			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const LinkedList<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}	
	
#endif