#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class Node
	{
	private:
		T data;
		Node<T>* link;

		Node(const Node<T>& obj);
		Node& operator=(const Node<T>& rhs);
	public:
		Node() : Node(T(),NULL) {}

		Node(const T& data) : Node(data,NULL) {}

		Node(const T& data,Node<T>* link) : data(data), link(link) {}

		~Node() {}
	
		T& GetData() {return data;}

		const T& GetData() const {return data;}

		Node<T>* GetLink() {return link;}

		const Node<T>* GetLink() const {return link;}

		void SetData(const T& data) {this->data = data;}

		void SetLink(Node<T>* link) {this->link = link;}

		std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const Node<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};
}
		
#endif
