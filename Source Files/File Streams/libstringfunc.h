#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#define MAX_LIMIT_SZ 2048
using namespace std;
extern int getfunc();
int getstringlenth(const char *p) /* Pointer p should not be able to change the passed string */
{
    int l = 0;
    while(*p!='\0')
    {
        p++; l++;
    }
    return l;
}
char* stringmanipulate(char *p)
{
    while(*p!='\0')
    {
        if(*p =='s' || *p == 'S')
        {
            *p = '$';
        }
        p++;
    }
    return p;
}
char** pointermanipulate(char *p)
{
    char **pp = &p;
    while(**pp!='\0')
    {
        if(**pp == 'w' || **pp == 'W')
        {
            **pp = '#';
        }
        (*pp)++;
    }
    return pp;
}
void printstring(const char *p)
{
    while(*p!='\0')
    {
        printf("%c",*p);
        ++p;
    }
    std::cout << "\n";
}
void countvowel(const char *p)
{
    char vowel[] = "aeiou"; 
    const char *j = vowel;
    static int count = 0;
    while(*p!='\0')
    {
        while(*j!='\0')
        {
            if(*j == *p)
            {
                count++; 
            }
            j++;
        }
        p++;
    }
    printf("%d\n", count);
}