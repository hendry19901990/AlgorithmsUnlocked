#include <iostream>
#include <ioevent.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string.h>
#include <algorithm>
#include <stdexcpt.h>
#include <numeric>
#define SIZE 1024
#define MAX_SIZE 40960
#define for(n) for(auto i = 0; i < n; i++)
#define for(n-1) for(auto i = 0; i < n; i++)
using namespace std;

/*Sorting Class*/
template <typename Elem, class Container = deque<Elem> >
class Sort
{
	Container conatiner;
	Elem array[];
	Elem* pointer;
	Elem& ref;
	size_t capacity;
	size_t MAX;
	Elem* front;
	Elem* rear;
public:
	inline bool isEmpty() noexcept;
	inline void size() noexcept;
	inline void max_size() noexcept;
	inline bool isFullCapacity() noexcept;
	inline bool isResizeAble() noexcept;
	Sort(size_t) noexcept;
	Sort(size_t, T);
	explicit Sort();
	~Sort()
	{
		delete pointer;
		capacity = 0;
		MAX = 0;
	}
	void dynamic_allocator(size_t);
	void insertBack(const Elem&);
	void insertFront(const Elem&);
	void deleteBack();
	void deleteFront();
	void insertAt();
	void operator[] ();
	void operator* ();
};
template<typename Elem>
class SortOperations : public Sort <Elem,Container>
{
	Elem Buffer[];
	static int Count;
	static int Compare;
	static int Inversions;
public:
	void bubbleSortOperation();
	void InsertionSortOperation();
	void SelectionSortOperation();
	void MergeSortOperation();
	void HeapSortOperation();
	void BinaryInsertionSort();
	void OptBubbleSort();
	void QuickSortOperation();
	void SystemSort();
	void WaveSortOperation();
	void RecursiveSortOperation();
	inline bool isSorted();
};

template<typename Elem, class Container>
inline bool Sort<Elem, Container>::isEmpty() noexcept
{
	return false;
}

template<typename Elem, class Container>
inline void Sort<Elem, Container>::size() noexcept
{

}

template<typename Elem, class Container>
inline void Sort<Elem, Container>::max_size() noexcept
{

}

template<typename Elem, class Container>
inline bool Sort<Elem, Container>::isFullCapacity() noexcept
{
	return false;
}

template<typename Elem, class Container>
inline bool Sort<Elem, Container>::isResizeAble() noexcept
{
	return false;
}

template<typename Elem, class Container>
Sort<Elem, Container>::Sort(size_t) noexcept
{

}

template<typename Elem, class Container>
Sort<Elem, Container>::Sort(size_t, T)
{

}

template<typename Elem, class Container>
Sort<Elem, Container>::Sort()
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::dynamic_allocator(size_t)
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::insertBack(const Elem &)
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::insertFront(const Elem &)
{
	
}

template<typename Elem, class Container>
void Sort<Elem, Container>::deleteBack()
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::deleteFront()
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::insertAt()
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::operator[]()
{

}

template<typename Elem, class Container>
void Sort<Elem, Container>::operator*()
{

}

template<typename Elem>
void SortOperations<Elem>::bubbleSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::InsertionSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::SelectionSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::MergeSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::HeapSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::BinaryInsertionSort()
{

}

template<typename Elem>
void SortOperations<Elem>::OptBubbleSort()
{

}

template<typename Elem>
void SortOperations<Elem>::QuickSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::SystemSort()
{

}

template<typename Elem>
void SortOperations<Elem>::WaveSortOperation()
{

}

template<typename Elem>
void SortOperations<Elem>::RecursiveSortOperation()
{

}

template<typename Elem>
inline bool SortOperations<Elem>::isSorted()
{
	return false;
}
