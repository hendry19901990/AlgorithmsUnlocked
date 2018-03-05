#include <iostream>
#include <sstream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
static int count = 0;
#ifndef FILE 
#define FILE 0
#endif
int main(int argc, char** argv)
{
    unsigned long address = 0;
    char c;
    string data, modified_data;
    /* Store the input data into a stream */
    stringstream instream;
    instream << hex << setfill('0');
    while(cin.good())
    {
        int nread;
        char buf[16];
        for(nread = 0; nread < 16 && cin.get(buf[nread]); nread++);
        if(nread == 0) break;
        // Show the address 
        instream << setw(8) << address;
        // Show the hex codes
        for( int i = 0; i < 16; i++ )
        {
            if( i % 8 == 0 ) instream << ' ';
	        if( i < nread )
            instream << ' ' << setw(2) << (unsigned)buf[i];
            else 
            instream << '   ';
        }
        instream << ' ';
        for( int i = 0; i < nread; i++)
        {
            if( buf[i] < 32 ) instream << '.';
            else instream << buf[i];
        }
        instream << "\n";
        address += 16;
    }
    while(instream >> data)
    {
        modified_data = modified_data + " " + data;
    }
    cout << modified_data;
	return 0;
}