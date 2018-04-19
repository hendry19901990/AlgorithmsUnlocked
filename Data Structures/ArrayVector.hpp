#ifndef _ARRAY_VECTOR
// extendable Array Implementation
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <memory>
#include <cstring>
#include <sstream>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
template<typename T>
class ArrayVector
{
	T elem[1];
	std::shared_ptr<T> elem_pointer;
	size_t capacity;
	size_t sz;
	size_t MAX_CAP;
public:
	inline bool isEmpty() noexcept;
	inline void size() noexcept;
	inline void max_size() noexcept;
	inline bool isFullCapacity() noexcept;
	inline bool isNotResizeAble() noexcept;
	ArrayVector(size_t);
	ArrayVector(size_t, const T&);
	ArrayVector();
	~ArrayVector() {}
	bool dynamic_allocator(size_t);
	bool insertBack(const T&);
	bool insertFront(const T&);
	bool deleteBack();
	bool deleteFront();
	bool insertAt(size_t, const T&);
	T operator[] (size_t);
	shared_ptr<T> operator* ();
};

template<typename T>
inline bool ArrayVector<T>::isEmpty() noexcept
{
	return (sz == 0);
}

template<typename T>
inline void ArrayVector<T>::size() noexcept
{
	return sz;
}

template<typename T>
inline void ArrayVector<T>::max_size() noexcept
{
	return MAX_CAP;
}

template<typename T>
inline bool ArrayVector<T>::isFullCapacity() noexcept
{
	return (sz == MAX_CAP);
}

template<typename T>
inline bool ArrayVector<T>::isNotResizeAble() noexcept
{
	return (capacity == MAX_CAP);
}

template<typename T>
inline ArrayVector<T>::ArrayVector(size_t N) : capacity(N), sz(0), elem_pointer(nullptr), elem(new T[N + 1])
{
	MAX_CAP = 819200;
}

template<typename T>
inline ArrayVector<T>::ArrayVector(size_t num, const T& ez) : capacity(num), sz(0), elem_pointer(nullptr)
{
	elem = new T[num + 1];
	for (auto j = 0; j < num; j++)
	{
		elem[j] = ez;
	}
	MAX_CAP = 819200;
}

template<typename T>
inline ArrayVector<T>::ArrayVector() : capacity(0), sz(0), elem_pointer(nullptr), elem(NULL)
{
	MAX_CAP = 819200;
}

template<typename T>
inline bool ArrayVector<T>::dynamic_allocator(size_t N)
{
	if (N > MAX_CAP) return false;
	T* B = new T[N + 1];
	for (auto j = 0; j < sz; j++)
	{
		B[j] = elem[j];
	}
	if (elem != NULL) delete[] elem;
	this->elem = B;
	capacity = N;
	return true;
}

template<typename T>
inline bool ArrayVector<T>::insertBack(const T & ez)
{
	if (sz >= capacity)
	{
		this->dynamic_allocator(max(1, 2 * capacity));
	}
	elem[sz + 1] = ez;
	++sz;
	return true;
}

template<typename T>
inline bool ArrayVector<T>::insertFront(const T & ez)
{
	if (sz >= capacity)
	{
		this->dynamic_allocator(max(1, 2 * capacity));
	}
	for (auto j = sz - 1; j >= 0; j--)
	{
		elem[j + 1] = elem[j];
	}
	elem[0] = ez;
	++sz;
	return true;
}

template<typename T>
inline bool ArrayVector<T>::deleteBack()
{
	elem[sz] = -1;
	--sz;
	return true;
}

template<typename T>
inline bool ArrayVector<T>::deleteFront()
{
	for (auto j = 1; j <= sz; j++)
	{
		elem[j - 1] = elem[j];
	}
	this->deleteBack();
}

template<typename T>
inline bool ArrayVector<T>::insertAt(size_t pos, const T& ez)
{
	if (sz >= capacity)
	{
		this->dynamic_allocator(max(1, 2 * capacity));
	}
	for (auto j = sz - 1; j >= pos; j--)
	{
		elem[j + 1] = elem[j];
	}
	elem[pos] = ez;
	++sz;
	return true;
}

template<typename T>
T ArrayVector<T>::operator[](size_t pos)
{
	return this->elem[pos];
}

template<typename T>
std::shared_ptr<T> ArrayVector<T>::operator*()
{
	elem_pointer = std::make_shared<T>();
	elem_pointer = elem;
	return elem_pointer;
}


#define _ARRAY_VECTOR 1
#endif // !_ARRAY_VECTOR
