#ifndef GRAPH_H
#define GRAPH_H

template <class T>
class Graph
{	private:
		T* labels;
		bool** edges;
		int capacity;
		int size;
	public:
		Graph():Graph(10)
		Graph(int capacity):capacity(capacity),size(0)
		{	if(this->capacity<=0)
			{	this->capacity=10;}
			labels=new T[this->capacity];
			edges=new T*[this->capacity];
			for(int i=0;i<this->capacity;i+=1)
			{	edges[i]=new T[this->capacity];}
			for(int i=0,i<this->capacity;i+=1)
			{	for(int j=0;j<this->capacity;j+=1)
				{	edges[i][j]=false;}}}
		~Graph()
		{	for(int i=0;i<capacity;i+=1)
			{	delete[]edges[i];}
			delete[]edges;
			delete[]labels;}

		void AddVertex(const T& item)
		{	if(size<capacity)
			{	labels[size]=item;
				size+=1;}}

		void AddEdge(int src,int trg)
		{	if(src>=0 && src<size && trg>=0 && trg<size)
			{	edges[src][trg]=true;}}

		void RemoveEdge(int src,int trg)
		{	if(src>=0 && src<size && trg>=0 && trg<size)
                        {       edges[src][trg]=false;}}

		bool IsEdge(int src,int trg)
		{	if(src>=0 && src<size && trg>=0 && trg<size)
			{	return edges[src][trg];}
			return false;}

		int Count() const
		{	return size;}

		T& operator[](int value)
		{	if(value>=0 && value<size)
			{	return labels[value];}
			throw "Vertex Out of Range";}

                const T& operator[](int value) const
                {       if(value>=0 && value<size)
                        {       return labels[value];}
                        throw "Vertex Out of Range";}

		void RemoveVertex(int value)
		{	if(value>=0 && value<size)
			{	size-=1;
				for(int i=value;i<size;i+=1)
				{	labels[i]=labels[i+1];}
				for(int i=0;i<capacity;i+=1)
				{	for(int j=value;j<size;j+=1)
					{	edges[j][i]=edges[j+1][i];}}}}};

#endif
