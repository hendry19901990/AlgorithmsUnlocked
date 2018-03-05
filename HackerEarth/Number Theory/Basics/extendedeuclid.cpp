#include <iostream>
#include <limits>
using namespace std;
template<typename _EuclideanRingElement>
_EuclideanRingElement __gcd(_EuclideanRingElement __m, _EuclideanRingElement __n)
{
    while (__n != 0)
    {
        _EuclideanRingElement __t = __m % __n;
        __m = __n;
        __n = __t;
    }
    return __m;
}
template<typename _EuclideanRingElement>
_EuclideanRingElement extendecdl(_EuclideanRingElement a, _EuclideanRingElement b, int& x, int& y)
{
    if(a%b == 0)
    {
        x = 0;
        y = 1;  
        return __gcd<_EuclideanRingElement>(a ,b);
    }
    else{
        extendecdl<_EuclideanRingElement>(b, a%b, x, y);
        int temp  = x;
        x = y;
        y = temp - (a/b)*y;
    }
    return __gcd<_EuclideanRingElement>(a ,b);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.good();
    int a,m,x,y = 0;
    cin >> a >> m;
    int gcd = extendecdl<int>(a,m,x,y);
    int res = (x%m + m) % m;
    cout << res << endl;
    return 0;
}
