#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <sstream>
#include <math.h>
#include <vector>
#include <memory>
#include <map>
#include <stdexcept>
using namespace std;
/*Forward Class Defination*/
template <typename _Type> class CircularList;
template <typename T>
class CNode
{
private:
	T elem;
	std::shared_ptr<CNode> next;
	/*Here we are using a freind class to extend the functionalities. */
	friend class CircularList<T>;
public:
	CNode() = default;
	CNode(const T& e) : elem(e), next(std::make_shared<CNode>()) {}
	CNode(CNode&& node)
	{
		/*Use the std::move() func*/
		/* CNode<int> node2 = std::move(node1); */
		this->elem = node.elem;
		this->next = node.next;
	}
	CNode& operator= (CNode&& node)
	{
		/*Use the std::move() func*/
		this->elem = node.elem;
		this->next = node.next;
		return *this;
	}
	~CNode() = default;
};
/*Here we define the Circular Linked List*/
template <typename T>
class CircularList
{
public:
	CircularList() : cursor(std::make_shared<CNode<T> >()) {}
	~CircularList();
	bool empty() const;
	const T& front() const;
	bool advance() noexcept;
	bool add(const T& elem);
	bool remove();
private:
	std::shared_ptr<CNode<T> > cursor;
	size_t size;
};

template<typename T>
inline CircularList<T>::~CircularList()
{
	while (!empty()) remove();
}

template<typename T>
inline bool CircularList<T>::empty() const
{
	return (size == 0);
}

template<typename T>
inline const T & CircularList<T>::front() const
{
	return cursor->next->elem;
}

template<typename T>
inline bool CircularList<T>::advance() noexcept
{
	cursor = cursor->next;
	return true;
}

template<typename T>
inline bool CircularList<T>::add(const T & e)
{
	std::shared_ptr<CNode<T> > temp = std::make_shared<CNode<T> >();
	temp->elem = e;
	if (size == 0)
	{
		/* Entry at the start. New Node	*/
		temp->next = temp;
		cursor = temp;
		return true;
	}
	else
	{
		/* Regular insertion */
		temp->next = cursor->next;
		cursor->next = temp;
		cursor = temp;
		return true;
	}
}

template<typename T>
inline bool CircularList<T>::remove()
{
	std::shared_ptr<CNode<T> > old_ptr_node = cursor->next;
	if (old_ptr_node == cursor)
	{
		cursor = nullptr;
	}
	else
	{
		cursor->next = old_ptr_node->next;
	}
	return true;
}



