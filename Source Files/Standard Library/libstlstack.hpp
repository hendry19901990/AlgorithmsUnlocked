#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <stack>
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
void func_stack_run()
{
    int i = 90, j = 87;
    std::stack<char, vector<char> > char_stack;
    std::stack<string> mystack;
    mystack.emplace("First Sentence");
    mystack.emplace("Second Sentence");
    while(!mystack.empty())
    {
        cout << mystack.top() << endl;
        mystack.pop();
    }
    string str = "Ho jjfoljdhsnf";
    mystack.push(str);
    cout << mystack.size() << endl;
    std::stack<int> foo, bar;
    foo.push(1005);
    foo.push(5545);
    foo.push(8744);
    foo.pop();
    bar.push(885474);
    bar.push(i);
    bar.push(j);
    swap(foo, bar);
    /* template<class T, class Container = deque<T> > class stack */
} 