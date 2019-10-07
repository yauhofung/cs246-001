#include <iostream>
#include <cstdlib>
#include <ctime>
#include "LinkedSet.h"
using namespace ds;

int main()
{
	srand(time(NULL));
	ds::LinkedSet<int> S;

	for(int i = 0;i < 50;i += 1)
	{
		S.Add((rand() % 24 + 5));
	}

	std::cout << "|S| = " << S.Cardinality() << " S = " << S << "\n"; 

	for(int i = 0;i < 10;i += 1)
	{
		S.Remove((rand() % 24 + 5));
	}
	
	std::cout << "|S| = " << S.Cardinality() << " S = " << S << "\n"; 

	return 0;
}
