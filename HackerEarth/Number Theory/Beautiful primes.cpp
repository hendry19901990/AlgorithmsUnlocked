#include <iostream>
#include <stdio.h>
#include <string.h>
#include <climits>
#include <vector>
#include <typeinfo> 
#define rep(i, begin, end) for (__typeof(end) i = (begin) - ((begin) > (end)); i != (end) - ((begin) > (end)); i += 1 - 2 * ((begin) > (end)))
#define srep(i, begin, end) for (__typeof(end) i = begin; i != end; i++)
#define si(x) int x = scanInt();
#define sll(x) LL x = scanLong();
#define pi(x) printf("%d ", x)
#define pll(x) printf("%lld ", x)
#define nl printf("\n")
#define all(v) v.begin(), v.end()
using namespace std;
typedef long int LI; // 32 bit integer
typedef unsigned long int ULI; // 32 bit unsigned integer
typedef long long int LL; // 64 bit integer
typedef unsigned long long int  ULL; // 64 bit unsigned integer
typedef long double LD;
typedef vector<int> VI;
typedef vector<LL> VLL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
#define MAX 12100000
using namespace std;
typedef long long int ll;
LL mod = 1e9+7;
 
/* Fast I/O */
inline int scanInt() { int n = 0; char ch = getchar_unlocked(); int sign = 1;
 while(ch < '0' || ch > '9') {if(ch == '-') sign = -1;ch = getchar_unlocked();}
 while(ch >= '0' && ch <= '9') {n = (n<<1)+(n<<3)+(int)(ch-'0'); ch = getchar_unlocked();}
 return n*sign;
}
 
inline LL scanLong() {LL n = 0; char ch = getchar_unlocked();LL sign = 1;
 while(ch < '0' || ch > '9') {if(ch == '-') sign = -1;ch = getchar_unlocked();}
 while(ch >= '0' && ch <= '9') {n = (n<<1)+(n<<3)+(LL)(ch-'0');ch = getchar_unlocked();}
 return n*sign;
}
 
LL modpow(LL x, LL n, LL m) {
 if(n == 0) return 1;
 if(n == 1) return x%m;
 if(n == 2) return (x*x)%m;
 LL ans = 1;
 while(n != 0) {
  if(n&1) ans = (ans*x)%m;
  x = (x*x)%m;
  n >>= 1;
 }
 return ans;
}
 
LL modinv(LL x, LL m) {
 return modpow(x, m-2, m);
}
 
int main() {
#ifndef ONLINE_JUDGE
 freopen("inp.txt", "r", stdin);
#endif
 sll(t);
 while(t-->0) {
  // write your code here...
  sll(n);
  LL pr[n], a[n];
  rep(i, 0, n) pr[i] = scanLong();
  rep(i, 0, n) a[i] = scanLong();
  LL ans = 1;
  rep(i, 0, n) {
      LL num = modpow(pr[i], a[i]+1, mod) - pr[i];
      LL den = pr[i] - 1;
      while(num < 0) num += mod;
      while(den < 0) num += mod;
      ans = (ans*((num*modinv(den, mod))%mod))%mod;
  }
  cout << ans << endl;
 }
}