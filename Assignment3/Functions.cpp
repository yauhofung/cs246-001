#include <string>
#include <sstream>
#include <iostream>
using namespace std;
using namespace ds;

string InfixToPostfix(string s)
{	Map<int,char> str;
	for(int i=0;i<s.length();+=1) //put str in tmpStr
	{	str.Put(i,s[i]);}
	int p=0;
	while(str[p]!='(') //open-parenthesis search
	{	p+=1;}
	if(str[p]=='(') //open-parenthesis detected
	{	str.Remove(p);
		string tmp;
		while(str[p]!=')') //store parenthetical content in tmp
		{	tmp+=str[p];}
		str.Remove(p);
		tmp=InfixToPostfix(tmp);
