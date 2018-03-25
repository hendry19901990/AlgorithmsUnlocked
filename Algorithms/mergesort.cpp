#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
void merge(int* A, int* B)
{
    size_t i = 0, j = 0, k = 0;
    const size_t n = sizeof(A)/sizeof(int);
    const size_t m = sizeof(B)/sizeof(int);
    int* mergearray = new int[m + n + 1];
    memset(mergearray, 0, m+n+1);
    while(i < n && j < m)
    {
        if(A[i] >= B[j])
        {
            mergearray[k] = B[j];
            j++;
        }
        else 
        {
            mergearray[k] = A[i];
            i++;
        }
        k++;
    }
    while(i < n)
    {
        mergearray[k] = A[i];
        i++;
        k++;
    }
    while(j < m)
    {
        mergearray[k] = B[j];
        j++;
        k++;
    }
    size_t s = sizeof(mergearray)/sizeof(int);
    for(j = 0; j < s; j++)
    {
        cout << mergearray[j] << "  ";
        if(j%3 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;    
}
int main()
{
    int A[] = {2,7,3,6,5,4};
    int B[] = {3,5,9,12,45,65,84,45,44};
    merge(A,B);
    return 0;
}