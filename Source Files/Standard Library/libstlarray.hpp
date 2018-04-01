#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <array>
#include <list>
#include <algorithm>
#include <numeric>
#include <regex>
using namespace std;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
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
int array()
{
    std::vector<int,90> vec3(87);
    std::array <int,10> intarray;
    std::array <char,12> charray;
    char* str = "Hi There H";
    std::memcpy(charray.data(),str,12);
    /* Memory Copy */
    std::array<int,10> myarray;
    std::array<int, 7> first = {17,22,54,2541,66,33,25};  
    std::array<int, 7> second = {17,22,54,2541,874,44,65};  
    int i = 0;
    myarray.at(i) = i + 1;
    for(const int& x : myarray) std::cout << " " << x;
    myarray.fill(900);
    cout << myarray.size() << "\n";
    myarray.front() = 17;
    myarray.back() = 90;
    auto it = myarray.begin();
    auto const_iter = myarray.cbegin();
    /* Reverse print */
    for(auto rit = myarray.rend(); rit < myarray.rend(); ++rit)
        std::cout << "  " << *rit;
    first.swap(second);
    bool is_empty = first.empty();
    bool is_last_empty = second.empty();
    cout << first.max_size() << second.max_size() << charray.size();
    return 0;
}