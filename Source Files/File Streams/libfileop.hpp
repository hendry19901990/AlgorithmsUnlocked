#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
static int count = 0;
#ifndef FILE 
#define FILE 0
#endif
/* A dangerous way of file handling */
int main(int argc, char** argv)
{
    /* File Object */
    ifstream ifile;
    ofstream ofile;
    /* User input data */
    string data, modified_data, ch = "Y";
    /* Store the input data into a stream */
    stringstream instream; 
    ofile.open("dump.bin", ios::out | ios::in  | ios::app);
    if(ofile.fail())
    {
        cout << "No file found...trying to create a new file" << endl;
        ofile.open("dump.bin", ios::out | ios::in);
    }
    do{
        cout << "Enter the data to be saved  : " ;
        getline(cin, data);
        ofile << endl << data;
        cout << endl << "Want to enter more (Y / N) : " << endl;
        getline(cin,ch);
    }while(ch == "y" || ch == "Y");
    /* See what I just did */
    ifile.open("dump.bin", ios::in);
    while(ifile >> ch)  {  ::count++;  }
    ofile << endl << "Word Count now " <<  ::count;
    ofile.close();
    return 0;
}