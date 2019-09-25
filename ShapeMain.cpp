#include <iostream>
#include <string>
#include "Shape.h"
using namespace std;

template<typename T>
const T& Max(const T& x,const T& y)
{   if(x>y)
    {   return x;}
    else
    {   return y;}}

template<typename T>
T& Max(T& x,T& y)
{   if(x>y)
    {   return x;}
    else
    {   return y;}}

template<typename E>
void EchoX(const E& value,int x)
{   for(int i=0;i<x;i+=1)
    {   cout<<value<<endl;}}

int main()
{   int x,y;
    cout<<Max(3,4)<<endl;
    cout<<Max('a','A')<<endl;
    cout<<Max(4.423,21.32)<<endl;
    cout<<Max("hello","world")<<endl;
    
    cin>>x;
    cin>>y;
    
    cout<<Max(x,y)<<endl;
    cout<<Max<float>(2.322,1.12)<<endl;

    EchoX("Hello",10);
    cout<<endl;
    EchoX(Rectangle(),2);
    return 0;}
