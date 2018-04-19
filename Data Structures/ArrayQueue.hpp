#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
template <typename _type>
class arrayQueue
{
    size_t size;
    _type* circle;
    size_t capacity;
public:
    arrayQueue(size_t size, size_t cap);
    arrayQueue(arrayQueue&&);
    arrayQueue& operator= (arrayQueue&&);
    _type operator[] (size_t index) const noexcept {return circle[index];}
    ~arrayQueue() noexcept { delete[] circle;}
    void reserve(size_t cap);
    void pushback(_type t);
    void popfront(_type t);
};