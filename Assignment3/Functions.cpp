#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "LinkedSet.h"
#include "LinkedMap.h"
#include "Vector.h"
using namespace std;
using namespace ds;

void RemoveChar(string &str,int n) //removes char from str at index n
{	string tmp;
	for(int i=0;i<n;i+=1) //copies chars before n
	{	tmp+=str[i];}
	for(int j=n+1;j<str.length();j+=1) //copies chars after n
	{	tmp+=str[j];}
	str=tmp;}

//WARNING: a*(b+c+d) does not convert properly! Needs better infix check!!!
void ConvertOperations(string &str,char o1,char o2) //converts all o1 and o2 operations in str to postfix
{	int o=0;
	while(o<str.length()) //checks entire str
	{	while(o<str.length() && str[o]!=o1 && str[o]!=o2) //searches for o1 and o2 operators
		{	o+=1;}
		if(str[o]==o1) //checks for o1 operator
		{	if('a'<=str[o+1] && str[o+1]<='z') //checks for infix
			{	int count=0;
				while('a'<=str[o+1] && str[o+1]<='z') //shifts operands left
				{	str[o]=str[o+1];
					o+=1;
					count+=1;}
				for(int i=1;i<count;i+=1) //shifts operators left
				{	str[o]=str[o+1];
					o+=1;}
				str[o]=o1;}
			o+=1;}
		else if(str[o]==o2) //checks for o2 operator
		{	if('a'<=str[o+1] && str[o+1]<='z') //checks for infix
			{	int count=0;
				while('a'<=str[o+1] && str[o+1]<='z') //shifts operands left
				{	str[o]=str[o+1];
					o+=1;
					count+=1;}
				for(int i=1;i<count;i+=1) //shifts operators left
				{	str[o]=str[o+1];
					o+=1;}
				str[o]=o2;}
			o+=1;}}}

string InfixToPostfix(string str) //returns str in postfix
{	for(int i=0;i<str.length();i+=1) //traverses through str
	{	if(str[i]==' ') //checks for whitespace
		{	RemoveChar(str,i);
			i-=1;}}
	int p=str.length()-1;
	while(p>0) //checks entire str
	{	while(p>0 && str[p]!='(') //searches for last open-parenthesis
		{	p-=1;}
		if(str[p]=='(') //checks for last open-parenthesis
		{	RemoveChar(str,p);
			string tmp;
			int p2=p;
			while(str[p2]!=')') //copies parenthetical contents to tmp
			{	tmp+=str[p2];
				p2+=1;}
			RemoveChar(str,p2);
			tmp=InfixToPostfix(tmp);
			for(int i=0;i<tmp.length();i+=1) //replaces infix parenthetical contents with postfix tmp
			{	str[p+i]=tmp[i];}}}
	ConvertOperations(str,'^','^');
	ConvertOperations(str,'*','/');
	ConvertOperations(str,'+','-');
	return str;}

double Similarity(ifstream &ReadFile1,ifstream &ReadFile2) //returns similarity percentage
{	LinkedSet<string> set1;
	LinkedSet<string> set2;
	string tmp;
	while(ReadFile1>>tmp) //adds ReadFile1 to set1
	{	set1.Add(tmp);}
	while(ReadFile2>>tmp) //adds ReadFile2 to set2
	{	set2.Add(tmp);}
	LinkedSet<string> i=Intersection(set1,set2);
	LinkedSet<string> u=Union(set1,set2);
        cout<<"set1: "<<set1<<"\n";
        cout<<"set2: "<<set2<<"\n";
        cout<<"i: "<<i<<"\n";
        cout<<"u: "<<u<<"\n";
	return double(i.Cardinality())/double(u.Cardinality())*100;}

LinkedSet<int> Mode(ifstream &ReadFile) //returns modes of ReadFile
{	LinkedSet<int> set;
	LinkedMap<int,int> map;
	Vector<int> key;
	int n,maxFreq=1;
	while(ReadFile>>n) //extracts ReadFile ints
	{	if(map.HasKey(n)) //checks for duplicates
		{	map[n]+=1;}
		else //puts in map and inserts key
		{	map.Put(n,1);
			key.Insert(n);}
		if(map[n]>maxFreq) //checks for new maxFreq
		{	maxFreq=map[n];}}
	cout<<"Map: "<<map<<"\n";
	for(int i=0;i<=map.Length();i+=1) //traverses through map
	{	if(maxFreq==map[key[i]]) //adds modes to set
		{	set.Add(key[i]);}}
	return set;}

void MaximumInterval(ifstream &ReadFile,int n) //stores max value of each interval of length n from ReadFile to WriteFile
{	ofstream WriteFile("MaxFile2.txt");
	Vector<int> vec;
	int tmp,max;
	while(ReadFile>>tmp) //inserts ReadFile ints to vec
	{	vec.Insert(tmp);}
	for(int i=0;i<vec.Length()-2;i+=1) //traverses through vec
	{	max=0;
		for(int j=i;j<i+n;j+=1) //searches for max
		{	if(vec[j]>max) //checks for new max
			{	max=vec[j];}}
		WriteFile<<max<<" ";}
	WriteFile<<"\n";
	WriteFile.close();}

int main()
{	cout<<"\n";
	string str;
	cout<<"Enter an arithmetic expression with single lowercase letters representing operands: ";
	getline(cin,str);
	cout<<"Postfix: "<<InfixToPostfix(str)<<"\n\n";

	ifstream SimFile1("SimFile1.txt");
	ifstream SimFile2("SimFile2.txt");
	cout<<"Similarity: "<<Similarity(SimFile1,SimFile2)<<"%\n\n";
	SimFile1.close();
	SimFile2.close();

	ifstream ModeFile("ModeFile.txt");
	cout<<"Mode: "<<Mode(ModeFile)<<"\n\n";
	ModeFile.close();

	int length;
	ifstream MaxFile1("MaxFile1.txt");
	cout<<"Enter the length of each interval: ";
	cin>>length;
	MaximumInterval(MaxFile1,length);
	cout<<"Max values stored in MaxFile2.txt.\n\n";
	MaxFile1.close();

	return 0;}
