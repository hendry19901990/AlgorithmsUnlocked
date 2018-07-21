#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <regex>
#include <sstream>
#include <ctype.h>
using namespace std;
class trienode;
using char_ptr = std::shared_ptr<trienode>;
class trienode
{
	bool isEnd;
	char node_char;
	int up_to_this;
	vector<char_ptr> next_char_array;
public:
	trienode() : isEnd(false), node_char('0'), up_to_this(0) 
	{
		for(auto i = 0; i < 27; i++)
		{
			next_char_array.emplace_back(nullptr);
		}
	}
	trienode(char &ch): isEnd(false), node_char(ch), up_to_this(0) 
	{
		for(auto i = 0; i < 27; i++)
		{
			next_char_array.emplace_back(nullptr);
		}
	}
	~trienode() {}
	bool addWord(const string&, char_ptr&);
	void deleteWord(const string&, char_ptr&);
	bool searchWord(const string&, char_ptr&);
};
bool trienode::addWord(const string &str, char_ptr &root)
{
	auto size = str.size();
	char_ptr temp = root;
	for(auto j = 0; j < size; j++)
	{
		char ch = str[j];
		if(temp->next_char_array[tolower(str[j]) - 'a'] == nullptr)
			temp->next_char_array[tolower(str[j]) - 'a'] = std::make_shared<trienode>(ch);
		++(temp->up_to_this);
		temp = temp->next_char_array[tolower(str[j]) - 'a'];
		temp->isEnd = false;
	}
	temp->isEnd = true;
	return temp->isEnd;
}
bool trienode::searchWord(const string &str, char_ptr &root)
{
	auto size = str.size();
	char_ptr temp = root;
	for(auto j = 0; j < size; j++)
	{
		if(temp->next_char_array[tolower(str[j]) - 'a']->node_char == str[j])
		{
			temp = temp->next_char_array[tolower(str[j]) - 'a'];	
		}
		else return false;
	}
	return true;
}

int main()
{	
	stringstream ss;
	string str, buff;
	vector<string> buffvec;
	auto wordtrie = std::make_shared<trienode>();
	getline(cin, str); 
	ss << str;
	while(ss >> buff)
	{
		buffvec.emplace_back(buff);
	}
	for(string s : buffvec) wordtrie->addWord(s, wordtrie);
	cout << wordtrie->searchWord(buffvec[4], wordtrie);
	cout << wordtrie->searchWord("software", wordtrie);
	return 0;
}