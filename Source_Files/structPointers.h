#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstdio>
#define MAX_LIMIT_SZ 2048
using namespace std;
typedef struct node{
    int j;
    char ch[2];
    node *left = NULL;
    node *right = NULL;
    node *dangler = NULL;
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
    return 0;
}