#ifndef SPOOLER_H
#define SPOOLER_H

#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "Pair.h"
using namespace std;

class Spooler
{	private:
		Node<Pair<string,int> >* front;
		Node<Pair<string,int> >* back;
	public:
		
