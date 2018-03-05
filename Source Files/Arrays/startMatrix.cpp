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
#include "libmatrix.hpp"
using namespace std;
int main(int argc, char const **argv)
{   
    double** mat;
    create_square_matrix(&mat,5);
    identity_matrix(&mat,5);
    print_square_matrix(&mat,5);
    free(mat);
    return 0;
}