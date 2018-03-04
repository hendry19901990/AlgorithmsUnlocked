#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include <bitset>
#include <queue>
#include <forward_list>
#include <set>
#include <algorithm>
#include <future>
#include <initializer_list>
#include <scoped_allocator>
#include <system_error>
#define itn int
#define MAX_LIMIT_SZ 2048
#ifndef WINDOWS_LIB_H
    inline int pidorand() {
        return ((rand() & 32767 << 16) | (rand() & 32767));
    }
    #define rand pidorand
#endif
using namespace std;

/* A function that takes allocates memory for a double 2D array */
inline void create_square_matrix(double*** mat, unsigned int size)
{
    *mat = (double**)malloc(sizeof(double*)*size);
    for(unsigned int i = 0; i < size; i++){
        (*mat)[i] = (double*)malloc(sizeof(double)*size);
    }
}

void identity_matrix(double ***mat, unsigned int size)
{
    unsigned int row, column = 0;
    for( ; row < size; row++)
    {
        for( ; column < size; column++)
        {
            *(*(*(mat+row)+column)) = (row == column)? 1.00 : 0.00;
        }
    }
}

void print_square_matrix(double ***mat, unsigned int size)
{
    unsigned int row, column = 0;
    for( ; row < size; row++)
    {
        for( ; column < size; column++)
        {
            cout << *(*(*(mat+row)+column));
        }
        cout << "\n";
    }
}
