#include <iostream>
#include <cstring>
int main()
{
    int a[10];
    std::memset(a, -1, sizeof(a));
    for (auto i : a) std::cout << i;
}