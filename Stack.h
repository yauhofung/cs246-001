#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class Stack
	{
	private:
		Node<T>* top;
	public:
		Stack() : top(NULL) {}

		Stack(const Stack<T>& obj)
		{
			top = Copy(obj.top);
		}

		Stack<T>& operator=(const Stack<T>& rhs)
		{
			if(this != &rhs)
			{
				Clear(top);
				top = Copy(rhs.top);
			}

			return *this;			
		}

		~Stack() 
		{
			Clear(top);
			top = NULL;
		}

		void Push(const T& data)
		{
			if(top == NULL)
			{
				top = new Node<T>(data);
			}
			else 
			{
				Node<T> *tmp = new Node<T>(data);
				tmp->SetLink(top);
				top = tmp;
			}
		}

		bool IsEmpty() const {return top == NULL;}
	
		void Pop() 
		{
			if(top != NULL)
			{
				Node<T>* tmp = top;
				top = top->GetLink();
				delete tmp;
				tmp = NULL;
			}
		}

		const T& Top() const 
		{
			if(top != NULL)
			{
				return top->GetData();
			}
			throw "Empty Stack";
		}

		std::string ToString() const
		{
			std::stringstream out;

			if(top != NULL)
			{
				out << top->GetData();
			}
			else 
			{
				out << "";
			}
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Stack<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}	
	
#endif
