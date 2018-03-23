#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;
void recursiveselsort(int* A, size_t n)
{
    if(n <= 1) return;
    recursiveselsort(A, n-1);
    int min = 0;
    for(auto i = 0; i < n; i++)
    {
        if(A[i] < A[min])
        {
            min = i;
        }
        swap(A[min], A[0]);
    }
}
void print(int* A, size_t n)
{
    for(auto j = 0; j < n; j++)
    {
        cout << A[j] << " " ;
    }
    cout << endl;
}
int main()
{
    int A[] = {5,54,56,58,41,56,25,85,74,56,32,14,785,41,478,541,458,874};
    recursiveselsort(A, 18);
    print(A, 18);
    return 0;
}