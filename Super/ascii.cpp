#include <iostream>
#include <stdio.h>
using namespace std;

int counterAdd()
{   double long product = 1;
	int i,j = 0;
	cout<<"Calling counterAdd()..."<<endl;
    for (i=0;i<5;i++)
    {   int term = product * i;
    	product = product - product * i + term;
    	cout<<"Outer Block : "<<product<<endl;
	    for (j=0; j<5; j++)
	    {
	    	product = product + product * j;
	    	cout<<"....Inner Block : "<<product<<endl;
       	}
    }
    return 0;
}

int main()
{
 cout<<"Find the error :  "<<endl;
 counterAdd();
 return 0;
}



