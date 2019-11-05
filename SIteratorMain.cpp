using namespace std;

int main()
{	LinkedList<int> list;
	srand(time(NULL));
	int n=5+rand()%26;
	for(int i=0;i<n;i+=1)
	{	list.InsertInBack(rand()%1000+1);}
	SIterator<int>*iter=list.GetIterator();
	while(iter->HasNext())
	{	cout<<iter->Next()<<"\n";}
	return 0;}
