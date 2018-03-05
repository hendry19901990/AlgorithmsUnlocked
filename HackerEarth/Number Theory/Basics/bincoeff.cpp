#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
using namespace std;
typedef long long int ll;
ll C (int n, int k)
{
    ll res = 1;
    for(int i = 0; i <= k; i++)
    {
        res = res * (n - k + i) / i;
    }
    return (int)(res + 0.01);
}
int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        cout << "Enter the n & r for nCr : [n,r] " << endl;
        return -1;
    }    
    int n = atoi(argv[1]);
    int r = atoi(argv[2]);
    ll res = C (n , r);
    return 0;
}