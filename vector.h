#ifndef VECTOR_H
#define VECTOR_H
#include <iostream>
#include <string>
#include <sstream>

template<class T>
class Vector
{   private:
        T* data;
        int size;
        int capacity;
        void Resize()
        {   T* tmp=new T[capacity];
            for(int i=0;i<capacity;i+=1)
            {   tmp[i]=data[i];}
            delete[]data;
            capacity*=2;
            data=new T[capacity];
            for(int i=0;i<size;i+=1)
            {   data[i]=tmp[i];}
            delete[]tmp;}
    public:
        Vector()
        {   size=0;
            capacity=10;
            data=new T[capacity];
            for(int i=0;i<capacity;i+=1)
            {   data[i]=T();}}
        Vector(const Vector<T>& obj)
        {   size=obj.size;
            capacity=obj.capacity;
            data=new T[capacity];
            for(int i=0;i<size;i+=1)
            {   data[i]=obj.data[i];}}
        Vector<T>& operator=(const Vector<T>& rhs)
        {   if(this!=&rhs)
            {   size=rhs.size;
                capacity=rhs.capacity;
                delete[]data;
                data=new T[capacity];
                for(int i=0;i<size;i+=1)
                {   data[i]=rhs.data[i];}}
            return *this;}
        ~Vector()
        {   delete[]data;}
        std::string ToString() const
        {   std::stringstream out;
            out<<"[";
            for(int i=0;i<size;i+=1)
            {   out<<data[i];
                if(i!=size-1)
                {   out<<",";}}
            out<<"]";
            return out.str();}
        friend std::ostream& operator<<(std::ostream& out,const Vector<T>& obj)
        {   out<<obj.ToString();
            return out;}
        void Insert(const T& value)
        {   if(size==capacity)
            {   Resize();}
            data[size]=value;
            size+=1;}
        void Remove()
        {   if(size>0)
            {   size-=1;}}
        T& operator[](int index)
        {   if(index>=0&&index<size)
            {   return data[index];}
            throw "Out of Bound";}
        const T& operator[](int index) const
        {   if(index>=0&&index<size)
            {   return data[index];}}
        bool IsEmpty() const
        {   return size==0;}
        int Size() const
        {   return size;}
        int Capacity() const
        {   return capacity;}
        void Fill(const T& value,int n)
        {   Clear();
            for(int i=0;i<n;i+=1)
            {   Insert(value);}}
        void Clear()
        {   size=0;}};

#endif