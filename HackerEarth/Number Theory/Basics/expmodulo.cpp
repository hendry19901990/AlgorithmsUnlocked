#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
using namespace std;
typedef long long int ll ;
ll expmodulo(ll a, ll b, ll mod)
{
    if(a == 0 || b == 0 || a < 0 || b < 0) return 0;
    else if(b == 0) return 1;
    else if(b == 1) return a % mod;
    else if(b&1) return (a * expmodulo(a * a, b>>1, mod) % mod); // No Overflow.
    else {
        return expmodulo(a * a, b>>1, mod);
    }
}
int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        cout << "Enter the base, power & mod-num : [b,pb,md] " << endl;
        return -1;
    }    
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    int mod = atoi(argv[3]);
    cout << "Exponent Modulo is : " << expmodulo(a,b,mod) << endl;
    return 0;
}