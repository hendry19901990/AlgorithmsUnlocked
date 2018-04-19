#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <cstring>
#include <sstream>
#include <stdexcept>
using namespace std;
/*
Queue implemented in a circular array.
front = (front + 1) modulo N --> front deletion (a.k.a pop_front/dequeue)
rear = (rear + 1) modulo N --> rear addition (a.k.a push_back/enqueue)
*/
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
class QueueFull : public RuntimeException {
public:
	std::stringstream ss;
	QueueFull(const string& err) : RuntimeException(err)
	{
		ss << err;
		cout << ss.str();
	}
};
template <typename T>
class ArrayQueue
{
public:
	ArrayQueue();
	ArrayQueue(size_t cap, T& elem);
	~ArrayQueue();
	ArrayQueue& operator= (ArrayQueue&&);
	ArrayQueue(ArrayQueue&&);
	size_t size() const;
	bool empty() const;
	const T& Front() const throw(QueueEmpty);
	const T& Rear() const throw(QueueEmpty);
	bool enqueue(const T& elem) throw(QueueFull);
	bool dequeue(const T& elem) throw(QueueEmpty);
	bool allocator(size_t newcap) noexcept;
private:
	T * Queue;
	size_t sz;
	size_t capacity;
	size_t front, rear;
};

template<typename T>
inline ArrayQueue<T>::ArrayQueue()
{
	Queue = new T[40];
	std::memcpy(Queue, 0, sizeof(T));
	front = rear = 0;
	sz = 0;
	capacity = 40;
}

template<typename T>
inline ArrayQueue<T>::ArrayQueue(size_t cap, T& elem)
{
	Queue = new T[cap + 1];
	std::memcpy(Queue, elem, sizeof(T));
	capacity = cap;
	front = rear = 0;
	sz = 0;
}

template<typename T>
inline ArrayQueue<T>::~ArrayQueue()
{
	delete[] Queue;
}

template<typename T>
inline ArrayQueue<T>& ArrayQueue<T>::operator=(ArrayQueue && que)
{
	this->Queue = que.Queue;
	this->sz = que.sz;
	this->capacity = que.capacity;
	delete[] que.Queue;
	return *this;
}

template<typename T>
inline ArrayQueue<T>::ArrayQueue(ArrayQueue && que)
{
	this->Queue = que.Queue;
	this->sz = que.sz;
	this->capacity = que.capacity;
	delete[] que.Queue;
}

template<typename T>
inline size_t ArrayQueue<T>::size() const
{
	return sz;
}

template<typename T>
inline bool ArrayQueue<T>::empty() const
{
	return (sz == 0);
}

template<typename T>
inline const T & ArrayQueue<T>::Front() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Queue is Empty");
	else return Queue[front];
}

template<typename T>
inline const T & ArrayQueue<T>::Rear() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Rear of empty Queue");
	else return Queue[rear];
}

template<typename T>
inline bool ArrayQueue<T>::enqueue(const T & elem) throw(QueueFull)
{
	if (sz == capacity) throw QueueFull("Queue is full. Allocate more memory. call allocator()");
	else
	{
		rear = (rear + 1) % capacity;
		Queue[rear] = elem;
		++sz;
	}
	return true;
}

template<typename T>
inline bool ArrayQueue<T>::dequeue(const T & elem) throw(QueueEmpty)
{
	if(sz == 0) throw QueueEmpty("Pop from empty Queue").
	front = (front + 1) % capacity;
	Queue[front] = 0;
	if (front == rear)
	{
		front = rear = 0;
	}
	--sz;
	return true;
}

template<typename T>
inline bool ArrayQueue<T>::allocator(size_t newcap) noexcept
{
	T* B = new T[newcap + 1];
	for (auto i = 0; i < sz; i++)
	{
		B[i] = this->Queue[i];
	}
	if (!Queue) delete[] Queue;
	this->Queue = B;
	capacity = newcap;
	return true;
}

