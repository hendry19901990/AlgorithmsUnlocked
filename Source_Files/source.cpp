#include<iostream>
#include "strings.h"
#define MAX_LIMIT_SZ 2048
static int number = 4544;
void function(int a)
{
    printf("%d,",a);
    static int number = a;
    if(a <= 0){exit(0);}
    printf("%d\n",number);
    function(a - 1);
}
void function2(int a)
{
    printf("%d,",a);
    int number = a;
    if(a < 0){exit(0);}
    printf("%d\n",number);
    function(a - 1);

}
char *arr = (char*)malloc(MAX_LIMIT_SZ);
int main(int argc, char const **argv)
{   
    int number = 92;
    if(arr == NULL)
    {
        number = 855;
        printf("Error Allocating Heap ! %d",::number);
        exit(1);
    }
    fgets(arr, MAX_LIMIT_SZ, stdin);
    printf("%d\t%lu\n",getstringlenth(arr),sizeof(&arr));
    stringmanipulate(arr);
    pointermanipulate(arr);
    printstring(arr);
    free(arr);
    function2(number);
    return 0;
}
