#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <queue>
#include <deque>
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
    std::queue<char, vector<char> > char_stack;
    std::queue<string> myqueue;
    myqueue.emplace("First Sentence");
    myqueue.emplace("Second Sentence");
    while(!myqueue.empty())
    {
        cout << myqueue.back() << myqueue.front() << endl;
        myqueue.pop();
    }
    string str = "Ho jjfoljdhsnf";
    myqueue.push(str);
    cout << myqueue.size() << endl;
    std::queue<int> foo, bar;
    foo.push(1005); /* At back */
    foo.push(5545);
    foo.push(8744);
    foo.pop();      /* At Front of Queue */
    bar.push(885474);
    bar.push(i);
    bar.push(j);
    swap(foo, bar);
    bar.swap(foo);
    /* template<class T, class Container = deque<T> > class queue */
} 
void double_queue()
{ /* All other functions as that for stl vector class */
    std::deque<int> mydeque (2, 1500);
    mydeque.push_front(54114);
    mydeque.push_back(8455);
    mydeque.pop_front();
    mydeque.pop_back();
}