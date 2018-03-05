#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef long long int ll ;
int inv[12100000];
void process(ll exp)
{
    memset(inv,1,10000000*sizeof(int));
    inv[0] = 1;
    for(int i = 2; i <= 10000000; i++)
    {
        inv[i] = ((exp - exp/i)*inv[exp % i])% exp;
    }
}
int main(int argc, char* argv[])
{
    ll exp = 1e9+13;
    ios_base::sync_with_stdio(false);
    cin.good();
    int count = 0;
    if(argc < 2)
    {
        cout << "Enter the range correctly : [L:R] " << endl;
        return -1;
    }
    int l = atoi(argv[1]);
    int r = atoi(argv[2]);
    // size_t t = (l-r)>0 ? l-r : r-l;
    process(exp);
    if(l > r)
    {
        for(int i = r; i <= l; i++)
        {
            cout << inv[i] << endl;
        }
    }
    else
    {
        for(int i = l; i <= r; i++)
        {
            cout << inv[i] << endl;
        }
    }
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}