#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <regex>
using namespace std;
/* Value type to typename */
/**
 * We say X is a container type such as vector<int> list<int> vector<string> etc.
 * X::value_type                Type T, element type
 * X::reference                 T & refernce to an element of type T.
 * X::const_reference           const T& a const refernce to an element of type T.
 * X::iterator                  iterator type pointing to T, behves like type T*. Basically a pointer to T.
 * X::const_iterator            iterator type pointing to const T. behaves like a const T*
 * X::difference_type           Like a signed interger that tells the distance from one iterator to the other iterator. 
 * X::size_type                 Size of data objects. Unsigned int.
 * */
typedef vector<int>::value_type valtype;
typedef vector<int>::reference VecRef;
typedef vector<int>::const_reference  constVecRef;
typedef vector<int>::iterator  genericIter;
typedef vector<int>::reverse_iterator  RevIter;
typedef vector<int>::const_iterator VecConstIter;
typedef vector<int>::difference_type difftyp;
typedef vector<int>::size_type VecSize;

template<typename Bag>
typename Bag::value_type min(const Bag& b)
{
    typename Bag::const_iterator it;
    typename Bag::value_type val = *b.begin();
    for(it = b.begin(); it != b.end(); ++it)
    {
        if(*it < val)
        {
            val = *it;
        }
    }
    return val;
}
int main(int argc, char *argv[])
{
    vector<int> temperatures;
    int coldest = min(temperatures);
    /** 
    * The temparature parameter will cause Bag to be evaluated as vector<int> 
    * and typename Bag::value_type to be evaluated as vector<int>::value_type 
    * which in turn is int
    * */
    valtype a; /* __typeid(int) */
    genericIter iter = temperatures.begin();
    RevIter last = temperatures.rbegin();
    



}
