//WORK IN PROGRESS
//Expected Completion: 12/21/2019 @ 11:59PM
#include <iostream>
#include <string>
#include <sstream>
#include "LinkedMap.h"
#include "LinkedList.h"
using namespace std;
using namespace ds;

void CommandPrompt()
{	LinkedMap<string,LinkedMap> root;

	LinkedList<string>* pwd;
	pwd.InsertInFront("root");

	string str;

	bool loop=true;
	while(loop)
	{	cout<<"$ ";
		cin>>str;

		if(str=="cd")
		{	getline(cin,str);

			if(str=="..")
			{	//cd to parent dir

int main()
{	CommandPrompt();

	return 0;}
