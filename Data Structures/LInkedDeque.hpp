#ifndef _LINKED_DEQUE 

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <stdexcept>
#include "DLinkedList.hpp"
using namespace std;
/*A dequeue using a Double linked list*/
class RuntimeException
{
private:
	string errorMsg;
public:
	RuntimeException(const string& err)
	{
		errorMsg = err;
	}
	string getMessage() const
	{
		return errorMsg;
	}
};
class QueueEmpty : public RuntimeException {
public:
	std::stringstream ss;
	QueueEmpty(const string& err) : RuntimeException(err)
	{
		ss << err;
		cout << ss.str();
	}
};
template <typename T>
class LinkedDequeue
{
public:
	LinkedDequeue() { sz = 0; };
	~LinkedDequeue() {};
	size_t size() const;
	bool empty() const;
	const T& front() const throw(QueueEmpty);
	const T& back() const throw(QueueEmpty);
	bool push_front(const T& elem);
	bool push_back(const T& elem);
	bool pop_front() throw(QueueEmpty);
	bool pop_back() throw(QueueEmpty);
private:
	DLinkedList Deque;
	size_t sz;
};

template<typename T>
inline size_t LinkedDequeue<T>::size() const
{
	return sz;
}

template<typename T>
inline bool LinkedDequeue<T>::empty() const
{
	return (sz == 0);
}

template<typename T>
inline const T & LinkedDequeue<T>::front() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Front of Empty Queue");
	else Deque.front();
}

template<typename T>
inline const T & LinkedDequeue<T>::back() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Back of Empty Queue");
	else return Deque.back();
}

template<typename T>
inline bool LinkedDequeue<T>::push_front(const T & elem)
{
	Deque.addFront(e);
	++sz;
	return true;
}

template<typename T>
inline bool LinkedDequeue<T>::push_back(const T & elem)
{
	Deque.addBack(e);
	++sz;
	return true;
}

template<typename T>
inline bool LinkedDequeue<T>::pop_front() throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Pop from empty Queue");
	Deque.removeFront();
	--sz;
	return true;
}

template<typename T>
inline bool LinkedDequeue<T>::pop_back() throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Pop from empty Queue");
	Deque.removeBack();
	--sz;
	return true;
}

#define _LINKED_QUEUE 1
#endif // !_LINKED_DEQUE 
