#ifndef TEST_H
#define TEST_H
#include <iostream>
#include <string>
#include <sstream>

class Shape
{   double* sides;
    int sidesCount;
    public:
        Shape():sides(NULL){}
        Shape(int size):sidesCount(size) //overloaded constructor
        {   if(sidesCount<=0)
            {   sidesCount=3;}
            sides=new double[sidesCount];
            for(int i=0;i<sidesCount;i+=1)
            {   sides[i]=1.0;}}
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
        virtual double Perimeter() const=0;
        virtual double Perimeter()=0;
        virtual double Area() const=0;
        virtual double Area()=0;
        int GetSides() const
        {   return sidesCount;}
        int GetSides()
        {   return sidesCount;}
        double GetSide(int index) const
        {   if(index>=0 and index<sidesCount)
            {   return sides[index];}
            throw "Out of Bound";}
        double GetSide(int index)
        {   if(index>=0 and index<sidesCount)
            {   return sides[index];}
            throw "Out of Bound";}
        void SetSide(int index,double value)
        {   if(index>=0 and index<sidesCount and value>0)
            {   sides[index]=value;}}
        const double& operator[](int index) const
        {   if(index>=0 and index<sidesCount)
            {   return sides[index];}
            throw "Out of Bound";}
        double& operator[](int index)
        {   if(index>=0 and index<sidesCount)
            {   return sides[index];}
            throw "Out of Bound";}};
class Rectangle:public Shape
{   public:
        Rectangle():Shape(2){}
        Rectangle(double length,double width):
        Rectangle()
        {   if(length>0 and width>0)
            {   SetSide(0,(length<width)?(length):(width));
                SetSide(1,(length>width)?(length):(width));}}
        Rectangle(const Rectangle& obj):
        Shape(dynamic_cast<const Shape&>(obj)){}
        Rectangle& operator=(const Rectangle& rhs)
        {   if(this!=&rhs)
            {   Shape::operator=(dynamic_cast<const Shape&>(rhs));}
            return *this;}
        ~Rectangle(){}
        void SetWidth(double value)
        {   if(GetSide(1)>=value and value>0)
            {   SetSide(0,value);}}
        void SetLength(double value)
        {   if(GetSide(0)<=value and value>0)
            {   SetSide(1,value);}}
        double GetWidth()
        {   return GetSide(0);}
        double GetLength()
        {   return GetSide(1);}
        double Perimeter() const
        {   return 2*(GetSide(0)+GetSide(1));}
        double Perimeter()
        {   return 2*(GetSide(0)+GetSide(1));}
        double Area() const
        {   return GetSide(0)*GetSide(1);}
        double Area()
        {   return GetSide(0)*GetSide(1);}
    private:
        using Shape::GetSide;
        using Shape::SetSide;
        using Shape::GetSides;
        using Shape::GetSide const;};
#endif