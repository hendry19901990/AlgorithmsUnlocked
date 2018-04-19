#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <sstream>
#include <math.h>
#include <vector>
#include <map>
#include <memory>
#include "CircularList.hpp"
#include <stdexcept>
/*A queue using a circular linked list*/
using namespace std;
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
class LinkedQueue
{
public:
	LinkedQueue() {}
	~LinkedQueue() {}
	size_t size() const;
	bool empty() const;
	const T& front() const throw(QueueEmpty);
	bool enqueue(const T& elem);
	bool dequeue() throw(QueueEmpty);
private:
	CircularList<T> Queue;
	size_t size;
	size_t capacity;
};

template<typename T>
inline size_t LinkedQueue<T>::size() const
{
	return size;
}

template<typename T>
inline bool LinkedQueue<T>::empty() const
{
	return (size == 0);
}

template<typename T>
inline const T & LinkedQueue<T>::front() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Front of Empty Queue");
	else return Queue.front();
}

template<typename T>
inline bool LinkedQueue<T>::enqueue(const T & elem)
{
	Queue.add(elem);
	Queue.advance();
	++size;
	return true
}

template<typename T>
inline bool LinkedQueue<T>::dequeue() throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Deque of Empty Queue");
	Queue.remove();
	--size;
	return true;
}
