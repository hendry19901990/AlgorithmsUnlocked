/** Given an integer N. Find out the PermutationSum 
 * where PermutationSum for integer N is defined as the maximum sum 
 * of difference of adjacent elements in all arrangement of numbers from 1 to N.
 * 
 * Difference between two elements A and B will be considered as 
 * abs(A-B) or |A-B| which always be a positive number.
 * */

#include <iostream>
typedef long long int ll;
using namespace std;
int main()
{
    ll n,t;
    cin>>t;
    while(t--)
    {
	    cin>>n;
	    if(n==1)
	    cout<<1<<endl;
	    else
        /* We see what happens if we add n */
	    cout<<((n-1)*(n))/2+(n/2-1)<<endl;
    }
    return 0;
}