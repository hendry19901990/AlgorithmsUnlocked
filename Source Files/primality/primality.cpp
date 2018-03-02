#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int modularpower(int a,unsigned int y,int p)
{
    int temp = 1;
    /*----Restrict--Overflow---*/
    a = a % p;
    while( y > 0 ){
        /*---Check-odd-and-store---*/
        if( y & 1 )
        temp = (temp * a) % p;
        /*---Division-by-2-*/
        y = y >> 1;
        a = (a * a) % p;
    }
    return temp;
}
bool isPrime(unsigned int n, int trial)
{
    if(n <=1 || n == 4) return false;
    if(n <= 3)return true;
    /* We try TRIAL times */
    while( trial > 0 )
    {
        int base = 2 + rand() % ( n - 4 );
        /* Using Fermat's Little theorm */
        if( modularpower(base, n-1, n) != 1)  return false;
        trial--;    
    }
    return true;
}
int main()
{
    int a, b, k = 50;
    cin >> a >> b;
    isPrime(a,k)?  cout << "true\n": cout << "false\n";
    isPrime(b,k)?  cout << "true\n": cout << "false\n";
    return 0;
}