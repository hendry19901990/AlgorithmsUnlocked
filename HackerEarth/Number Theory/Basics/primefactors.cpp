#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
using namespace std;
typedef long long int ll;
void printprimefactors(int n)
{
    if(!(n&1))
    {
        cout << "2" << endl;
        n = n >> 1;
    }
    else
    {
        for(int i = 3; i*i < n; i = i + 2)
        {
            if(n%i == 0)
            {
                cout << i << endl;
                n = n / i ;
            }
        }
    }

    if( n > 2 )
    {
        cout << n << endl;
    }
}
int main(int argc, char* argv[])
{
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.good();
    if(argc < 1)
    {
        cout << "Please enter number : [n] " << endl;
    }
    int num = atoi(argv[1]);
    printprimefactors(num);
    return 0;
}