#include "Vector.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void Random(Vector<int>& vec,int n)
{   vec.Clear();
    for(int i=0;i<n;i+=1)
    {   vec.Insert(rand()%100+1);}}
void Reverse(Vector<int>& vec)
{   int tmp;
    int n=vec.Size();
    for(int i=0;i<n/2;i+=1)
    {   tmp=vec[i];
        vec[i]=vec[(n-1)-i];
        vec[(n-1)-i]=tmp;}}

int main()
{   srand(time(NULL));
/*    cout<<int()<<endl;
    cout<<float()<<endl;
    cout<<double()<<endl;
    cout<<char()<<endl;
    cout<<bool()<<endl;*/
    Vector<int> t;
    Random(t,10);
    cout<<t<<endl;
    Reverse(t);
    cout<<t<<endl;
    return 0;}
