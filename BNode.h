#ifndef BNODE_H
#define BNODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class BNode
	{
	private:
		T data;
		BNode<T>* left;
		BNode<T>* right;

		BNode(const BNode<T>& obj);
		BNode& operator=(const BNode<T>& rhs);
	public:
		BNode() : BNode(T(),NULL,NULL) {}

		BNode(const T& data) : BNode(data,NULL,NULL) {}

		BNode(const T& data,BNode<T>* left,BNode<T>* right) : data(data), left(left), right(right) {}

		~BNode() {}
	
		T& GetData() {return data;}

		const T& GetData() const {return data;}

		BNode<T>*& GetLeft() {return left;}

		const BNode<T>* GetLeft() const {return left;}

		BNode<T>*& GetRight() {return right;}

		const BNode<T>* GetRight() const {return right;}

		void SetData(const T& data) {this->data = data;}

		void SetLeft(BNode<T>* left) {this->left = left;}

		void SetRight(BNode<T>* right) {this->right = right;}

		bool IsLeaf() const {return ((left == NULL) && (right == NULL));}

		std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const BNode<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};

	template <class T>
	BNode<T>* Copy(const BNode<T>* root)
	{
		if(root == NULL)
		{
			return NULL;
		}

		BNode<T> *tmp = new BNode<T>(root->GetData());
		tmp->SetLeft(Copy(root->GetLeft()));
		tmp->SetRight(Copy(root->GetRight()));
		return tmp;
	}

	template <class T>
	void Clear(BNode<T>*& root)
	{
		if(root != NULL)
		{
			Clear(root->GetLeft());
			Clear(root->GetRight());
			delete root;
			root = NULL;
		}
	}
}
		
#endif
