#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <string>
#include <sstream>
#include <memory>
#include <map>
#include <stdexcept>
#include "LinkedList.hpp"
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
class StackEmpty : public RuntimeException{
public:
    std::stringstream ss;
    StackEmpty(const string& err) : RuntimeException(err)
    {
        ss << err;
        cout << ss.str();
    }
};
class StackFull : public RuntimeException{
public:
    std::stringstream ss;
    StackFull(const string& err) : RuntimeException(err)
    {
        ss << err;
        cout << ss.str();
    }
};
/* Using the Linked List previously defined */
template <typename T>
class LinkedStack
{
public:
    LinkedStack();
    size_t size() const;
    bool empty() const;
    const T& top() const throw(StackEmpty);
    bool push(const T& elem);
    bool pop(const T& elem) throw(StackEmpty);
private:
    linkedlist<T> stack;
    size_t num;
};

template <typename T>
LinkedStack<T>::LinkedStack() : S(), num(0) 
{

}
template <typename T>
size_t LinkedStack<T>::size() const
{
    return num;
}
template <typename T>
bool LinkedStack<T>::empty() const
{
    return (num==0);
}
template <typename T>
const T& LinkedStack<T>::top() const throw(StackEmpty)
{
    if(empty()) throw StackEmpty("Top of Empty Stack");
    else return stack.front();
}
template <typename T>
bool LinkedStack<T>::push(const T& elem)
{
    ++num;
    stack.addFront(elem);
}
template <typename T>
bool LinkedStack<T>::pop(const T& elem) throw(StackEmpty)
{
    if(empty()) throw StackEmpty("Pop from Empty Stack");
    else
    {
        --num;
        stack.removeFront(elem);
    }    
}
