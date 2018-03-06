#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long int ll;
#define MAX 100000 /* Arbitrary, Guess wont ask beyond it. */ 
using namespace std;
ll* primesieve = new ll[MAX + 1];
ll* primecount = new ll[MAX + 1];
void *process(void)
{
	/* Only primes satisfy all the constraints given. */
    primesieve[0] = 0;
    for(int i = 1; i < 100000; i++)
    {
        primesieve[i] = 1;
    }   
    for(int i = 2; i < 100000; i++)
    {
        /** We try to iterate through all the sequences of i 
         * and multiples of i using j , to set it to 0 
         * since those aren't primes 
         * */
        if(primesieve[i] == 1)
        {
            for(int j = 2; i*j < 100000; j++)
            {
                /* Will do it for all multiples of j */
                primesieve[i*j] = 0;
            }
        }
    }
	int count = 0;
	for(int k = 0; k <= 100000; k++)
	{
		if(primesieve[k] == 1)
		{
			/* Only primes satisfy all the constraints given. */
			/* Keep a count of the prime numbers encountered till now */
			count++; 
		}
		primecount[k] = count;
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.good();
	ll test;
	cin >> test;
	(*process)();
	while(test-- > 0)
	{
		int L, R = 0;
		cin >> L >> R;
		if(L > R)
		{
			cout << primecount[L] - primecount[R-1] << endl;
		}
		else if( R > L)
		{
			cout << primecount[R] - primecount[L-1] << endl;
		}
		else
		{
		    return 0;
		}
	}
	return 0;
}
