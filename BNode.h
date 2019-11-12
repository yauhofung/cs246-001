#ifndef BNODE_H
#define BNode_H
using namespace std;

template <class T>
class BNode
{	private:
	BNode<T>*left;
	BNode<T>*right;
	T data;

	public:
	BNode():BNode(T(),NULL,NULL) {}
	BNode(T data,BNode<T>*left,BNode<T>*right)
	{	this->data=data;
		this->left=left;
		this->right=right;}

	T& GetData()
	{	return data;}
	const T& GetData() const
	{	return data;}
	BNode<T>* GetLeft() {return left;}
	const BNode<T>* GetLeft() const {return left;}
	BNode<T>* GetRight() {return right;}
	const BNode<T>* GetRight() {return right;}

	void SetData(const T& data)
	{	this->data=data;}
	void SetLeft(const BNode<T>* left)
	{	this->left=left;}
	void SetRight(const BNode<T>* right)
	{	this->right=right;}

	string ToString() const
	{	stringstream out;
		out<<data;
		return out.str();}
	friend ostream& operator<<(ostream& out,const BNode<T>& obj)
	{	out<<obj.ToString();
		return out;}}
