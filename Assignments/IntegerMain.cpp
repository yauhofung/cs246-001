#include "Integer.h"
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>

int main()
{	Integer<int> obj1,obj2;

	ifstream ReadFile1("ReadFile1.txt");
	ifstream ReadFile2("ReadFile2.txt");
	ofstream WriteFile("WriteFile.txt");

	obj1.ReadInteger(ReadFile1,obj1);
	obj2.ReadInteger(ReadFile2,obj2);

	obj1.Statistics(WriteFile,obj1,obj2);

	ReadFile1.close();
	ReadFile2.close();
	WriteFile.close();
	return 0;}
