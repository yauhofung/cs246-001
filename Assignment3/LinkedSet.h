#ifndef LINKEDSET_H
#define LINKEDSET_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"

namespace ds
{
	template <class T>
	class LinkedSet
	{
	private:
		Node<T>* head;
		int size;
	public:
		LinkedSet() : size(0), head(NULL) {}

		LinkedSet(const LinkedSet<T>& obj)
		{
			size = obj.size;
			head = Copy(obj.head);
		}

		LinkedSet& operator=(const LinkedSet<T>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				Clear(head);
				head = Copy(rhs.head);
			}

			return *this;	
		}

		~LinkedSet() 
		{
			Clear(head);
			head = NULL;
		}

		bool Contains(const T& value) const 
		{
			for(Node<T>* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(value == tmp->GetData())
				{
					return true;
				}
			}
			return false;
		}

		void Add(const T& value) 
		{
			if(!Contains(value))
			{
				Node<T>* tmp = new Node<T>(value);
				tmp->SetLink(head);
				head = tmp;
				size += 1;
			}
		}

		void Remove(const T& value) 
		{
			if(head != NULL)
			{
				if(head->GetData() == value)
				{
					Node<T>* tmp = head;
					head = head->GetLink();
					delete tmp;
					tmp = NULL;
					size -= 1;
				}
				else
				{
					Node<T>* tmp = head;

					while(tmp->GetLink() != NULL && tmp->GetLink()->GetData() != value)
					{
						tmp = tmp->GetLink();
					}

					if(tmp->GetLink() != NULL)
					{
						Node<T>* oldItem = tmp->GetLink();
						tmp->SetLink(oldItem->GetLink());
						delete oldItem;
						oldItem = NULL;
						size -= 1;
					}
				}
			}
		}	

		bool IsEmpty() const {return (head == NULL);}

		int Cardinality() const {return size;}

		friend LinkedSet<T> Intersection(const LinkedSet<T>& A,const LinkedSet<T>& B)
		{
			LinkedSet<T> R;

			if(!A.IsEmpty() && !B.IsEmpty())
			{
				for(Node<T>* tmp = A.head;tmp != NULL;tmp = tmp->GetLink())
				{
					if(B.Contains(tmp->GetData()))
					{
						R.Add(tmp->GetData());
					}
				}
			}
			return R;
		}

		friend LinkedSet<T> Union(const LinkedSet<T>& A,const LinkedSet<T>& B)
		{
			LinkedSet<T> R;
			int m = A.Cardinality(), n = B.Cardinality();

			if(m > n)
			{
				R = A;
				
				for(Node<T>* tmp = B.head;tmp != NULL;tmp = tmp->GetLink())
				{
					if(!A.Contains(tmp->GetData()))
					{
						R.Add(tmp->GetData());
					}
				}
			}
			else
			{
				R = B;
				
				for(Node<T>* tmp = A.head;tmp != NULL;tmp = tmp->GetLink())
				{
					if(!B.Contains(tmp->GetData()))
					{
						R.Add(tmp->GetData());
					}
				}
			}
			return R;
		}
	
		friend LinkedSet<T> Difference(const LinkedSet<T>& A,const LinkedSet<T>& B)
		{
			LinkedSet<T> R;

			if(!A.IsEmpty())
			{
				R = A;

				for(Node<T>* tmp = B.head;tmp != NULL;tmp = tmp->GetLink())
				{
					if(A.Contains(tmp->GetData()))
					{
						R.Remove(tmp->GetData());
					}
				}
			}
			return R;
		} 
 
		friend bool Subset(const LinkedSet<T>& A,const LinkedSet<T>& B)
		{
			if(A.Cardinality() > B.Cardinality())
			{
				return false;
			}
			else
			{
				for(Node<T>* tmp = A.head;tmp != NULL;tmp = tmp->GetLink())
				{
					if(!B.Contains(tmp->GetData()))
					{
						return false;
					}
				}
				return true;
			}
		}

		std::string ToString() const
		{
			std::stringstream out;
			out << "{";

			for(Node<T>* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				out << tmp->GetData();
				
				if(tmp->GetLink() != NULL)
				{
					out << ",";
				}
			}
			out << "}";
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const LinkedSet<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
