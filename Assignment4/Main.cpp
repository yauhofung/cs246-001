#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "FrequencyTable.h"
using namespace std;

string CharacterCount(ifstream& ReadFile)
{	string str;
	getline(ReadFile,str);
	return str;}


