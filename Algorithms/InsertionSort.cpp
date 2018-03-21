#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
void insertionsort(int* A, size_t size)
{
    for(auto sortupto = 1; sortupto < size; sortupto++)
    {
        int key = A[sortupto];
        int go_till = sortupto - 1;
        while(go_till > 0 && A[go_till] > key)
        {
            A[go_till + 1] = A[go_till];
            go_till--;
        }
        A[go_till + 1] = key;
    }
    for(auto i = 0; i < size; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;
}
void recursiveinsertionsort(int* A, size_t n)
{
    if(n <= 1) exit(EXIT_FAILURE);
    recursiveinsertionsort(A, n - 1);
    int last_elem = A[n -1];
    int indexUp = n - 2;
    while(indexUp > 0 && A[indexUp] > last_elem)
    {
        A[indexUp + 1] = A[indexUp];
        indexUp--;
    }
    A[indexUp + 1] = last_elem;
    for(auto i = 0; i < n; i++)
    {
        cout << A[i] << "  ";
    }
    cout << endl;
}
int main()
{
    int Array[] = {56,658,45,744,57,45,89,6,5,741,245,7441,58,42,588,7411,5,84,568,4,5,8,741,15,8,45,58,4,45,858,45,74,8,85,5,58,89,5,5,5,877,4,5,8,5654,87};
    insertionsort(Array, 45);
    recursiveinsertionsort(Array, 45);
    return 0;
}