#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
class parent
{
    string name;
    int date;
public : 
    parent() : randomId(238847), aliasname("Parent Name"), name(""), date(0) { cout << "Parent Called \n"; }
    int randomId;
    string aliasname;
    inline virtual void printname();  
protected :
    int procint;     
};
inline void parent::printname()
{
    cout << "Parent Print name \n";
}
class child : public parent 
{
    string name;
public : 
    child() { cout << "Child Called \n";}
    inline void prints();
};
inline void child::prints()
{
    cout << "Prints -> s" << endl; 
}
int inherit()
{
    child ch;
    /* child *che = new parent; Error */ 
    parent *p = new child;
    cout << "Call : " << endl;
    dynamic_cast<child*>(p);
    ch.printname();
    p -> printname();
    /* p -> prints(); Error : Parent has no prints() method*/ 
    return 0;
}