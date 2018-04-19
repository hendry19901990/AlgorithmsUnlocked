#ifndef _DOUBLE_LINKED_LIST

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <memory>
#include <string>
#include <sstream>
#include <map>
using namespace std;
/*Forward Class Defination*/
template <typename T> class DLinkedList;
template <typename _type>
class DNode
{
private:
	_type elem;
	std::shared_ptr<DNode> prev;
	std::shared_ptr<DNode> next;
public:
	DNode() : prev(nullptr), next(nullptr) {}
	DNode(_type e) : elem(std::move(e)), prev(std::make_shared(new DNode)), next(std::make_shared(new DNode)) {}
	DNode(DNode&& e) noexcept
	{
		this->elem = e.elem;
		this->prev = e.prev;
		this->next = e.next;
	}
	DNode& operator= (DNode&& e) noexcept
	{
		this->elem = e.elem;
		this->elem = e.elem;
		this->prev = e.prev;
		this->next = e.next;
		return *this;
	}
	~DNode() {}
	_type getelem()
	{
		return elem;
	}
	friend class DLinkedList<_type>;
};
template <typename T>
class DLinkedList
{
public:
	DLinkedList();
	~DLinkedList();
	bool empty() const;
	const T& front() const;
	const T& back() const;
	bool addFront(const T& e);
	bool addBack(const T& e);
	bool removeFront();
	bool removeBack();
private:
	std::shared_ptr<DNode<T> > header;
	std::shared_ptr<DNode<T> > tail;
protected:
	/* Protected Methods */
	bool add(std::shared_ptr<DNode<T> > em, const T& e);
	bool remove(std::shared_ptr<DNode<T> > em);
};

template <typename T>
DLinkedList<T>::DLinkedList()
{
	header = std::make_shared<DNode<T> >(new DNode<T>());
	tail = std::make_shared<DNode<T> >(new DNode<T>());
	header->next = tail;
	tail->prev = header;
}
template <typename T>
DLinkedList<T>::~DLinkedList()
{
	while (!empty()) removeFront();
	delete header;
	delete tail;
}
template <typename T>
bool DLinkedList<T>::empty() const
{
	return (header->next == tail);
}
template <typename T>
const T& DLinkedList<T>::front() const
{
	return header->next->elem;
}
template <typename T>
const T& DLinkedList<T>::back() const
{
	return tail->prev->elem;
}
template <typename T>
bool DLinkedList<T>::add(std::shared_ptr<DNode<T> > node, const T& e)
{
	std::shared_ptr<DNode<T> > temp = std::make_shared<DNode<T> >(new DNode<T>());
	temp->elem = e;
	temp->next = node;
	temp->prev = node->prev;
	node->prev->next = node->prev = temp;
	return true;
}
template <typename T>
bool DLinkedList<T>::remove(std::shared_ptr<DNode<T> > node)
{
	std::shared_ptr<DNode<T> > temp_front = node->prev;
	std::shared_ptr<DNode<T> > temp_back = node->next;
	temp_front->next = temp_back;
	temp_back->prev = temp_front;
	delete node;
	return true;
}
template <typename T>
bool DLinkedList<T>::addFront(const T& e)
{
	add(header->next, e);
}
template <typename T>
bool DLinkedList<T>::addBack(const T& e)
{
	add(tail, e);
}
template <typename T>
bool DLinkedList<T>::removeBack()
{
	remove(tail->prev);
}
template <typename T>
bool DLinkedList<T>::removeFront()
{
	remove(header->next);
}

#define _DOUBLE_LINKED_LIST 1
#endif // !_DOUBLE_LINKED_LIST
