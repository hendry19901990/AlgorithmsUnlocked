#ifndef _PRIORITY_QUEUE

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
/* Generic Comparator */
template <typename _class_type>
class comapare
{
public:
	bool operator()(const _class_type& first, const _class_type& second) {
		return (first.length() <= second.length());
	}
};

/* Visualizing an array/vector as a complete binary Tree */
template <typename object>
class Tree
{
private:
	std::vector<object> tree;
	comapare<object> comp;
public:
	/* We can directly get the pointer to the element needed. Not just the index */
	typedef typename std::vector<object>::iterator Pointer;
	Tree() : tree(1) {}
	size_t size() const;
	Pointer left_child(const Pointer& curr);
	Pointer right_child(const Pointer& curr);
	Pointer parent(const Pointer& curr);
	bool hasLeft(const Pointer& curr);
	bool hasRight(const Pointer& curr);
	bool isRoot(const Pointer& curr);
	Pointer root();
	Pointer last();
	bool add_back(const object& elem);
	bool remove_back();
	bool swap(const Pointer& first, const Pointer& sec);
protected:
	Pointer pointer(size_t pos)
	{
		return tree.begin() + pos;
	}
	size_t index(const Pointer& pos)
	{
		return pos - tree.begin();
	}
};

template<typename object>
inline size_t Tree<object>::size() const
{
	return tree.size() - 1;
}

template<typename object>
inline typename Tree<object>::Pointer Tree<object>::left_child(const Pointer & curr)
{
	return pointer(2 * index(curr));
}

template<typename object>
inline typename Tree<object>::Pointer Tree<object>::right_child(const Pointer & curr)
{
	return pointer(2 * index(curr) + 1);
}

template<typename object>
inline typename Tree<object>::Pointer Tree<object>::parent(const Pointer & curr)
{
	return pointer(index(curr) / 2);
}

template<typename object>
inline bool Tree<object>::hasLeft(const Pointer & curr)
{
	return (2 * index(curr) <= size());
}

template<typename object>
inline bool Tree<object>::hasRight(const Pointer & curr)
{
	return ((2 * index(curr) + 1) <= size());
}

template<typename object>
inline bool Tree<object>::isRoot(const Pointer & curr)
{
	return (index(curr) == 1);
}

template<typename object>
inline typename Tree<object>::Pointer Tree<object>::root()
{
	return pointer(1);
}

template<typename object>
inline typename Tree<object>::Pointer Tree<object>::last()
{
	return pointer(size());
}

template<typename object>
inline bool Tree<object>::add_back(const object & elem)
{
	tree.push_back(elem);
	return true;
}

template<typename object>
inline bool Tree<object>::remove_back()
{
	tree.pop_back();
	return true;
}
template<typename object>
inline bool Tree<object>::swap(const Pointer & first, const Pointer & sec)
{
	object temp = *first;
	*first = *sec;
	*sec = temp;
	return true;
}
/* Priority Queue :: Heap as a complete tree on a vector*/
template <typename object, typename compare>
class PriorityQueue
{
public:
	typedef typename Tree<object>::Pointer Pointer;
	size_t size();
	bool empty() const;
	bool heap_insert(const object& obj);
	bool Build_Heap();
	bool full_heapify();
	const object& get_min_elem();
	bool extract_min();
private:
	Tree<object> priorityQueue;
	comapare<object> compObj;
};

template<typename object, typename compare>
inline size_t PriorityQueue<object, compare>::size()
{
	return priorityQueue.size();
}

template<typename object, typename compare>
inline bool PriorityQueue<object, compare>::empty() const
{
	return (size() == 0);
}

template<typename object, typename compare>
inline bool PriorityQueue<object, compare>::heap_insert(const object & obj)
{
	priorityQueue.add_back(obj);
	Build_Heap();
	full_heapify();
	return true;
}

template<typename object, typename compare>
inline bool PriorityQueue<object, compare>::Build_Heap()
{
	/* Compare with parent as we move up and see if heap property is maintained.*/
	typename PriorityQueue<object, compare>::Pointer v = priorityQueue.last();
	while (!priorityQueue.isRoot(v))
	{
		typename PriorityQueue<object, compare>::Pointer u = priorityQueue.parent(v);
		if (!compObj(*v, *u)) break;
		else priorityQueue.swap(v, u);
		v = u;
	}
	return true;
}

template<typename object, typename compare>
inline bool PriorityQueue<object, compare>::full_heapify()
{
	/* Only one level heapify */
	/* We may never use heapify cause build_heap() is better. */
	typename PriorityQueue<object, compare>::Pointer root = priorityQueue.root();
	while (priorityQueue.hasLeft(root))
	{
		/*While there is a right and left child and left is less than right*/
		typename PriorityQueue<object, compare>::Pointer left = priorityQueue.left_child(root);
		typename PriorityQueue<object, compare>::Pointer right = priorityQueue.right_child(root); /*If it has one*/
		if (priorityQueue.hasRight(root) && compObj(*right, *left))
			left = priorityQueue.right_child(root);
		if (compObj(*left, *root)) {
			priorityQueue.swap(root, left);
			root = left;
		}
		else break;
	}
	return true;
}

template<typename object, typename compare>
inline const object & PriorityQueue<object, compare>::get_min_elem()
{
	return *(priorityQueue.root());
}

template<typename object, typename compare>
inline bool PriorityQueue<object, compare>::extract_min()
{
	/*If there is only one element, we remove it.*/
	if (size() == 1) priorityQueue.remove_back();
	else
	{
		/* We swap the first and last element. remove the last element and restore heap property*/
		typename PriorityQueue<object, compare>::Pointer first = priorityQueue.root();
		priorityQueue.swap(first, priorityQueue.last());
		priorityQueue.remove_back();
		full_heapify();
	}
	return false;
}


#define _PRIORITY_QUEUE 1
#endif
/*
int main()
{
	// Need to change the compare function accordingly
	PriorityQueue<string, comapare<string> > q;
	q.heap_insert("Hi There");
	q.heap_insert("Hi");
	q.heap_insert("There");
	q.heap_insert("Sumit");
	q.heap_insert("is a");
	q.heap_insert("good");
	q.heap_insert("boy");
	q.heap_insert("Hello");
	q.heap_insert("I am here");
	q.heap_insert("Okay go away");
	stringstream ss;
	for (auto i = 5; i > 0; i--)
	{
		string s = q.get_min_elem();
		q.extract_min();
		ss << s;
		cout << ss.str() << std::endl;
		ss.str("");
	}
	return 0;
}
*/
