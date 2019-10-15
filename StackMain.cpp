#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include <fstream>
#include "Stack.h"
using namespace ds;
using namespace std;

void ReverseFile(ifstream& in)
{       Stack<char> stack;
        char ch;
        while(in>>ch)
        {       if(ch!=' '&&ch!='\n')
                {       stack.Push(ch);}}
        ofstream out("reverse.txt");
        while(!stack.IsEmpty())
        {       out<<stack.Top();
                stack.Pop();}
        out.close();}

bool IsZeroTwice(char* str)
{	bool Switch=false;
	Stack<char> stack;
	if(str=='\0')
	{	return true;}
	else
	{	int i=0;
		while(str[i]!='\0' && !Switch)
		{	if(str[i]=='0')
			{	stack.Push('0');
				i+=1;}
			else if(str[i]=='1')
			{	Switch=true;}
			else
			{	return false;}}}
	if(!Switch)
	{	return false;}
	else
	{	while(str[i]!='\0')
		{	if(str[i]=='1')
			{	stack.Pop();
				if(stack.IsEmpty())
				{	return false;}
				else
				{	stack.Pop();}
				i+=1;}
			else
			{	return false;}}}
	return stack.IsEmpty();}

	int zeroCount=0;
	int oneCount=0;
	if(
	for(int i=0;i<str.length();i+=0)
	{	if(str[i]=='0')
		{	

int main()
{
	srand(time(NULL));
	ds::Stack<int> stack;
	std::string output, input;
	int value;

	input = "{";
	for(int i = 0;i < 10;i += 1)
	{
		value = rand() % 24 + 5;
		stack.Push(value);
		input += std::to_string(value) + ",";
	}
	input[input.length()-1] = '}';

	std::cout << "Inputs: " << input << "\n";

	output = "{";
	while(!stack.IsEmpty())
	{
		output += stack.ToString() + ",";
		stack.Pop();
	}
	output[output.length()-1] = '}';
	
	std::cout << "Outputs: " << output << "\n";
 
	return 0;
}
