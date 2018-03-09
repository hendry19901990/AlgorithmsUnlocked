#include <iostream>
#include <stdio.h>
#include <string.h>
// typedef long long int ll;
// const ll mod = 1e9 + 7;
// constexpr inline ll min(ll n) { return (n*(n-1)*(n-1))/4; }
// constexpr inline ll max(ll n) { return (n*(n-1)*(2*n-1))/6; }
using namespace std;
#define ll long long int
#define MOD 1000000007
int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        ll n;
        cin >> n;
        n--; /* (n - 1) */
        ll tmp = n/2;
        ll min = (tmp*tmp)%MOD;
        min = (min*(n+1))%MOD;
        ll max = (n*(n+1))%MOD;
        max = (max*(2*n+1))%MOD;
        max = (max*166666668)%MOD;
        cout << min << " " << max << endl;
    }
    return 0;
}