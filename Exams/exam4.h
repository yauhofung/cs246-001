#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BBNode.h"

template <class T>
class BinarySearchTree
{	private:
		T* root;
	public:
		BinarySearchTree()
		{	root=NULL;}
		BinarySearchTree(const BinarySearchTree& obj)
		{	root->Copy(obj.root);}
		BinarySearchTree& operator=(const BinarySearchTree& rhs)
		{	if(this!=&rhs)
			{	Clear(rhs.root);
				root->Copy(rhs.root);}
			return *this;}
		~BinarySearchTree()
		{	Clear(root);}

		bool IsEmpty()
		{	return root==NULL;}

		void Insert(const T& data)
		{	
