#include<iostream>
#include "strings.h"
#define MAX_LIMIT_SZ 2048
typedef struct node{
    int j;
    char ch;
    node *left = NULL;
    node *right = NULL;
}name;
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
    printf("%s\n",p);
}
char** passvalues()
{
    char **p = (char**)malloc(  sizeof(char*)*MAX_LIMIT_SZ );
    for(int i = 0; i < MAX_LIMIT_SZ; i++)
    {
        p[i] = (char*)malloc(MAX_LIMIT_SZ);
    }
    char *arr[] = {
    "This is a tool",
    "is a Tool",
    "a pool",
    "pointer for",
    "to get",
    "an what",
    "array of what",
    "Done nothing"
  };
    for(int i = 0; i < MAX_LIMIT_SZ; i++)
    {
        p[i] = arr[i];
    }
  return p;
}
int main(int argc, char const **argv)
{   
    node start;
    node *root = (node*)malloc(sizeof(node));
    node **TreeElements = (node**)malloc( MAX_LIMIT_SZ*sizeof(node*));
    for(int i = 0; i < MAX_LIMIT_SZ; i++ )
    {
        TreeElements[i] = (node*)malloc(sizeof(node));
    }
    char **array = (char**)malloc(MAX_LIMIT_SZ*sizeof(char*));
    for(int i = 0; i < MAX_LIMIT_SZ; i++)
    {
        array[i] = (char*)malloc(MAX_LIMIT_SZ);
    }
    char *arr = (char*)malloc(MAX_LIMIT_SZ);
    array = s;
    if(arr == NULL || array == NULL)
    {
        printf("Error Allocating Heap !");
        exit(1);
    }
    fgets(arr, MAX_LIMIT_SZ, stdin);
    // getarrayofpointers(array);
    TreeElements[0]->j = 90;
    TreeElements[0]->ch = 'd';
    TreeElements[1]->j = 91;
    TreeElements[1]->ch = 'c';
    TreeElements[2]->j = 92;
    TreeElements[2]->ch = 'j';
    node **p = TreeElements;
    printf("%d\t",(*p)->j);
    printf("%d\t",(*p++)->j);
    printf("%d\t",(*p)++->j);
    free(arr);
    return 0;
}
