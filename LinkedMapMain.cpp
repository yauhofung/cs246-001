#include <iostream>
#include "LinkedMap.h"
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

char LetterMode(string str)
{	LinkedMap<char,int> map;
	char ch;
	int max=1;
	for(int i=0;str[i]!='\0';i+=1)
	{	ch=tolower(str[i]);
		if(islower(ch))
		{	if(map.HasKey(ch))
			{	map[ch]+=1;}
			else
			{	map.Put(ch,1);}
			if(max<map[ch])
			{	max=map[ch];}}}
	if(map.IsEmpty())
	{	return '\0';}
	for(char i='a';i<='z';i+=1)
	{	if(max==map[i])
		{	return i;}}}

int main()
{
	std::cout << "Linked Map Test\n";
	ds::LinkedMap<int,std::string> a;
	
	std::string numbers[10] = {"Zero","One","Two","Three","Four","Five","Six","Seven","Eight","Nine"};
	
	for(int i = 0;i < 10;i += 1)
	{
		a.Put(i,numbers[i]);
	}

	std::cout << a << "\n";

	return 0;
}
