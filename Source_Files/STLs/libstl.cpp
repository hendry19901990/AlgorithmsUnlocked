#include <bits/stdc++.h>
#include <thread>
#include <vector>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <array>
#include <map>
#include <list>
#include <deque>
#include <bitset>
#include <queue>
#include <forward_list>
#include <set>
#include <algorithm>
#include <future>
#include <initializer_list>
#include <mutex>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <pthread.h>
using namespace std;
/* Global list typedefs*/
typedef std::list<int> DLinkedList;
typedef std::list<int>::const_iterator list_const_iter;
typedef std::list<int>::iterator list_iterator;
/* Global Shared */   
DLinkedList shared_list;   
/* In order to have race conditions, threads should access shared resource as randomly as possible */
void access_thread_global(int u)
{
    list_iterator iter;
    iter = shared_list.begin();
    for(auto i = 0; i < 20; i++)
    {
        *iter = u * i;
        ++iter;
    }

}       
int main()
{
    DLinkedList mylist;
    list_iterator iter, share_iter;
    iter = mylist.begin();
    share_iter = shared_list.begin();
    for(auto i = 0; i < 20; i++){
        mylist.push_back(i*10);
        shared_list.push_back(i*i);
    }
    std::thread first (access_thread_global,10);
    std::thread second (access_thread_global,100);
    // pauses until first finishes
    second.join();  
    first.join();               // pauses until second finishes
    for(auto i = 0; i < 20; i++)
    {
       // ++iter; 
        ++share_iter;
       // cout << *iter << endl;
        cout << *share_iter << endl;
    }

}