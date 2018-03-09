#include <iostream>
#include <string.h>
#include <string>
#include <sstream>
#include <stdio.h>
using namespace std;
int main()
{
    string str;
    int n = 0;
    getline(cin, str);
    cin >> n;
    for(int i = 0; i <= str.length(); i++)
    {
        if(str[i] != '-' && str[i] != ',' && str[i] != ';' && str[i] != '%')
        {
            str[i] = str[i] + n;
        }
    }
    cout << str << endl;
    return 0;
}