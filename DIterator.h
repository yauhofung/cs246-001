#include "DNode.h"
using namespace std;

template <class T>
class DIterator: public Iterator<T>
{	private:
	DNode*root;
	public:
	DIterator():DIterator(NULL){}
	DIterator(DNode<T>*&root):root(root){}
	bool HasNext() const
	{	return (root!=NULL);}
	T& Next()
	{	T value=root->GetData();
		root=root->GetNext();
		return value;}};
