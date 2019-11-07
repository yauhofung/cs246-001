template <class T>
void Merge(T data[],int p,int q,int r)
{	const int m=r-p+1;
	const int n=q-r;
	T L[m],R[n];
	for(int i=0;i<m;i+=1)
	{	L[i]=data[p+i];}
	for(int i=0;i<n;i+=1)
	{	R[i]=data[r+1+i];}
	int lc=0,rc=0;
	int i=p;
	while(lc<m&&rc<n)
	{	if(L[lc]<=R[rc])
		{	data[i]=L[lc];
			lc+=1;}
		else
		{	data[i]=R[rc];
			rc+=1;}
		i+=1;}
	if(lc!=m)
	{	while(lc<m)
		{	data[i]=L[lc];
			i+=1;
			lc+=1;}}
	else
	{	while(rc<n)
		{	data[i]=R[rc];
			i+=1;
			rc+=1;}}}

template <class T>
void MergeSort(T data[],int p,int q)
{	if(p<q)
	{	int r=(p+q)/2;
		MergeSort(data,p,r);
		MergeSort(data,p,q,r);
		Merge(data,p,q,r);}}
