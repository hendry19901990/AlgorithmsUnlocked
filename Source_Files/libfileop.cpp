#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
using namespace std;
static int count = 0;
#ifndef FILE 
#define FILE 0
#endif
int main(int argc, char** argv)
{
    /* File Object */
    ifstream ifile;
    ofstream ofile;
    /* User input data */
    string data, modified_data;
    /* Store the input data into a stream */
    stringstream instream; 
    ofile.open("dump.bin", ios::binary | ios::out | ios::in  | ios::app);
    if(ofile.fail())
    {
        cout << "No file found...trying to create a new file" << endl;
        ofile.open("dump.bin", ios::binary | ios::out | ios::in);
    }
    cout << "Enter the data to be saved  : " ;
    getline(cin, data);
    ofile << data << endl;
    /*  Explicit read 
    ifile >> modified_data;
      Explicitly using the file to read and count the words in a string stream 
    instream << modified_data;
    while(instream >> data)
    {
        modified_data = modified_data + " " +  data;
        ::count++;
    }
    modified_data = modified_data + "$ is what you entered and the word count is : ";
    file << modified_data << ::count;
    file.close(); */
    return 0;
}