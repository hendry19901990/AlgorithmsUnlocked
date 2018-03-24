#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int a[25001];
void process()
{
    for(auto i = 25000; i >= 0; i--)
    {
        int j = 25000 - i;
        a[j] = i;
    }
}
void print(size_t size)
{
    for(auto i = 0; i < size; i++)
    {
        cout << a[i] << "    ";
        if(i%10 == 0)
        {
            cout << endl;
        }
    }
    cout << endl;
}
void insertionsort(int* A, size_t size)
{
    int count = 0;
    for(auto sortupto = 1; sortupto < size; sortupto++)
    {
        count++;
        int key = A[sortupto];
        int go_till = sortupto - 1;
        while(go_till > 0 && A[go_till] > key)
        {
            A[go_till + 1] = A[go_till];
            go_till--;
        }
        A[go_till + 1] = key;
        cout << " Comparisions done = " << count << endl;
    }
    print(size);
}
void recursiveinsertionsort(int* A, size_t n)
{
    static int count = 0;
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
    cout << " Comparisions done = " << count << endl;
}
int main()
{
    process();
    insertionsort(a, 25000);
    process();
    recursiveinsertionsort(a, 25000);
    print(25000);
    return 0;
}