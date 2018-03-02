#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

vector<int> parseInts(string str) {
   // Complete this function
   stringstream ss;
   std::vector<int> vec;
   char ch;
   ss << str;
   int a,b;
   while(ss >> a){
     ss >> ch;
     vec.push_back(a);
   }
   return vec;
}

int main() {
    string str;
    getline(cin,str);
    vector<int> integers = parseInts(str);
    for(int i = 0; i < integers.size(); i++) {
        cout << integers[i] << "\n";
    }

    return 0;
}
