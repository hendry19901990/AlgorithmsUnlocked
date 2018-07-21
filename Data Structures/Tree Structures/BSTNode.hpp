#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <regex>
#include <sstream>
using namespace std;

template <typename T>
class BSTNode;

template <typename T>
using node_ptr = std::shared_ptr<BSTNode<T> >;

template <typename T>
class BSTNode
{
	T data_item;
	int left_height, right_height;
	node_ptr<T> left, right;
public:
	BSTNode() : data_item(0), left_height(0), right_height(0), left(nullptr), right(nullptr) { }
	BSTNode(T& data) : data_item(data), left_height(0), right_height(0), left(nullptr), right(nullptr) { }
	~BSTNode() {}
	T getdata() const;
	void setdata(T& item); 
	void addLeft(T&);
	void addRight(T&);
	void addItem(T& , const node_ptr<T>&);
	bool SearchMethod(T&, const node_ptr<T>&) const; 
};
template <typename T>
T BSTNode<T>::getdata() const
{
	return this->data_item;	
}
template <typename T>
void BSTNode<T>::setdata(T& item)
{
	this->data_item = item;	
}
template <typename T>
void BSTNode<T>::addLeft(T& item)
{
	this->left = std::make_shared<BSTNode<T> >(item);
}
template <typename T>
void BSTNode<T>::addRight(T& item)
{
	this->right = std::make_shared<BSTNode<T> >(item);
}
template <typename T>
void BSTNode<T>::addItem(T& item, const node_ptr<T> &root)
{
	auto data = root->getdata();
	if(item > data){
		if(root->right != nullptr){
			root->addItem(item, root->right);
		}
		else{
			root->addRight(item);
		}
	}
	if(item < data){
		if(root->left != nullptr){
			root->addItem(item, root->left);
		}
		else{
			root->addLeft(item);
		}
	}
}
template <typename T>
bool BSTNode<T>::SearchMethod(T& item, const node_ptr<T> &root) const
{
	auto data = root->getdata();
	if(item == data){
		cout << "Data found in BST. " << endl;
		return true;
	}
	else if ( (item > data) && root->right != nullptr){
		root->SearchMethod(item, root->right);
	}
	else if ( (item < data) && root->left != nullptr){
		root->SearchMethod(item, root->left);	
	}
	else
	{
		cout << "Not found " << endl; 
	} 
	return false;
}
