#ifndef BBNODE_H
#define BBNode_H
using namespace std;

template <class T>
class BBNode
{	private:
	BBNode<T>* left;
	BBNode<T>* right;
	BBNode<T>* p;
	T data;

	public:
	BBNode():BBNode(T(),NULL,NULL,NULL) {}
	BBNode(T data,BBNode<T>* left,BBNode<T>* right,BBNode<T>* p)
	{	this->data=data;
		this->left=left;
		this->right=right;
		this->p=p;}

	T& GetData() {return data;}
	const T& GetData() const {return data;}
	BBNode<T>* GetLeft() {return left;}
	const BNode<T>* GetLeft() const {return left;}
	BBNode<T>* GetRight() {return right;}
	const BNode<T>* GetRight() {return right;}
	BBNode<T>* GetP() {return p;}
	const BBNode<T>* GetP() const {return p;}

	void SetData(const T& data)
	{	this->data=data;}
	void SetLeft(const BBNode<T>* left)
	{	this->left=left;}
	void SetRight(const BBNode<T>* right)
	{	this->right=right;}
	void SetP(const BBNode<T>* p)
	{	this->p=p;}

	string ToString() const
	{	stringstream out;
		out<<data;
		return out.str();}
	friend ostream& operator<<(ostream& out,const BBNode<T>& obj)
	{	out<<obj.ToString();
		return out;}

	BBNode<T>* Copy(BBNode<T>* p,BBNode<T>* root)
	{	if(root=NULL)
		{	return NULL;}
		BBNode<T>* tmp=new BBNode<T>(root->GetData());
		tmp->SetP(p);
		tmp->SetLeft(Copy(tmp,root->GetLeft()));
		tmp->SetRight(Copy(tmp,root->GetRight()));
		return tmp;}

	void Clear(BBNode<T>*& root)
	{	if(root!=NULL)
		{	Clear(root->GetLeft());
			Clear(root->GetRight());
			root->SetP(NULL);
			delete root;
			root=NULL;}};

#endif
