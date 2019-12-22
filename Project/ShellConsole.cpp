//This program uses a linked list and nested linked maps to simulate the file system in a Linux environment.
//Commands: cd, ls, rm, touch, mkdir

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedMap.h"
#include "LinkedList.h"
using namespace std;
using namespace ds;

template <class L>
void CommandPrompt() //initializes Linux shell
{	LinkedMap<string,L> root; //root directory

	LinkedMap<string,L>* pwd=&root; //points at present working directory

	LinkedList<LinkedMap<string,L>*> path; //keeps track of full path to pwd
	path.InsertInFront(pwd);

	LinkedMap<string,L>* tmp; //points at created LinkedMap (touch/mkdir)

	string cmd; //reads user input

	bool loop=true;
	cout<<"NOTE: Press Ctrl+c to terminate the program.\n";
	while(loop) //ensures program does not terminate after each command
	{	cout<<"$ ";
		cin>>cmd;

		if(cmd=="cd") //changes directory
		{	getline(cin,cmd);

			if(cmd=="..") //changes to parent directory
			{	if(path.Length()==1) //checks pwd for root
				{	throw "Cannot change directory to root's parent";}
				else
				{	path.RemoveFromBack();
					pwd=path[path.Length()-1];}}
			else
			{	if(pwd->HasKey(cmd)) //verifies specified directory
				{	pwd=&(pwd->Get(cmd));
					path.InsertInBack(pwd);}
				else
				{	throw "Specified directory does not exist";}}}

		else if(cmd=="ls") //lists files in pwd
		{	cout<<*pwd<<"\n";} //NOTE: modified LinkedMap.h's ToString() to return only the strings (filenames) in pwd

		else if(cmd=="rm") //removes files and empty directories
		{	while(cin>>cmd) //checks each argument
			{	if(pwd->HasKey(cmd)) //searches for specified directory
				{	if(pwd->Get(cmd).IsEmpty()) //ensures specified directory is empty
					{	pwd->Remove(cmd);}
					else
					{	throw "Cannot remove nonempty directory";}}
				else
				{	throw "Specified directory does not exist";}}}

		else if(cmd=="touch"||cmd=="mkdir") //creates files and/or directories
		{	while(cin>>cmd) //checks each argument
			{	if(pwd->HasKey(cmd)) //searches for specified directory
				{	throw "Cannot recreate existing directory";}
				else
				{	tmp=new LinkedMap<string,L>();
					pwd->Put(cmd,*tmp);}}}

		else
		{	throw "Invalid command";}}}

int main()
{	//CommandPrompt(); //ERROR: compiler fails to call function

	return 0;}
