#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Node.h"
using namespace ds;
using namespace std;

template<class T>
void append(Node<T>*& root,const T& data)
{   if(root==NULL)
    {   root=new Node<T>(data);}
    else
    {   Node<T>* tmp=root;
        while(tmp->GetLink()!=NULL)
        {   tmp=tmp->GetLink();}
        tmp->SetLink(new Node<T>(data));}}

template<class T>
void traverse(Node<T>* root)
{   cout<<"[";
    Node<T>* tmp=root;
    while(tmp!=NULL)
    {   cout<<tmp->GetData();
        if(tmp->GetLink()!=NULL)
        {   cout<<",";}
        tmp=tmp->GetLink();}
    cout<<"]";}

template<class T>
void Clear(Node<T>*& root)
{   Node<T>* tmp;
    while(root!=NULL)
    {   tmp=root;
        root=root->GetLink();
        delete tmp;
        tmp=NULL;}}

int main()
{   srand(time(NULL));
    Node<int>* root=NULL;
    int n=10;
    for(int i=0;i<n;i+=1)
    {   append(root,rand()%24+5);
        traverse(root);
        cout<<endl;}
    return 0;}
