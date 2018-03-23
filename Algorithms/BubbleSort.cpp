#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
void print(const int* A)
{
    int n = sizeof(A) / sizeof( A[0] );
    for(auto i = 0; i < 11; i++)
    {
        cout << A[i] << "," ;
    }
    cout << endl;
}
void bubblesort(int* A)
{
    int n = sizeof(A) / sizeof( A[0] );
    for(auto i = 0; i < n - 1; i++)
    {
        bool swapped = false;
        for(auto j = 0; j < n-i-1; j++)
        {
            if(A[j] > A[j + 1])
            std::swap(A[j], A[j + 1]);
            swapped = true;
        }
        if(swapped == false) break;
    }
}
int main()
{
    int array[] = {3,6,7,5,7,8,9,4,1,2,1};
    bubblesort(array);
    print(array);
    return 0;
}