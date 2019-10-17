#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Queue.h"
using namespace ds;
using namespace std;

void CountToNBinary(int n)
{	Queue<string> queue;
	string val;
	string binary[2]={"0","1"};
	if(n>=1)
	{	cout<<"1\n";}
	queue.Enqueue("1");
	for(int i=2;i<=n;i+=1)
	{	val=queue.Peek();
		val+=binary[i%2];
		cout<<val<<"\n";
		queue.Enqueue(val);
		if(i%2==1)
		{	queue.Dequeue();}}}

int main()
{
	srand(time(NULL));
	ds::Queue<int> queue;
	std::string output, input;
	int value;

	input = "{";
	for(int i = 0;i < 10;i += 1)
	{
		value = rand() % 24 + 5;
		queue.Enqueue(value);
		input += std::to_string(value) + ",";
	}
	input[input.length()-1] = '}';

	std::cout << "Inputs: " << input << "\n";

	output = "{";
	while(!queue.IsEmpty())
	{
		output += queue.ToString() + ",";
		queue.Dequeue();
	}
	output[output.length()-1] = '}';
	
	std::cout << "Outputs: " << output << "\n";

	CountToNBinary(100);

	return 0;
}
