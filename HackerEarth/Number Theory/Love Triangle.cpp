#include <iostream>
#define ll long long
using namespace std;
ll lovetriangle(ll x){
    if(x < 9) return x;
    else return x % 9 + 10 * lovetriangle(x / 9);
}
int main()
{
    ll x;
    while( cin >> x ){
        cout << lovetriangle(x) << "\n";
    }
    return 0;
}
