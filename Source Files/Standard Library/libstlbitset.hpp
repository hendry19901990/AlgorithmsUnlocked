#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <string.h>
#include <bitset>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
void func_bit_set()
{
    /* std::vector<bool> boolvec --> dynamically resizeable */
    std::bitset<8> bar(std::string("10110010"));
    std::bitset<10> foo(std::string("8541225477"));
    auto is_all_set = foo.set();
    auto is_any_bit_set = foo.any();
    auto setbits = foo.count();
    auto size = foo.size();
    foo.flip(8);
    foo.flip();
    auto is_none_set = foo.none();
    cout << foo[3] << endl;
    int pos = 9, value = 8;
    foo.reset(pos);
    foo.reset();
    foo.set(pos, value);
    auto is_set_bit_pos = foo.test(pos);
    cout << foo.to_string() << endl;
    cout << foo.to_ulong() << endl;
    cout << foo.to_ullong() << endl;
} 