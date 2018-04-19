#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
#include <stdexcept>
using namespace std;
template<typename T>
class listnode
{
public: 
    listnode(const T& elem) : node(elem), next(new listnode) {}
    ~listnode() {}
    listnode() {}
    void operator=(const listnode<T>&);
    listnode* next;
private:
    T node;
};
template<typename T>
void listnode<T> :: operator=(const listnode<T>& temp)
{
    this -> node = temp -> node;
    this -> next = temp -> next;
}
template <typename T>
class linkedlist
{
public : 
    linkedlist();
    linkedlist(const T& elem);
    void front() const;
    void addFront(const T& elem) noexcept;
    void relocate() noexcept;
    void addBack(const T& elem) noexcept;
    void addAt(const int& pos, const T& elem) noexcept;
    void operator=(const listnode<T>&) noexcept;
    void removeFront() noexcept;
    void removeBack() noexcept;
    void printnodes() noexcept;
    void removeNode(const int& pos) noexcept;
private :
    listnode<T>* head;
    listnode<T>* tail;
    int count;
};
template <typename T>
void linkedlist<T>::front() const
{
    return head->next->node;
}
template<typename T>
void linkedlist<T> :: operator=(const listnode<T>& temp) noexcept
{
    this -> node = temp -> node;
    this -> next = temp -> next;
}
template <typename T> 
linkedlist<T> :: linkedlist() : head(new listnode<T>), tail(new listnode<T>), count(0)
{
    head->next = nullptr;
    tail = head;
    tail->next = nullptr;
}
template <typename T> 
linkedlist<T> :: linkedlist(const T& elem) : head(new listnode<T>), tail(new listnode<T>), count(0) 
{
    head->node = elem;
    head->next = nullptr;
    relocate();
}
template <typename T> 
void linkedlist<T> :: addFront(const T& elem) noexcept
{
    listnode<T>* front = new listnode<T>;
    front->node = elem;
    front->next = head;
    head = front;
}
template <typename T> 
void linkedlist<T> :: addAt(const int& pos, const T& elem) noexcept
{
    count = 1;
    listnode<T>* temp = new listnode<T>;
    listnode<T>* add = new listnode<T>;
    add -> node = elem;
    add -> next = nullptr;
    temp = head;
    while(count != pos - 1)
    {
        temp = temp -> next;
        count++;
    }
    add -> next = temp -> next;
    temp -> next = add;
}
template <typename T> 
void linkedlist<T> :: removeNode(const int& pos) noexcept
{
    count = 1;
    listnode<T>* temp = new listnode<T>;
    temp = head;
    while(count != pos - 1)
    {
        temp = temp -> next;
        count++;
    }
    temp -> next = temp -> next -> next;
}
template <typename T> 
void linkedlist<T> :: removeBack() noexcept
{
    count = 1;
    listnode<T>* temp = new listnode<T>;
    temp = head;
    while(temp -> next -> next != nullptr)
    {
        temp = temp -> next;
    }
    temp -> next = nullptr;
}
template <typename T> 
void linkedlist<T> :: relocate() noexcept
{
    listnode<T>* temp = new listnode<T>;
    temp = head;
    while(temp -> next != nullptr)
    {
        temp = temp -> next;
    }
    tail = temp;
    tail -> next = nullptr;
}
template <typename T> 
void linkedlist<T> :: printnodes() noexcept
{
    listnode<T>* temp = new listnode<T>;
    temp = head;
    while(temp -> next != nullptr)
    {
        cout << temp -> node << "->" ;
        temp = temp -> next;
    }
    cout << endl;
}
template <typename T> 
void linkedlist<T> :: addBack(const T& elem) noexcept
{
    relocate();
    listnode<T>* back = new listnode<T>;
    back->node = elem;
    back->next = nullptr;
    tail->next = back;
    tail = back;
}
void linkedlist_func()
{
    linkedlist<int> list;
    for(auto i = 0; i < 30; i++)
    {
        list.addBack(i + 1);
    }
    list.addAt(10, 87);
    list.removeNode(9);
    list.removeNode(19);
    list.removeBack();
    list.removeBack();
    list.printnodes();
}