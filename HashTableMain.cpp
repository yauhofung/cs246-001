#include <iostream>
#include <ctime>
#include <cstdlib>
#include "HashTable.h"
using namespace std;

void RandomValues(int a[],int n,int l,int h)
{	int mx=(l<h)?(h):(l);
	int mn=l+h-mx;
	for(int i=0;i<n;i+=1)
	{	a[i]=mn+rand()%(mx-mn+1);}}

bool SumMultiple(int a[],int n)
{	HashTable tbl;
	for(int i=0;i<n;i+=1)
	{	if(!tbl.IsEmpty(28-a[i]%28))
		{	return true;}
		tbl.Insert(a[i]);}
	return false;}

void Display(int a[],int n)
{	for(int i=0;i<n;i+=1)
	{	cout<<a[i]<<" ";}
	cout<<"\n";}

int main()
{	srand(time(NULL));
	int SIZE=10;
	int a[SIZE];
	RandomValues(a,SIZE,1,1000);
	Display(a,SIZE);
	cout<<"Sum Multiple of 28: ";
	if(SumMultiple(a,SIZE))
	{	cout<<"True\n";}
	else
	{	cout<<"False\n";}
	
	return 0;}
