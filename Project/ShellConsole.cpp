//This program uses a linked list and nested linked maps to simulate the file system in a Linux environment.
//Commands: cd, ls, rm, touch, mkdir

#include <iostream>
#include <string>
#include <sstream>
#include "LinkedMap.h"
#include "LinkedList.h"
using namespace std;
using namespace ds;

void CommandPrompt() //initializes Linux shell
{	LinkedMap<string,LinkedMap> root; //ERROR: compiler does not recognize LinkedMap as a valid data type
	LinkedMap<string,LinkedMap>* pwd=&root; //points at present working directory

	LinkedList<LinkedMap<string,LinkedMap>*> path; //keeps track of full path to pwd
	path.InsertInFront(pwd);

	LinkedMap<string,LinkedMap>* tmp; //points at created LinkedMap (touch/mkdir)

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
				{	tmp=new LinkedMap<string,LinkedMap>();
					pwd->Put(cmd,*tmp);}}}}}

int main()
{	CommandPrompt();

	return 0;}
