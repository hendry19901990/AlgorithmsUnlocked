#include <iostream>
#include <sstream>
#include <string>
using namespace std;
static int count = 0;
#ifndef FILE 
#define FILE 0
#endif

int main(int argc, char** argv)
{
    /* User input data */
    string data, modified_data;
    /* Store the input data into a stream */
    stringstream instream; 
    /* Enter Data */
    cout << "Enter the data to be saved  : " ;
    getline(cin, data);
    instream << data;
    while(instream >> data)
    {
        modified_data = modified_data + " " +  data;
        ::count++;
    }
    /* Giving Word Count */
    modified_data = modified_data + "$ is what you entered and the word count is ";
    cout << modified_data << ::count;
    return 0;
}