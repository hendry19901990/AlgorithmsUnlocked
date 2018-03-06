#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
using namespace std;
typedef long long int ll;
void inverse(ll A, ll M, ll& x, ll& y)
{
    if(A % M == 0)
    {
        x = 0;
        y = 1;
    }
    else
    {
        inverse(M, A % M, x, y);
        ll temp = x;
        x = y;
        y = temp - (A / M) * y;
    }
}
ll expmodulo(ll a, ll b, ll mod)
{
    if(a == 0 || b == 0 || a < 0 || b < 0) return 0;
    else if(b == 0) return 1;
    else if(b == 1) return a % mod;
    else if(b&1) return ((a * expmodulo((a * a) % mod, b>>1, mod)) % mod); // No Overflow.
    else {
        return expmodulo((a * a) % mod, b>>1, mod);
    }
}
int main(void)
{
    ios_base::sync_with_stdio(false);
    cin.good();
    ll A, M, B, C, x, y = 0;
    cin >> A >> B >> C >> M;
    inverse(C, M, x, y);
    x = (x % M + M) % M;
    ll res = (expmodulo(A, B, M) * x) % M;
    cout << res;
    return 0;
}