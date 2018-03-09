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
     * which in turn is int*/
}
