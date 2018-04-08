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
template <typename U, typename T>
void linearsearch(U& elem, T& item)
{
	bool found = false;
	for (const auto& i : elem)
	{
		if (i == item)
		{
			cout << "Found : " << &i << " Item " << item << endl;
			found = true;
		}
	}
	if(found == false)	cout << "Not Found Item : " << item << endl;
}
template <typename U, typename T>
void binarysearch(const U& elem, const T& item, size_t start, size_t end) noexcept
{
  if(start > elem.size() || end > elem.size() || start < 0 || end < 0)
	{
		cout << "Item not found in range :: " << item << endl;
		return;
	}
	bool found = false;
	if( start >= end )
	{
		elem[start] == item ? start : -1 ;
	}
	size_t mid = start + (end - start) / 2;
	if(item == elem[mid])
		found = true;
	else if (item > elem[mid])
	 	binarysearch<U,T> (elem, item, mid + 1, end);
	else
		binarysearch<U,T> (elem, item, start, mid - 1);
	if(found == true)
		cout << "Element found : " << &mid << " " << mid << endl;
	else
		cout << "Item : " << item << " not found" << endl;
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