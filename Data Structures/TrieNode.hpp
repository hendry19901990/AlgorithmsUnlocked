#include <iostream>
#include <string>
#include <memory>
#include <stdio.h>
#include <regex>
#include <sstream>
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
		if(temp->next_char_array[str[j] - 'a'] == nullptr)
			temp->next_char_array[str[j] - 'a'] = std::make_shared<trienode>(ch);
		++(temp->up_to_this);
		temp = temp->next_char_array[str[j] - 'a'];
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
		if(temp->next_char_array[str[j] - 'a']->node_char == str[j])
		{
			temp = temp->next_char_array[str[j] - 'a'];	
		}
		else return false;
	}
	return true;
}
int main()
{	
	string str1 = "confundus_charm";
	string str2 = "confusion";
	string str3 = "engineering";
	string str4 = "Google";
	string str5 = "Microsoft";
	auto wordtrie = std::make_shared<trienode>();
	wordtrie->addWord(str1, wordtrie);
	wordtrie->addWord(str2, wordtrie);
	wordtrie->addWord(str3, wordtrie);
	wordtrie->addWord(str4, wordtrie);
	wordtrie->addWord(str5, wordtrie);
	cout << wordtrie->searchWord(str3, wordtrie);
	return 0;
}