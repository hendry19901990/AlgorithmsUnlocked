#include<iostream>
#include "source.h"
char s[] = "This a great day for us cause we won the battle.";
int main()
{   
    std::cout << getstringlenth(s) << sizeof(s);
    return 0;
}
