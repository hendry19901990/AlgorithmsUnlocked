#include<iostream>
#include "strings.h"
#define MAX_LIMIT_SZ 2048
char *arr = (char*)malloc(MAX_LIMIT_SZ);
std::string str = "I am a Web Developer";
int main(int argc, char const **argv)
{   
    if(arr == NULL)
    {
        printf("Error Allocating Heap !");
        return -1;
    }
    fgets(arr, MAX_LIMIT_SZ, stdin);
    printf("%d\t%d\n",getstringlenth(arr),sizeof(&arr));
    stringmanipulate(arr);
    pointermanipulate(arr);
    printstring(arr);
    printstring(arr);
    free(arr);
    return 0;
}
