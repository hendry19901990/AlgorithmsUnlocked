#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
using namespace std;
int primesieve[12100000];
void process()
{
    primesieve[0] = 0;
    for(int i = 1; i < 12100000; i++)
    {
        primesieve[i] = 1;
    }   
    for(int i = 2; i < 12100000; i++)
    {
        /** We try to iterate through all the sequences of i 
         * and multiples of i using j , to set it to 0 
         * since those aren't primes 
         * */
        if(primesieve[i] == 1)
        {
            for(int j = 2; i*j < 12100000; j++)
            {
                /* Will do it for all multiples of j */
                primesieve[i*j] = 0;
            }
        }
    }
    cout << "Sieve generated" <<endl;
}
int main(int argc, char *argv[])
{
    ios_base::sync_with_stdio(false);
    cin.good();
    int count = 0;
    if(argc < 2)
    {
        cout << "Enter the range correctly : [L:R] " << endl;
        return -1;
    }
    process();
    int l = atoi(argv[1]);
    int r = atoi(argv[2]);
    if(l > r)
    {
        for(int i = r; i < l; i++)
        {
            if(primesieve[i] == 1)
            {
                cout << i << " is prime." << endl;
                count++;
            }
        }
    }
    else
    {
        for(int i = l; i < r; i++)
        {
            if(primesieve[i] == 1)
            {
                cout << i << " is prime." << endl;
                count++;
            }
        }
    }
    cout << "Count : " << count;
#ifdef LOCAL_DEFINE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
#endif
    return 0;
}