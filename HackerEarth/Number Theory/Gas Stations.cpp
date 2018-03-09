#include <iostream>
#include <stdio.h>
#include <string.h>
#include <vector>
#define vi vector<int>
#define pb push_back
#define ll long long
#define llu unsigned long long
#define N stations
#define X fuel
#define MOD 1000000007
using namespace std;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.good();
    int stations, fuel, j, i = 0;
    cin >> stations >> fuel;
    vi st;
    for(int i = 0; i <= stations; i++)
    {
        cin >> j;
        st.pb(j);
    }
    j = 0;
    while(fuel > 0 && st[i])
    {
        fuel = fuel - st[i];
        j++;
        i++;
    }
    cout << j;
    return 0;
}