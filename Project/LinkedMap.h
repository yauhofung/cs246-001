#ifndef LINKEDMAP_H
#define LINKEDMAP_H

#include <iostream>
#include <string>
#include <sstream>
#include "Pair.h"
#include "Node.h"

namespace ds
{
	template <class K,class V>
	class LinkedMap
	{
	private:
		Node<Pair<K,V> >* head;
		int size;
	public:
	
		LinkedMap() : size(0)
		{	
			head = NULL;
		}
	
		LinkedMap(const LinkedMap<K,V>& obj)
		{
			size = obj.size;
			head = Copy(obj.head);
		}

		LinkedMap<K,V>& operator=(const LinkedMap<K,V>& rhs)
		{
			if(this != &rhs)
			{
				size = rhs.size;
				Clear(head);
				head = Copy(rhs.head);
			}

			return *this;
		}

		~LinkedMap() {Clear(head);}

		int Length() const {return size;}

		bool IsEmpty() const {return (size == 0);}

		V& operator[](const K& key) 
		{
			for(Node<Pair<K,V> >* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(key == tmp->GetData().GetKey())
				{
					return tmp->GetData().GetValue();
				}
			}
			throw "Invalid Key";
		}

		const V& operator[](const K& key) const 
		{
			for(Node<Pair<K,V> >* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(key == tmp->GetData().GetKey())
				{
					return tmp->GetData().GetValue();
				}
			}
			throw "Invalid Key";
		}

		V& Get(const K& key) 
		{
			for(Node<Pair<K,V> >* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(key == tmp->GetData().GetKey())
				{
					return tmp->GetData().GetValue();
				}
			}
			throw "Invalid Key";
		}

		const V& Get(const K& key) const 
		{
			for(Node<Pair<K,V> >* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(key == tmp->GetData().GetKey())
				{
					return tmp->GetData().GetValue();
				}
			}
			throw "Invalid Key";
		}

		bool HasKey(const K& key)
		{
			for(Node<Pair<K,V> >* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				if(key == tmp->GetData().GetKey())
				{
					return true;
				}
			}
			return false;
		}

		void Put(const K& key,const V& value)
		{
			if(head == NULL)
			{
				head = new Node<Pair<K,V> >(Pair<K,V>(key,value));
			}
			else
			{
				Node<Pair<K,V> >* tmp = head;

				while(tmp->GetLink() != NULL && tmp->GetData().GetKey() != key)
				{
					tmp = tmp->GetLink();
				}
			
				if(tmp->GetLink() == NULL)
				{
						tmp->SetLink(new Node<Pair<K,V> >(Pair<K,V>(key,value)));
					size += 1;
				}
			}
		}

		void Remove(const K& key)
		{
			if(size > 0)
			{
				Node<Pair<K,V> >* tmp = head;
				
				while(tmp->GetLink() != NULL && tmp->GetLink()->GetData().GetKey() != key)
				{
					tmp = tmp->GetLink();
				}
				
				if(tmp->GetLink() != NULL)
				{
					Node<Pair<K,V> >* ctmp = tmp->GetLink();
					tmp->SetLink(ctmp->GetLink());
					delete ctmp;
					ctmp = NULL;
					size -= 1;
				}
			}
		}

		std::string ToString() const
		{
			std::stringstream out;

			for(Node<Pair<K,V> >* tmp = head;tmp != NULL;tmp = tmp->GetLink())
			{
				out << tmp->GetData().GetKey();

				if(tmp->GetLink() != NULL)
				{
					out << "  ";
				}
			}

			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const LinkedMap<K,V>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
