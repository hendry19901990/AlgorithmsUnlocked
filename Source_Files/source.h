#include<iostream>
extern int getfunc();
int getfunc()
{
    return 0;
}
int getstringlenth(const char *p) /* Pointer p should not be able to change the passed string */
{
    int l = 0;
    while(*p!='\0')
    {
        p++; l++;
    }
    return l;
}