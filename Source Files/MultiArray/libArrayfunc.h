#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#define MAX_LIMIT_SZ 2048
using namespace std;
template<typename T,size_t size, char c> class Arraytype{
    T array[size];
public: 
    T& operator[](size_t t);
    void* operator new(size_t p);
    Arraytype operator()(char j,int p);
    T& operator+(int i);
    T& operator<<(int j);
};
template<typename T,size_t size, char c>
T& Arraytype<T,size,c> :: operator[](size_t p)
{

}
int runMethodArrays()
{
    return 0;
}