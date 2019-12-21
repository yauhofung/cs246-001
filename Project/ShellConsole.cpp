//WORK IN PROGRESS
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedMap.h"
using namespace std;
using namespace ds;

void CommandPrompt()
{	LinkedMap<string,LinkedMap> root;
	LinkedMap<string,LinkedMap>* pwd=root;
	string str;

	bool loop=true;
	while(loop)
	{	cout<<"$ ";
		cin>>str;

		if(str=="cd")
		{	getline(cin,str);

			else if(str=="..")
			{	//cd to parent dir

int main()
{	CommandPrompt();

	return 0;}
