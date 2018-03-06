#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long int ll;
using namespace std;
int main()
{
    /* We calculate the sum of all divisors of the number including 1 */
    int test = 0;
    cin >> test;
    /* Note the all divisors are less than root n */
    while(test--)
    {
        ll n = 0;
        cin >> n;
        ll s = 0;
        for(ll i = 1; i < n; i++)
        {
            if(n%i == 0)
            {
                s+= i; 
            }
        }
        cout << s << endl;
    }
    return 0;
}