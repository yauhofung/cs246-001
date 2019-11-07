#ifndef INTEGER_H
#define INTEGER_H

#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
using namespace std;

template <class T>
class Integer
{	T I;
	public:
		Integer() //default constructor
		{}
		Integer(const Integer<T>& obj) //copy constructor
		{	I=obj.I;}
		Integer& operator=(const Integer<T>& rhs) //overloaded assignment operator
		{	if(this!=&rhs)
			{	I=rhs.I;}
			return *this;}
		~Integer() //destructor
		{}

		Integer(int i) //int overloaded constructor
		{	I=i;}
		Integer(string s) //string overloaded constructor
		{	I=s;}

		string ToString() const //ToString() method
		{	stringstream out;
			out<<I;
			return out.str();}
		friend ostream& operator<<(ostream& out,const Integer<T>& obj) //overloaded ostream operator
		{	out<<obj.ToString();
			return out;}

		friend Integer& operator==(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded equal-to operator
		{	if(lhs.I==rhs.I)
			{	return true;}
			else
			{	return false;}}
                friend Integer& operator!=(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded not-equal operator
                {       if(lhs.I!=rhs.I)
                        {       return true;}
                        else
                        {       return false;}}
                friend Integer& operator>(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded greater-than operator
                {       if(lhs.I>rhs.I)
                        {       return true;}
                        else
                        {       return false;}}
                friend Integer& operator<(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded less-than operator
                {       if(lhs.I<rhs.I)
                        {       return true;}
                        else
                        {       return false;}}
                friend Integer& operator>=(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded greater-than-or-equal-to operator
                {       if(lhs.I>=rhs.I)
                        {       return true;}
                        else
                        {       return false;}}
                friend Integer& operator<=(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded less-than-or-equal-to operator
                {       if(lhs.I<=rhs.I)
                        {       return true;}
                        else
                        {       return false;}}

		friend Integer& operator+(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded plus operator
		{	return lhs.I+rhs.I;}
                friend Integer& operator-(const Integer<T>& lhs,const Integer<T>& rhs) //overloaded minus operator
                {       return lhs.I-rhs.I;}

		void ReadInteger(ifstream& ReadFile,Integer<T>& obj) //read from file
		{	ReadFile>>obj.I;}

		void Statistics(ofstream& WriteFile,Integer<T>& obj1,Integer<T>& obj2) //write to file
		{	WriteFile<<"The first Integer is "; //relational
			if(obj1.I>obj2.I)
			{	WriteFile<<"greater than";}
			else if(obj1.I<obj2.I)
			{	WriteFile<<"less than";}
			else
			{	WriteFile<<"equal to";}
			WriteFile<<" the second Integer.\n";

			WriteFile<<"\nSum\n"; //plus
			WriteFile<<obj1.I+obj2.I<<"\n";

			WriteFile<<"\nDifference\n"; //minus obj1 FROM obj2
			WriteFile<<obj2.I-obj1.I<<"\n";}};
#endif
