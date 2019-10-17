#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class Queue
	{
	private:
		Node<T>* front;
		Node<T>* back;
	public:
		Queue() : front(NULL), back(NULL) {}

		Queue(const Queue<T>& obj)
		{
			Node<T>* tmp = obj.front;
			
			if(tmp != NULL)
			{
				front = new Node<T>(tmp->GetData());
				back = front;
				tmp = tmp->GetLink();

				while(tmp != NULL)
				{
					back->SetLink(new Node<T>(tmp->GetData()));
					tmp = tmp->GetLink();
					back = back->GetLink();
				}
			}
		}

		Queue& operator=(const Queue<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(front);
				back = NULL;
				Node<T>* tmp = rhs.front;
			
				if(tmp != NULL)
				{	
					front = new Node<T>(tmp->GetData());
					back = front;
					tmp = tmp->GetLink();

					while(tmp != NULL)
					{
						back->SetLink(new Node<T>(tmp->GetData()));
						tmp = tmp->GetLink();
						back = back->GetLink();
					}
				}
			}

			return *this;
		}

		~Queue() 
		{
			Clear(front);
			front = NULL;
			back = NULL;
		}

		void Enqueue(const T& data)
		{
			if(front == NULL)
			{
				front = new Node<T>(data);
				back = front;
			}
			else 
			{
				back->SetLink(new Node<T>(data));
				back = back->GetLink();
			}
		}

		bool IsEmpty() const {return front == NULL;}
	
		void Dequeue() 
		{
			if(front != NULL)
			{
				Node<T>* tmp = front;
				front = front->GetLink();
				delete tmp;
				tmp = NULL;
				
				if(front == NULL)
				{
					back = NULL;
				}
			}
		}

		const T& Peek() const 
		{
			if(front != NULL)
			{
				return front->GetData();
			}
			throw "Empty Queue";
		}

		std::string ToString() const
		{
			std::stringstream out;

			if(front != NULL)
			{
				out << front->GetData();
			}
			else 
			{
				out << "";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Queue<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}	
	
#endif
