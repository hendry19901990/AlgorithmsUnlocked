#ifndef _LINKED_LIST 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include <stdexcept>
using namespace std;
/*Forward Class Defination for making friend class*/
template <typename T> class LinkedList;
template<typename T>
class ListNode
{
public:
	ListNode(const T& elem) : node(elem), next(std::make_shared<ListNode>()) {}
	~ListNode() {}
	ListNode() {}
	ListNode& operator=(ListNode&&);
	friend class LinkedList<T>;
private:
	std::shared_ptr<ListNode> next;
	T node;
	/* More data members can be added but I am keeping it simple here. */
};
template<typename T>
inline ListNode<T>& ListNode<T>::operator=(ListNode && link)
{
	this->node = link.node;
	this->next = link.next;
}
template <typename T>
class LinkedList
{
public:
	LinkedList();
	LinkedList(const T& elem);
	void front() const;
	void addFront(const T& elem) noexcept;
	void relocate() noexcept;
	void addBack(const T& elem) noexcept;
	void addAt(const int& pos, const T& elem) noexcept;
	void operator=(const ListNode<T>&) noexcept;
	void removeFront() noexcept;
	void removeBack() noexcept;
	void printnodes() noexcept;
	void removeNode(const int& pos) noexcept;
private:
	std::shared_ptr<ListNode<T> > head;
	std::shared_ptr<ListNode<T> > tail;
	int count;
};
template <typename T>
void LinkedList<T>::front() const
{
	return head->next->node;
}
template<typename T>
void LinkedList<T> :: operator=(const ListNode<T>& temp) noexcept
{
	this->node = temp->node;
	this->next = temp->next;
}
template<typename T>
inline void LinkedList<T>::removeFront() noexcept
{

}
template <typename T>
LinkedList<T> ::LinkedList() : head(std::make_shared<ListNode<T> >()), tail(std::make_shared<ListNode<T> >()), count(0)
{
	head->next = nullptr;
	tail = head;
	tail->next = nullptr;
}
template <typename T>
LinkedList<T> ::LinkedList(const T& elem) : head(std::make_shared<ListNode<T> >()), tail(std::make_shared<ListNode<T> >()), count(0)
{
	head->node = elem;
	head->next = nullptr;
	relocate();
}
template <typename T>
void LinkedList<T> ::addFront(const T& elem) noexcept
{
	std::shared_ptr<ListNode<T> > front = std::make_shared<ListNode<T> >();
	front->node = elem;
	front->next = head;
	head = front;
}
template <typename T>
void LinkedList<T> ::addAt(const int& pos, const T& elem) noexcept
{
	count = 1;
	std::shared_ptr<ListNode<T> > temp = std::make_shared<ListNode<T> >();
	std::shared_ptr<ListNode<T> > add = std::make_shared<ListNode<T> >();
	add->node = elem;
	add->next = nullptr;
	temp = head;
	while (count != pos - 1)
	{
		temp = temp->next;
		count++;
	}
	add->next = temp->next;
	temp->next = add;
}
template <typename T>
void LinkedList<T> ::removeNode(const int& pos) noexcept
{
	count = 1;
	std::shared_ptr<ListNode<T> > temp = std::make_shared<ListNode<T> >();
	temp = head;
	while (count != pos - 1)
	{
		temp = temp->next;
		count++;
	}
	temp->next = temp->next->next;
}
template <typename T>
void LinkedList<T> ::removeBack() noexcept
{
	count = 1;
	std::shared_ptr<ListNode<T> > temp = std::make_shared<ListNode<T> >();
	temp = head;
	while (temp->next->next != nullptr)
	{
		temp = temp->next;
	}
	temp->next = nullptr;
}
template <typename T>
void LinkedList<T> ::relocate() noexcept
{
	std::shared_ptr<ListNode<T> > temp = std::make_shared<ListNode<T> >();
	temp = head;
	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	tail = temp;
	tail->next = nullptr;
}
template <typename T>
void LinkedList<T> ::printnodes() noexcept
{
	std::shared_ptr<ListNode<T> > temp = std::make_shared<ListNode<T> >();
	temp = head;
	while (temp->next != nullptr)
	{
		cout << temp->node << "->";
		temp = temp->next;
	}
	cout << endl;
}
template <typename T>
void LinkedList<T> ::addBack(const T& elem) noexcept
{
	relocate();
	std::shared_ptr<ListNode<T> > back = std::make_shared<ListNode<T> >();
	back->node = elem;
	back->next = nullptr;
	tail->next = back;
	tail = back;
}

#define _LINKED_LIST 1
#endif // !_LINKED_LIST 
