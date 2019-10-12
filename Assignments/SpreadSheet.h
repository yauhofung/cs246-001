#ifndef SPREADSHEET_H
#define SPREADSHEET_H

#include <iostream>
#include <string>
#include <sstring>
using namespace std;
using namespace ds;

class SpreadSheet
{	double* grid;
	int columns;
	int rows;
	bool IsCoordinate(string coordinate) const
	{	if((64<coordinate[0]&&coordinate[0]<91||96<coordinate[0]&&coordinate[0]<113)&&48<coordinate[1]&&coordinate[1]<58) //'A'=65,'Z'=90,'a'=97,'z'=112,'1'=49,'9'=57
		{	if(coordinate.length()<3) //2-char string
			{	return true;}
			else if(coordinate.length<4&&47<coordinate[2]&&coordinate[2]<58) //3-char string '0'=48,'9'=57
			{	return true;}
			else
			{	return false;}}
		else
		{	return false;}}
	int GetIndex(string coordinate) const
	{	if(IsCoordinate(coordinate))
		{	if(64<coordinate[0]&&coordinate[0]<91) //Uppercase 'A'=65,'Z'=90
			{	int index=coordinate[0]-64;}
			else //Lowercase
			{	int index=coordinate[0]-96;}
			if(coordinate.length()<3) //2-char string
			{	index*=(coordinate[1]-48);}
			else //3-char string
			{	index*=(coordinate[1]*10+coordinate[2]-528);} //(coordinate[1]-48)*10-coordinate[2]-48 Simplified
			return index;}
		else
		{	throw "Invalid Coordinate";}}
	public:
		SpreadSheet()
		{	columns=10;
			rows=15;
			grid=new double[rows*columns];
			for(int i=0;i<rows*columns;i+=1)
			{	grid[i]=0.0;}
		SpreadSheet(const SpreadSheet& obj)
		{	columns=obj.columns;
			rows=obj.rows;
			if(columns>0&&rows>0)
			{	grid=new double[rows*columns];
				for(int i=0;i<rows*columns;i+=1)
	                        {       grid[i]=obj.grid[i];}}
			else
			{	grid=NULL;}}
		SpreadSheet& operator=(const Counter& rhs)
		{	if(this!=&rhs)
			{	columns=rhs.columns;
				rows=rhs.rows;
				delete[] data;
				if(columns>0&&rows>0)
				{	grid=new double[rows*columns];
	                                for(int i=0;i<rows*columns;i+=1)
        	                        {       grid[i]=obj.grid[i];}}
	                        else
        	                {       grid=NULL;}}
			return *this;}
		~SpreadSheet()
		{	delete[] grid;}
		int Columns() const
		{	return columns;}
		int Rows() const
		{	return rows;}
		string ToString() const
		{	stringstream out;
			out<<left<<"        "
			for(int i=0;i<columns;i+=1)
			{	out<<setw(8)<<char(i+65);}
			out<<"\n";
			for(int i=1;i<=rows;i+=1)
			{	out<<setw(8)<<i;
				for(int j=1;j<=columns;j+=1)
				{	out<<setw(8)<<fixed<<setprecision(2)<<"["<<GetCell(string(char(j+64))+string(i))<<"]";}
				out<<"\n";}
			return out.str();}
		friend ostream& operator<<(ostream& out,const SpreadSheet& obj)
		{	out<<obj.ToString();
			return out;}
		double GetCell(string coordinate) const
		{	if(IsCoordinate(coordinate))
			{	

#endif
