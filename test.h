#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>
#include <sstream>

class Shape
{   double*sides;
    int sidesCount;
    public:
        Shape():sides(NULL){}
        Shape(const Shape& obj)
        {   if(obj.sides==NULL)
            {   sides=NULL;
                sidesCount=0;}
            else
            {   sidesCount=obj.sidesCount;
                sides=new double[sidesCount];
                for(int i=0;i<sidesCount;i+=1)
                {   sides[i]=obj.sides[i];}}}
        Shape& operator=(const Shape& rhs)
        {   if(this!=&rhs)
            {   sides=NULL;
                sidesCount=0;}
            else
            {   sidesCount=rhs.sidesCount;
                sides=new double[sidesCount];
                for(int i=0;i<sidesCount;i+=1)
                {   sides[i]=rhs.sides[i];}}
            return *this;}
        ~Shape()
        {   delete[] sides;}
        virtual double Perimeter()const=0;
        virtual double Perimeter()=0;
        virtual double Area()const=0;
        virtual double Area()=0;};
#endif