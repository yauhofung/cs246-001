#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "FrequencyTable.h"
#include "Spooler.h"
using namespace std;

string CharacterCount(ifstream& ReadFile)
{	string str;
	getline(ReadFile,str);
	return str;}

void Printer(ofstream& WriteFile)
{	int option;
	Spooler spooler;
	while(option!=4)
	{	cout<<"1. Add a job and count.\n";
		cout<<"2. Display query.\n";
		cout<<"3. Execute batch.\n";
		cout<<"4. Quit.\n";
		cout<<"Select an option: ";
		getline(cin,option);

		if(option==1)
		{	string path;
			int count;
			cout<<"Enter a file path: ";
			getline(cin,path);
			cout<<"Enter a count: ";
			getline(cin,count);
			spooler.AddJob(path,count);}

		else if(option==2)
		{	cout<<spooler<<"\n";}

		else if(option==3)
		{	string str;
			Pair<string,int> job=spooler.ExecuteJob();
			ifstream ReadFile(job.GetKey());
			
