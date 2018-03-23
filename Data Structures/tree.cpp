#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
template<typename T>
class node
{
    vector<T> elem;
    int index;
public:
    explicit node();
    node(size_t, int);
    inline void printnode();
    inline void updatenode(int);
    inline T& operator[](size_t i) const {return elem[i];}
    inline bool operator==(const T& lhs){ return memcmp(lhs,this->elem) == 0; }
    ~node();
};
template<typename T> node<T>::node() : elem(vector<T>(80)), index(0) {}
template<typename T> node<T>::node(size_t N, int a) : elem(vector<T>(N)), index(a) {}
template<typename T> node<T>::~node() { delete elem; index = -1;}
template<typename T> inline void node<T>::printnode()
{
    for(const auto &i : elem)
    {
        cout << i << ",";
    }
}
template<typename T> inline void node<T>::updatenode(int i)
{
    this->index = i;
}
template<typename T>
std::ostream& operator<<(std::ostream& out, const node<T>& f)
{
   return out << f.printnode() << endl;
}
int main()
{
    node<int> *treenode = new node<int>;


}
