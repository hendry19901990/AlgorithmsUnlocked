#include <iostream>
#include <stdio.h>
#include <conio.h>
using namespace std;
double multiply(double,double);
int main() {
	double c,d = 0;
    cout << "Enter value of c (first number): ";
    cin >> c;
    cout <<endl;
    cout << "Enter value of d (second number): ";
    cin >> d;
    cout <<endl;
    /* Passing the numbers inline */
	cout << "Value of (c x d) i.e, "<< c <<" located @ "<< &c <<" x "<< d <<" located @ "<< &d <<" = "<< multiply(c,d) << endl;
	return 0;
}
/* Function to multiply two numbers */
double multiply(double a, double b)
{
    double r = 0;
    /* Algorithm to multiply two numbers */
    for(int i = 0; i < b; i++)
    {
    	r = r + a;
    }
   cout <<" Value at : " << &r << " = ";
   return r;
}
