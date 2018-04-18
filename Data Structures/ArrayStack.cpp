#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <stdexcept>
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
    StackEmpty(const string& err) : RuntimeException(err)
    {
        printf("%s\n", err);
    }
};
class StackFull : public RuntimeException{
public:
    StackFull(const string& err) : RuntimeException(err)
    {
        printf("%s\n", err);
    }
};
template <typename T>
class ArrayStack
{
    enum { DEF_CAPACITY = 100 };
public :
    ArrayStack(int capacity = DEF_CAPACITY);
    int size() const noexcept;
    bool empty() const noexcept;
    const T& top() const throw(StackEmpty);
    void push(const T& elem) throw(StackFull);
    void pop() throw(StackEmpty);
private :
    T* stack;
    int capacity;
    int topelem; /*Top*/
};
template <typename T> ArrayStack<T> :: ArrayStack(int capacity) :
    stack (new T[capacity]), capacity(capacity), topelem(-1) {

}
template <typename T> int ArrayStack<T> :: size() const noexcept 
{
    return (topelem + 1);
}
template <typename T> bool ArrayStack<T> :: empty() const noexcept
{
    return (topelem < 0);
}
template <typename T> const T& ArrayStack<T> :: top() const throw(StackEmpty){
    if (empty() ) throw StackEmpty("Top of Empty Stack");
    else return stack[topelem];
}
template <typename T> void ArrayStack<T> :: push(const T& elem) throw(StackFull)
{
    if(size() == capacity) throw StackFull("Stack is full.");
    else stack[++topelem] = elem;
}
template <typename T> void ArrayStack<T> :: pop() throw(StackEmpty) 
{
    if(empty()) throw StackEmpty("Pop from empty stack");
    --topelem;
}
int main()
{
    ArrayStack<int> intstack;
    intstack.pop();
}
