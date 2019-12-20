//WORK IN PROGRESS
#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include "BBNode.h"
using namespace ds;

template <class T>
class BinarySearchTree
{	private:
		BBNode<T>* root;
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
		{	if(IsEmpty())
			{	root=new BBNode<T>(data);}
			else
			{	BBNode<T>* parent,child=root;
				bool isGreater;
				while(child!=NULL)
				{	parent=child;
					if(data>parent->GetData())
					{	child=parent->GetRight();
						isGreater=true;}
					else
					{	child=parent->GetLeft();
						isGreater=false;}}
				child=new BBNode<T>(data,parent);
				if(isGreater)
				{	parent->SetRight(child);}
				else
				{	parent->SetLeft(child);}}}

		const bool Search(const T& data)
		{	if(IsEmpty)
			{	return false;}
			else
			{	BBNode<T>* tmp=root;
				while(tmp!=NULL)
				{	if(tmp->GetData()==data)
					{	return true;}
					else if(data>tmp->GetData())
					{	tmp=tmp->GetRight();}
					else
					{	tmp=tmp->GetLeft();}}
				return false;}}

		void Remove(const T& data)
		{	if(Search(data))
			{	BBNode<T>* target=root;
				while(target->GetData()!=data)
				{	if(data>target->GetData())
                                        {       target=target->GetRight();}
                                        else
                                        {       target=target->GetLeft();}}
				if(target->IsLeaf())
				{	
