#include <iostream>
#include "Node.h"
#include "LinkedList2.h"
using namespace std;
using namespace ds;

bool isPalindrome(const LinkedList<char>& list)
{   LinkedList<char> clist=list;
    int length=clist.Length()/2;
    for(int i=1;i<=length;i+=1)
    {   cout<<clist[0]<<clist[clist.Length()-1]<<"\n";
        if(clist[0]==clist[clist.Length()-1])
        {   clist.RemoveFromBack();
            clist.RemoveFromFront();}
        else
        {   return false;}}
    return true;}

int main()
{   LinkedList<char> palin;
    palin.InsertInBack('r');
    palin.InsertInBack('a');
    palin.InsertInBack('c');
    palin.InsertInBack('e');
    palin.InsertInBack('c');
    palin.InsertInBack('a');
    palin.InsertInBack('r');
    cout<<palin.ToString()<<"\n";
    if(isPalindrome(palin))
    {   cout<<"This is a palindrome.\n";}
    else
    {   cout<<"This isn't a palindrome.\n";}    
    return 0;}