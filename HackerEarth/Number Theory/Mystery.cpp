
#include <iostream>
#include <math.h>
#include <vector>
#define ll long long
using namespace std;
int getdivisorcount(int n)
{
    int count = 0, s = sqrt(n);
    if(n == 0 || n == 1)
    {
        return n;
    }
    for(auto i = 1; i <= s; i++)
    {
        if(n%i == 0){
            count++;
        }
    }
    if(s*s == n)
    {
        return 2*count-1;
    }else{
        return 2*count;
    }
}
int main()
{
    int i, cases = 0; 
    cin >> cases;
    while(cases--){
        cin >> i;
        cout << getdivisorcount(i) << endl;
    }
}