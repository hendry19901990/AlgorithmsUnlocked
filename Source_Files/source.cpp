#include<iostream>
#include "strings.h"
#define MAX_LIMIT_SZ 2048
    char *s[] = {
    "This is a tool",
    "is a Tool",
    "a pool",
    "pointer for",
    "to get",
    "an what",
    "array of what",
    "Done nothing"
  };
void getarrayofpointers(char **array)
{
    char **p = array;
    printf("%s\n",*p);
    printf("%s\n",*++p);
    printf("%s\n",*p++);
    printf("%s\n",*(p+1));
    printf("%s\n",*++p+1);
    printf("%s\n",++*p+2);
    printf("%s\n",*p++);
}
char** passvalues()
{

}
char *arr = (char*)malloc(MAX_LIMIT_SZ);
int main(int argc, char const **argv)
{   
    char **array = (char**)malloc(MAX_LIMIT_SZ*sizeof(char*));
    array = s;
    if(arr == NULL || array == NULL)
    {
        printf("Error Allocating Heap !");
        exit(1);
    }
    fgets(arr, MAX_LIMIT_SZ, stdin);
    getarrayofpointers(array);
    return 0;
}
