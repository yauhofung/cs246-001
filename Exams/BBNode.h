#ifndef BBNODE_H
#define BBNODE_H

#include <iostream>
#include <string>
#include <sstream>

namespace ds
{
	template <class T>
	class BBNode
	{
	private:
		T data;
		BBNode<T>* p;
		BBNode<T>* left;
		BBNode<T>* right;

		BBNode(const BBNode<T>& obj);
		BBNode& operator=(const BBNode<T>& rhs);
	public:
		BBNode() : BBNode(T(),NULL,NULL,NULL) {}

		BBNode(const T& data) : BBNode(data,NULL,NULL,NULL) {}

		BBNode(const T& data,BBNode<T>* p) : BBNode(data,p,NULL,NULL) {}

		BBNode(const T& data,BBNode<T>* p,BBNode<T>* left,BBNode<T>* right) : data(data), p(p), left(left), right(right) {}

		~BBNode() {}
	
		T& GetData() {return data;}

		const T& GetData() const {return data;}

		BBNode<T>*& GetP() {return p;}

		const BBNode<T>*& GetP() const {return p;}

		BBNode<T>*& GetLeft() {return left;}

		const BBNode<T>* GetLeft() const {return left;}

		BBNode<T>*& GetRight() {return right;}

		const BBNode<T>* GetRight() const {return right;}

		void SetData(const T& data) {this->data = data;}

		void SetP(BBNode<T>* p) {this->p = p;}

		void SetLeft(BBNode<T>* left) {this->left = left;}

		void SetRight(BBNode<T>* right) {this->right = right;}

		bool IsLeaf() const {return ((left == NULL) && (right == NULL));}

		std::string ToString() const
		{
			std::stringstream out;
			out << data;
			return out.str();
		}

		friend std::ostream& operator<<(std::ostream& out,const BBNode<T>& obj)
		{
			out << obj.ToString();
			return out;
		}
	};


	template <class T>
	BBNode<T>* Copy(const BBNode<T>* root,BBNode<T>* p)
	{
		if(root == NULL)
		{
			return NULL;
		}

		BBNode<T> *tmp = new BBNode<T>(root->GetData(),p);
		tmp->SetLeft(Copy(root->GetLeft(),tmp));
		tmp->SetRight(Copy(root->GetRight(),tmp));
		return tmp;
	}

	/*Call this version of Copy()*/
	template <class T>
	BBNode<T>* Copy(const BBNode<T>* root)
	{
		if(root == NULL)
		{
			return NULL;
		}
		return Copy(root,NULL);
	}

	template <class T>
	void Clear(BBNode<T>*& root)
	{
		if(root != NULL)
		{
			BBNode<T>* l = root->GetLeft();
			BBNode<T>* r = root->GetRight();
			Clear(l);
			Clear(r);
			
			if(root != NULL)
			{
				delete root; 
				root = NULL;
			}
		}
	}
}
		
#endif
