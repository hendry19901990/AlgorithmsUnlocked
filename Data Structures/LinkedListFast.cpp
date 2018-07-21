#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <regex>
#include <sstream>
using namespace std;

template <typename T>
class ListNode;

template <typename T>
using list_ptr = std::shared_ptr<ListNode<T> >;

template <typename T>
class ListNode
{
	T data;
	list_ptr<T> next, prev; 
public:
	ListNode() : data(), next(nullptr) { }
	ListNode(T& item) : data(item), next(nullptr) { }
	~ListNode() {}
	T getlistdata() const;
	void setlistdata(T& item);
	void PrintList(const list_ptr<T> &root);
	void addNode(T& item, const list_ptr<T> &root);
	void deleteNode(const list_ptr<T> &root);
	// void UpdateNode(T& item, T& search);
	void SearchList(T& item); 
};
template <typename T>
T ListNode<T>::getlistdata() const 
{
	return this->data;
}
template <typename T>
void ListNode<T>::setlistdata(T& item)
{
	this->data = item;
}
template <typename T>
void ListNode<T>::addNode(T& item, const list_ptr<T> &root)
{
	list_ptr<T> temp = root;
	while(temp->next != nullptr) { temp = temp->next; }
	temp->next = std::make_shared<ListNode<int> >(item);
}
template <typename T>
void ListNode<T>::deleteNode(const list_ptr<T> &root)
{
	list_ptr<T> temp = root;
	while(temp->next->next != nullptr) { temp = temp->next; }
	temp->next->data = 0;
    temp->next = nullptr;
}
template <typename T>
void ListNode<T>::PrintList(const list_ptr<T> &root)
{
	list_ptr<T> temp = root;
	cout << endl << "List is : " << endl;
	while(temp->next != nullptr)
	{ 
		cout << "[ " << temp->data << " ]" << " --> ";
		temp = temp->next;
	}
}