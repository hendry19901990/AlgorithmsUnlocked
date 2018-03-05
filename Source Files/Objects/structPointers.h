#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#define MAX_LIMIT_SZ 2048
using namespace std;
typedef struct error{
    int *p;
    error *dangle = NULL;
}error;
typedef struct node{
    int j;
    char ch[2];
    node *left;
    node *right ;
    node *dangler ;
    node():j(MAX_LIMIT_SZ),left(nullptr),right(nullptr),dangler(nullptr){} // ctor initialization
}name;
void printStruct(node* *t)
{
    node **p = t;
    printf("%d\t%d\t%d\t%d\t",--((*p)->j),++((*p)->j),++((*p)->j),--((*p)->j));
    printf("%d\t%d\t%d\t%d\t",((*p)->j)--,((*p)->j)++,((*p)->j)++,((*p)->j)--);
    printf("%d\t%d\t%d\t%d\t",--((*p)->j),++((*p)->j),++((*p)->j),--((*p)->j));
    printf("%d\t",(*++p)->j);
    printf("%d\t",(*p)++->j);
    printf("%d\t",(*++p)->j);
    printf("%d\n",(*--p)->j);
}
int runMethodStruct()
{
    node start;
    node *root = (node*)malloc(sizeof(node));
    node **TreeElements = (node**)malloc( MAX_LIMIT_SZ*sizeof(node*));
    for(int i = 0; i < MAX_LIMIT_SZ; i++ )
    {
        TreeElements[i] = (node*)malloc(sizeof(node));
    }
    TreeElements[0]->j = 90;
    TreeElements[0]->ch[0] = 'd';
    TreeElements[1]->j = 91;
    TreeElements[1]->ch[0] = 'c';
    TreeElements[2]->j = 92;
    TreeElements[2]->ch[1] = 'j';
    printStruct(TreeElements);
    int l= 90;
    int a[] = {69,57,77,7,6,8,9,10};
    error *ptr = (error*)malloc(sizeof(error));
    ptr->p = a;
    l = (*ptr->p++)++;
    int y = ++l;
    printf("%d\n",l);
    printf("%d\n",y);
    printf("%p\n",a);
    printf("%d\n",*ptr->p);
    return 0;
}