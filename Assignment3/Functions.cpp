#include <string>
#include <iostream>
using namespace std;

void RemoveChar(string &str,int n) //removes char from str at index n
{	string tmp;
	for(int i=0;i<n;i+=1) //copies chars before n
	{	tmp+=str[i];}
	for(int j=n+1;j<str.length();j+=1) //copies chars after n
	{	tmp+=str[j];}
	str=tmp;}

string InfixToPostfix(string str) //returns str in postfix
{	for(int i=0;i<str.length();i+=1) //traverses through str
	{	if(str[i]==' ') //checks for whitespace
		{	RemoveChar(str,i);
			i-=1;}}
	int p=str.length()-1;
	while(p>0) //converts all parenthetical contents
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
	int e=0;
	while(e<str.length()) //converts all exponents
	{	cout<<str<<"\n";
		while(e<str.length() && str[e]!='^') //searches for exponent
		{	cout<<e<<"\n";
			e+=1;}
		if(str[e]=='^') //checks for exponent
		{	if('a'<=str[e+1] && str[e+1]<='z') //checks for infix ["a^(b^c^d)" DOES NOT CONVERT PROPERLY! INFIX CHECK NEEDS IMPROVEMENT!!!]
			{	int count=0;
				while('a'<=str[e+1] && str[e+1]<='z') //shifts operand(s) left
				{	str[e]=str[e+1];
					e+=1;
					count+=1;}
				for(int i=1;i<count;i+=1) //shifts operators left
				{	str[e]=str[e+1];
					e+=1;}
				str[e]='^';}
			e+=1;}}
	return str;}

int main()
{	string str;
	cout<<"Enter an arithmetic expression with single lowercase letters representing operands: ";
	getline(cin,str);
	cout<<"Postfix: "<<InfixToPostfix(str)<<"\n";

	return 0;}
