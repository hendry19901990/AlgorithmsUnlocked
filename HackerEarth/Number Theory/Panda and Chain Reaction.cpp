/** Panda has become a scientist recently. 
 * In his laboratory, there are infinite number of chambers where a chamber number K is 
 * connected to a chamber number K-1. The numbering of chambers start from 0. 
 * Initially, X number of particles are present in the chamber number 0. T
 * he number of particles present in chamber K is K times the number of particles present in chamber K-1.
 * You are supposed to help Panda in finding out the number of particles in a given chamber number N.
 * Note: The number of particles in chamber K cannot be calculated until the number of 
 * particles in chamber K-1 are calculated.
 * */
#include <iostream>
#include <stdio.h>
#include <string.h>
#define MAX 12100000
using namespace std;
typedef long long int ll;
const ll mod = 1e6 + 3;
ll* particles = new ll[MAX + 1];
void *fillchamberparticles()
{
    particles[0] = 1;
    for(ll i = 1; i < MAX; i++)
    {
        particles[i] = (i * particles[i - 1]) % mod;
    }
}
int main()
{
    int t = 0;
    cin >> t;
    while(t--)
    {
        ll X, N;
        cin >> N >> X;
        X = X % mod;
        /* No need to send X, We can simply multiply later */
        (*fillchamberparticles)();
        ll result = (X * particles[N]) % mod;
        cout << result << endl;
    }
    return 0;
}
