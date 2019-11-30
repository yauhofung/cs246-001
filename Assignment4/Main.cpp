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
		{	while(!spooler.IsEmpty())
			{	Pair<string,int> job=spooler.ExecuteJob();
				ifstream ReadFile(job.GetKey());
				if(ReadFile.is_open)
				{	for(int i=0;i<job.GetValue();i+=1)
					{	WriteFile<<ReadFile<<"  ";}
					ReadFile.close();}
				else
				{	cout<<"Error: Cannot Print";}}
			cout<<"Batch executed.\n";}

		else if(option!=4)
		{	cout<<"Invalid input.\n";}}}

void DisplayTowers(Tower t1,Tower t2,Tower t3)
{	cout<<"Tower 1: "<<t1<<"\n";
	cout<<"Tower 2: "<<t2<<"\n";
	cout<<"Tower 3: "<<t3<<"\n";}

void TowersOfHanoi(Tower& t1,Tower& t2,Tower& t3) //implementation based on https://en.wikipedia.org/wiki/Tower_of_Hanoi#Simpler_statement_of_iterative_solution
{	if(t1.Size()%2==0)
	{	while(!t1.IsEmpty() && !t2.IsEmpty())
		{	if(t1.Top()<t2.Top())
			{	t2.AddDisk(t1.RemoveDisk());}
			else
			{	t1.AddDisk(t2.RemoveDisk());}
			DisplayTowers(t1,t2,t3);

			if(t1.Top()<t3.Top())
                        {       t3.AddDisk(t1.RemoveDisk());}
                        else
                        {       t1.AddDisk(t3.RemoveDisk());}
                        DisplayTowers(t1,t2,t3);

			if(t2.Top()<t3.Top())
                        {       t3.AddDisk(t2.RemoveDisk());}
                        else
                        {       t2.AddDisk(t3.RemoveDisk());}
                        DisplayTowers(t1,t2,t3);}}
	else
	{	while(!t1.IsEmpty() && !t2.IsEmpty())
                {       if(t1.Top()<t3.Top())
                        {       t3.AddDisk(t1.RemoveDisk());}
                        else
                        {       t1.AddDisk(t3.RemoveDisk());}
                        DisplayTowers(t1,t2,t3);

                        if(t1.Top()<t2.Top())
                        {       t2.AddDisk(t1.RemoveDisk());}
                        else
                        {       t1.AddDisk(t2.RemoveDisk());}
                        DisplayTowers(t1,t2,t3);

                        if(t2.Top()<t3.Top())
                        {       t3.AddDisk(t2.RemoveDisk());}
                        else
                        {       t2.AddDisk(t3.RemoveDisk());}
                        DisplayTowers(t1,t2,t3);}}}
