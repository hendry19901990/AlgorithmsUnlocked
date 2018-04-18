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
class arrayDeque
{
    size_t size;
    _type* circle;
    size_t capacity;
public:
    arrayDeque(size_t size, size_t cap);
    arrayDeque(arrayDeque&&);
    arrayDeque& operator= (arrayDeque&&);
    _type operator[] (size_t index) const noexcept {return circle[index];}
    ~arrayDeque() noexcept { delete[] circle;}
    void reserve(size_t cap);
    void pushback(_type t);
    void popback(_type t);
    void pushfront(_type t);
    void popfront(_type t);
};
