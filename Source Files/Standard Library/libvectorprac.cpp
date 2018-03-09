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
typedef vector<int>::value_type value_type;
typedef vector<int>::reference VectorReference;
typedef vector<int>::const_reference  constVectorReferenece;
typedef vector<int>::iterator  iterator;
typedef vector<int>::reverse_iterator  reverse_iterator;
typedef vector<int>::const_iterator constVectorIterator;
typedef vector<int>::difference_type difference_type;
typedef vector<int>::size_type size_type;

int main()
{
    return 0;
}