#ifdef STATICBTREE_H
#define STATICBTREE_H
#include <iostream>
#include <cmath>
#include <string>

#define PARENT(i) (((i)-1)/2)
#define LEFT(i) (2*(i)+1)
#define RIGHT(i) (2*(i)+2)

template <class T>
class StaticBTree
{	T* data;
	int height;
	int size;
	public:
	StaticBTree(): height(3),size(0)
	{	data=new T[15];}
	StaticBTree(int height):size(0)
	{	if(height<=0)
		{	this->height=3;}
		data=new T[(int)(pow(2,this->height+1))-1];}
	void Insert(const T& value)
	{	data[size]=value;
		size+=1;}};

#endif
