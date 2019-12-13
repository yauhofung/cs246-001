#include <iostream>
#include "LinkedList.h"
using namespace ds;
using namespace std;

int main()
{	LinkedList<int> list;
	for(int i=1;i<=100;i+=1)
	{	list.InsertInBack(i);}

	bool isGreater;
	while(list.Length()!=1)
	{	cout<<"Is your number greater than "<<(list[0]+list[list.Length()-1])/2<<"? (true/false) ";
		cin>>isGreater;

		if(isGreater)
		{	for(int i=0;i<list.Length()/2;i+=1)
			{	list.RemoveFromFront();}}

		else
		{	for(int i=0;i<list.Length()/2;i+=1)
			{	list.RemoveFromBack();}}}

	cout<<"Your number is: "<<list[0]<<"\n";

	return 0;}
