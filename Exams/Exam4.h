#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

#include <iostream>
#include <string>
#include <sstream>
#include "BBNode.h"
using namespace ds;
using namespace std;

template <class T>
class BinarySearchTree
{	private:
		BBNode<T>* root;
	public:
		BinarySearchTree()
		{	root=NULL;}
		BinarySearchTree(const BinarySearchTree& obj)
		{	root=Copy(obj.root);}
		BinarySearchTree& operator=(const BinarySearchTree& rhs)
		{	if(this!=&rhs)
			{	Clear(root);
				root=Copy(rhs.root);}
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

		void ReplaceWithSuccessor(BBNode<T>*& predecessor,BBNode<T>*& successor) //NOTE: predecessor must not be a leaf
		{	if(predecessor->GetRight()!=NULL)
			{	successor=predecessor->GetRight();
				while(successor->GetLeft()!=NULL)
				{	successor=successor->GetLeft();}
				predecessor->SetData(successor->GetData());
				if(successor->IsLeaf())
				{	successor->GetP()->SetLeft(NULL);
					Clear(successor);}
				else
				{	predecessor=successor;
					ReplaceWithSuccessor(predecessor,successor);}}
			else //mirrored version of the other condition
			{	successor=predecessor->GetLeft();
				while(successor->GetRight()!=NULL)
				{	successor=successor->GetRight();}
                                predecessor->SetData(successor->GetData());
                                if(successor->IsLeaf())
                                {       successor->GetP()->SetRight(NULL);
                                        Clear(successor);}
                                else
                                {       predecessor=successor;
                                        ReplaceWithSuccessor(predecessor,successor);}}}

		void Remove(const T& data)
		{	if(Search(data))
			{	BBNode<T>* target=root;
				bool isGreater;
				while(target->GetData()!=data)
				{	if(data>target->GetData())
                                        {       target=target->GetRight();
						isGreater=true;}
                                        else
                                        {       target=target->GetLeft();
						isGreater=false;}}
				if(target->IsLeaf())
				{	if(isGreater)
					{	target->GetP()->SetRight(NULL);}
					else
					{	target->GetP()->SetLeft(NULL);}
					Clear(target);}
				else
				{	BBNode<T>* successor=target;
					ReplaceWithSuccessor(target,successor);}}}

		int Height(BBNode<T>* leaf)
		{	BBNode<T>* tmp=leaf;
			int h=0;
			while(tmp!=root)
			{	tmp=tmp->GetP();
				h+=1;}
			return h;}}

		void MaxHeightSearch(BBNode<T>* tmp,int& height)
		{	if(tmp!=NULL)
			{	if(tmp->IsLeaf())
				{	if(Height(tmp)>height)
					{	height=Height(tmp);}}
				else
				{	MaxHeightSearch(tmp->GetLeft(),height);
					MaxHeightSearch(tmp->GetRight(),height);}}}

		const int Depth()
		{	if(IsEmpty||root->IsLeaf())
			{	return 0;}
			else
			{	int height=1;
				MaxHeightSearch(root,height);
				return height;}}

		void Counter(BBNode<T>* tmp,int& count)
		{	if(tmp!=NULL)
			{	count+=1;
				Counter(tmp->GetLeft(),count);
				Counter(tmp->GetRight(),count);}}

		const int Count()
		{	if(root==NULL)
			{	return 0;}
			else if(root->IsLeaf())
			{	return 1;}
			else
			{	BBNode<T>* tmp=root;
				int count=0;
				return Counter(tmp,count);}}

		void Postfix(BBNode<T>* tmp,stringstream& out)
		{	if(tmp!=NULL)
			{	Postfix(tmp->GetLeft(),out);
				Postfix(tmp->GetRight(),out);
				out<<tmp->GetData()<<" ";}}

		string ToString() const
		{	stringstream out;
			if(!IsEmpty())
			{	BBNode<T>* tmp=root;
				Postfix(tmp,out);}
			return out.str();}

		friend ostream& operator<<(ostream& out,const BinarySearchTree<T>& obj)
		{	out<<obj.ToString();
			return out;}};

#endif
