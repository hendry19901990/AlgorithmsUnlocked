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
template<typename T>
class listnode
{
public : 
    listnode(const T& elem) : node(elem), next(new listnode) {}
    ~listnode() {}
    listnode() {}
    void operator=(const listnode<T>&);
    T node;
    listnode* next;
};
template<typename T>
class CircularLinkedList : public listnode<T>
{
    
};