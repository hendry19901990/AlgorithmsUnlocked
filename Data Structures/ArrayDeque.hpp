#ifndef _ARRAY_DEQUEUE

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <sstream>
#include <cstring>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
/*
Dequeue implemented in a circular array.
front = (front + 1) modulo N --> front deletion (a.k.a pop_front/dequeue)
rear = (rear + 1) modulo N --> rear addition (a.k.a push_back/enqueue)
front = (front - 1) modulo N --> front addition (a.k.a push_front)
rear = (rear - 1) modulo N --> rear deletion (a.k.a pop_back)
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
class ArrayDequeue
{
public:
	ArrayDequeue();
	ArrayDequeue(size_t cap, T& elem);
	~ArrayDequeue();
	ArrayDequeue& operator= (ArrayDequeue&&);
	ArrayDequeue(ArrayDequeue&&);
	size_t size() const;
	bool empty() const;
	const T& Front() const throw(QueueEmpty);
	const T& Rear() const throw(QueueEmpty);
	bool push_front(const T& elem) throw(QueueFull);
	bool pop_back() throw(QueueEmpty);
	bool push_back(const T& elem) throw(QueueFull);
	bool pop_front() throw(QueueEmpty);
	bool allocator(size_t newcap) noexcept;
private:
	T * Queue;
	size_t sz;
	size_t capacity;
	size_t front, rear;
	size_t t_front, t_rear;
};

template<typename T>
inline ArrayDequeue<T>::ArrayDequeue()
{
	Queue = new T[40];
	std::memcpy(Queue, 0, sizeof(T));
	front = rear = 0;
	t_front = t_rear = capacity = 40;
	sz = 0;
}

template<typename T>
inline ArrayDequeue<T>::ArrayDequeue(size_t cap, T& elem)
{
	Queue = new T[cap + 1];
	std::memcpy(Queue, elem, sizeof(T));
	t_front = t_rear = capacity = cap;
	front = rear = 0;
	sz = 0;
}

template<typename T>
inline ArrayDequeue<T>::~ArrayDequeue()
{
	delete[] Queue;
}

template<typename T>
inline ArrayDequeue<T>& ArrayDequeue<T>::operator=(ArrayDequeue && que)
{
	this->Queue = que.Queue;
	this->sz = que.sz;
	this->capacity = que.capacity;
	delete[] que.Queue;
	return *this;
}

template<typename T>
inline ArrayDequeue<T>::ArrayDequeue(ArrayDequeue && que)
{
	this->Queue = que.Queue;
	this->sz = que.sz;
	this->capacity = que.capacity;
	delete[] que.Queue;
}

template<typename T>
inline size_t ArrayDequeue<T>::size() const
{
	return sz;
}

template<typename T>
inline bool ArrayDequeue<T>::empty() const
{
	return (sz == 0);
}

template<typename T>
inline const T & ArrayDequeue<T>::Front() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Queue is Empty");
	else return Queue[front];
}

template<typename T>
inline const T & ArrayDequeue<T>::Rear() const throw(QueueEmpty)
{
	if (empty()) throw QueueEmpty("Rear of empty Queue");
	else return Queue[rear];
}

template<typename T>
inline bool ArrayDequeue<T>::push_front(const T & elem) throw(QueueFull)
{
	front = (front - 1) % capacity;
	if ((front >= capacity) || (sz == capacity))
	{
		throw QueueFull("Cannot insert at the front now.");
	}
	else
	{
		if (front < 0)
		{
			front = 0;
			Queue[front] = elem;
			++sz;
		}
		else
		{
			Queue[front] = elem;
			++sz;
		}
	}
	return true;
}

template<typename T>
inline bool ArrayDequeue<T>::pop_back() throw(QueueEmpty)
{
	if (sz == 0) throw QueueEmpty("Pop back from empty queue");
	Queue[rear] = -1;
	rear = (rear - 1);
	if (rear <= front)
	{
		front = rear = 0;
	}
	--sz;
	return true;
}

template<typename T>
inline bool ArrayDequeue<T>::push_back(const T & elem) throw(QueueFull)
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
inline bool ArrayDequeue<T>::pop_front() throw(QueueEmpty)
{
	if (sz == 0) throw QueueEmpty("Pop back from empty queue");
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
inline bool ArrayDequeue<T>::allocator(size_t newcap) noexcept
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

#define _ARRAY_DEQUEUE 1
#endif // !_ARRAY_DEQUEUE
