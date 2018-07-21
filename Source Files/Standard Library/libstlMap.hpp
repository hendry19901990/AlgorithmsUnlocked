#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <regex>
#include <sstream>
#include <ctype.h>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{	
	unordered_map<int,string> mymap;
	unordered_map<int,string>::hasher hash_func = mymap.hash_function();
	mymap[9] = "Sumit Lahiri";
	mymap[14] = "Shuvradeep Lahiri";
	mymap[86] = "Google";
	mymap[23] = "Pradipta Lahiri";
	mymap[35] = "Pradipta Lahiri";
	mymap[49] = "Susovan Lahiri";
	mymap[52] = "Google";
	mymap[56] = "Microsoft";
	mymap[245] = "Apple";
	mymap[127] = "HackerEarth";
	mymap[364] = "HackerRank";
	mymap[1255] = "HackerRank";
	mymap[732] = "Microsoft";
	mymap.emplace (1701, "J.T. Kirk");
	mymap.emplace (18654, "Rowan Atkinson");
	unsigned size = mymap.bucket_count();
	for(const auto& x : mymap)
	{
		std::cout << "Element [" << x.first << " : " << x.second << "]";
    	std::cout << " is in bucket #" << mymap.bucket(x.first) << std::endl;
	}
   	for (unsigned i = 0; i < size; ++i)
   	{
    	std::cout << "bucket #" << i << " has " << mymap.bucket_size(i) << " elements.\n";
  	}
  	std::cout << "mymap's buckets contain:\n";
  	for (auto i = 0; i < mymap.bucket_count(); ++i)
  	{
    	std::cout << "bucket #" << i << " contains:";
    	for (auto start = mymap.begin(i); start != mymap.end(i); ++start)
    		std::cout << "{" << start->first << " : " << start->second << "}  ";
    	std::cout << std::endl;
  	}
	return 0;
}