#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <vector>
#include <ctype.h>
#include <array>
#include <map>
#include <list>
#include <deque>
#include <bitset>
#include <queue>
#include <forward_list>
#include <set>
#include <algorithm>
#include <future>
#include <initializer_list>
#include <mutex>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
using namespace std;
ostream& operator<<(ostream& out, string vec){
	for (auto& i : vec) {
		cout << "\t" << i << endl;
	}
}
int main(int argc, char* argv[])
{
	try
	{
		string word = "This is a great thing to do ";
		reverse(word.begin(), word.end()); /* Reverse the string */
		string file("tofu.man");
		const char* ch = word.data(); /* C++ style, pointer to first char in str. */
		const char* cj = word.c_str(); /* C style, pointer to first char in str. As if str is C string */
		cj = cj + 3; /* Normal Pointer Arithmetic */
		ch = ch + 4; /* Normal Pointer Arithmetic */
		cout << word.size() << word.capacity() << endl;
		string copy1(word); /* Copy constructor called */
		string copy2(word, *cj, 5); /* Copy Constructor from cj to next 5 pos */
		string copy3(word, *ch, 7); /* Copy Constructor from ch to next 7 pos */
		cout << word << copy1 << copy2 << copy3 << endl;
		char sentence[80] = "I am C++ developer for distributed computing.";
		string title(sentence + 9, sentence + 16);
		vector<char> input;
		char c;
		while (cin.get(c) && c != '\n')
		{
			input.push_back(c);
		}
		string str_input(input.begin() + 3, input.end() + 6);
		cout << str_input.empty();
		string message("May be the donkey will eat food.");
		string pet(message.substr(10, 5)); /* Substring from pos-> 10 next 5 char */
		cout << message[3] << pet << endl;
		string longer("This is a big cat-house with cats living in it");
		string shorter("cats");
		auto loc1 = longer.find(shorter); 
		auto loc2 = longer.find(shorter);
		auto loc3 = longer.find(shorter, loc1 + 1);
		auto loc4 = shorter.find('h' || 'i');
		if (loc1 == string::npos || loc2 == string::npos || loc3 == string::npos || loc4 == string::npos) cout << "Not found\n";
		auto loc11 = longer.find_first_of(shorter);
		auto loc22 = longer.find_first_not_of(shorter);
		auto loc33 = longer.find_last_of(shorter, loc1 + 1);
		cout << loc1 << loc2 << loc3 << loc11 << loc22 << loc33;
		word.append("I am Happy");
		word.append(3, '!');
		word.append(message);
		string test;
		test.assign(9, '0');
		word = message + test + pet;
		cout << word << endl;
		string str3("The banker");
		str3.insert(4, "former");
		str3.insert(str3.size() - 1, "waltzed!!!!!", 8);
		word.append(str3);
		word.erase(9, 16);
		string::size_type pos = word.find("is");
		cout << word << endl;
	}
	catch (std::exception e) {
		cout << e.what() << endl;
	}
	return 0;
}