#ifndef _ARRAY_VECTOR

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
	T elem[];
	T* elem_pointer;
	size_t capacity;
	size_t size;
	size_t MAX_CAP;
public:
	inline bool isEmpty() noexcept;
	inline void size() noexcept;
	inline void max_size() noexcept;
	inline bool isFullCapacity() noexcept;
	inline bool isResizeAble() noexcept;
	ArrayVector(size_t) noexcept;
	ArrayVector(size_t, T);
	ArrayVector();
	~ArrayVector()
	{
		delete elem_pointer;
		capacity = 0;
		size = 0;
		MAX_CAP = 0;
	}
	void dynamic_allocator(size_t);
	void insertBack(const T&);
	void insertFront(const T&);
	void deleteBack();
	void deleteFront();
	void insertAt();
	void operator[] ();
	void operator* ();
};

template<typename T>
inline bool ArrayVector<T>::isEmpty() noexcept
{
	return false;
}

template<typename T>
inline void ArrayVector<T>::size() noexcept
{

}

template<typename T>
inline void ArrayVector<T>::max_size() noexcept
{

}

template<typename T>
inline bool ArrayVector<T>::isFullCapacity() noexcept
{
	return false;
}

template<typename T>
inline bool ArrayVector<T>::isResizeAble() noexcept
{
	return false;
}

template<typename T>
ArrayVector<T>::ArrayVector(size_t N) noexcept
{

}

template<typename T>
ArrayVector<T>::ArrayVector(size_t, T)
{

}

template<typename T>
ArrayVector<T>::ArrayVector()
{

}

template<typename T>
void ArrayVector<T>::dynamic_allocator(size_t)
{

}

template<typename T>
void ArrayVector<T>::insertBack(const T &)
{

}

template<typename T>
void ArrayVector<T>::insertFront(const T &)
{

}

template<typename T>
void ArrayVector<T>::deleteBack()
{

}

template<typename T>
void ArrayVector<T>::deleteFront()
{

}

template<typename T>
void ArrayVector<T>::insertAt()
{

}

template<typename T>
void ArrayVector<T>::operator[]()
{

}

template<typename T>
void ArrayVector<T>::operator*()
{

}


#define _ARRAY_VECTOR 1
#endif // !_ARRAY_VECTOR
