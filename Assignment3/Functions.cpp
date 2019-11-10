#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include "Set.h"
using namespace std;
using namespace ds;

void RemoveChar(string &str,int n) //removes char from str at index n
{	string tmp;
	for(int i=0;i<n;i+=1) //copies chars before n
	{	tmp+=str[i];}
	for(int j=n+1;j<str.length();j+=1) //copies chars after n
	{	tmp+=str[j];}
	str=tmp;}

//WARNING: a*(b+c+d) does not convert properly! Infix check needs improvements!!!
void ConvertOperations(string &str,char o1,char o2) //converts all o1 and o2 operations in str to postfix
{	int o=0;
	while(o<str.length()) //checks entire str
	{	while(o<str.length() && str[o]!=o1 && str[o]!=o2) //searches for o1 and o2 operators
		{	o+=1;}
		if(str[o]==o1) //checks for o1 operator
		{	if('a'<=str[o+1] && str[o+1]<='z') //checks for infix
			{	int count=0;
				while('a'<=str[o+1] && str[o+1]<='z') //shifts operand(s) left
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
				while('a'<=str[o+1] && str[o+1]<='z') //shifts operand(s) left
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

double Similarity(ifstream &ReadFile1,ifstream &ReadFile2)
{	Set<string> set1;
	Set<string> set2;
	string tmp;
	while(ReadFile1>>tmp)
	{	set1.Add(tmp);}
	while(ReadFile2>>tmp)
	{	set2.Add(tmp);}
	Set<string> i=Intersection(set1,set2);
	Set<string> u=Union(set1,set2);
        cout<<"set1: "<<set1<<"\n";
        cout<<"set2: "<<set2<<"\n";
        cout<<"i: "<<i<<"\n";
        cout<<"u: "<<u<<"\n";
	return double(i.Cardinality())/double(u.Cardinality())*100;}

int main()
{	cout<<"\n";
	string str;
	cout<<"Enter an arithmetic expression with single lowercase letters representing operands: ";
	getline(cin,str);
	cout<<"Postfix: "<<InfixToPostfix(str)<<"\n\n";

	ifstream ReadFile1("ReadFile1.txt");
	ifstream ReadFile2("ReadFile2.txt");
	cout<<"Similarity: "<<Similarity(ReadFile1,ReadFile2)<<"%\n\n";
	ReadFile1.close();
	ReadFile2.close();

	return 0;}
