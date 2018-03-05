#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
using namespace std;
int primesieve[12100000];
int primefactors[12100000];
void process(void)
{
    primesieve[0] = 0;
    primefactors[0] = 1;
    for(int i = 1; i < 12100000; i++)
    {
        primesieve[i] = 1;
        primefactors[i] = 0;
    }   
    for(int i = 2; i < 12100000; i++)
    {
        /** We try to iterate through all the sequences of i 
         * and multiples of i using j , to set it to 0 
         * since those aren't primes 
         * */
        if(primesieve[i] == 1)
        {
            /** We will list all the prime numbers
             * in our array of prime factors. 
             * We enter at the first occurance of the prime 
             * number that proves the given number to be a composite.
             * */
            primefactors[i] = i;
            for(int j = 2; i*j < 12100000; j++)
            {
                /* Will do it for all multiples of j */
                primesieve[i*j] = 0;
                /* We do an entry at the first occurance */
                if(primefactors[i*j] == 0)
                {
                    primefactors[i*j] = i;
                }
            }
        }
    }
    cout << "Sieve generated, Prime Factorization : " <<endl;
}
int main(int argc, char *argv[])
{
    if(argc < 1)
    {
        cout << "Enter the number correctly : [expected number] " << endl;
        return -1;
    }
    int num = atoi(argv[1]);
    process();
    while(num != 1)
    {
        cout << "Divisor# " << primefactors[num] << endl;
        /* Jumps backwards to prime factors. We keep dividing. */
        num = num / primefactors[num];
    }
}