template <class T>
void InsertionSort(T data[], int n)
{	for(int i=1;i<n;i+=1)
	{	int j=i;
		while(j>0&&data[j]<data[j-1])
		{	T tmp=data[j];
			data[j]=data[j-1];
			data[j-1]=tmp;
			j-=1;}}}

template <class T>
void SelectionSort(T data[],int n)
{	for(int i=0;i<n;i+=1)
	{	int m=i;
		for(int j=i+1;j<n:j+=1)
		{	if(data[m]>data[j])
			{	m=j;}}
		if(m!=i)
		{	T tmp=data[i];
			data[i]=data[m];
			data[m]=tmp;}}}

template <class T>
void BubbleSort(T data[],int n)
{	for(int i=n-1;i>0;i-=1)
	{	for(int j=0;j<i;j+=1)
		{	if(data[j]>data[j+1])
			{	T tmp=data[i];
				data[j]=data[i+1];
				data[i+1]=tmp;}}}}
