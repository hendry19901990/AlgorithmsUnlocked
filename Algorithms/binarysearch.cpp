#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int a[250000001];
static int count = 0;
void binarysearch(int* A, size_t s, size_t e, int& item)
{
    if( s >= e ) 
    {
        cout << "Item not found ! " << endl;
        return;
    }
    size_t mid = (s + e)/2;
    if(A[mid] > item)
    {
        ++count;
        cout << " First half :: mid = " << mid  << " Comaparision : " << count << endl;
        binarysearch(A, s, mid, item);
    } 
    else if(A[mid] < item)
    {
        ++count;
        cout << " Second half :: mid = " << mid << " Comaparision : " << count << endl; 
        binarysearch(A, mid, e, item);
    }
    else
    {
        cout << "Item = " << item << " Pos = " << mid << endl;
    }
}
void linearsearch(int* A, int& item)
{
    int count = 0;
    size_t i = 250000000;
    while( i > 0)
    {
        ++count;
        cout << " Search Index = " << i << " Comaparision : " << count << endl; 
        if( A[i] == item )
        {
            cout << "Item = " << item << " Pos = " << i << endl;
            break;
        }
        else
        {
            i--;
            continue;
        }
    }
}
void process()
{
    for(auto i = 0; i <= 250000000; i++)
    {
        a[i] = i;
    }
}
int main()
{
    process();
    int item;
    for(auto i = 0; i < 250000000; i++ )
    {
        item = i;
        binarysearch(a,0,250000000,item);
    }
    linearsearch(a,item);
    return 0;
}