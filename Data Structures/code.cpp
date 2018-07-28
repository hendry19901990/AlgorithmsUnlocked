#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <regex>
#include <sstream>
#include <ctype.h>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <random>
#include <queue>
#include <stack>
#include <deque>
#include <list>
#include <set>
#include <iterator>
#include <algorithm>
#include <functional>
#include <limits>
#include <mutex>
#include <thread>
using namespace std;
#define print(vec) for(const auto& e : vec) { cout << e << ", "; }
struct BinaryTrie;
using trie = std::shared_ptr<BinaryTrie>;

struct BinaryTrie
{
	bool finished;
	vector<trie> nextnodes;
	BinaryTrie() : finished(false)
	{
		nextnodes.emplace_back(nullptr);
		nextnodes.emplace_back(nullptr);
	}
};

stack<bool> FindinBinary(const long long& num)
{
	stack<bool> que;
	bool sign = false;
	long long temp = num;
	if(temp < 0)
	{
		sign = true;
		temp = -temp;
	}
	while(temp)
	{
		if(temp % 2) que.emplace(true);
		else que.emplace(false);
		temp = temp / 2;
	}
	if(sign)
	{
		que.emplace(true);
	}
	else
	{
		que.emplace(false);
	}
	return que;
}

void addNumber(trie xor_trie, const long long& num)
{
	auto q = FindinBinary(num);
	auto temp = xor_trie;
	while(!q.empty())
	{
		bool y = q.top();
		q.pop();
		/* Adding Trie Nodes now */
		if(temp->nextnodes[y] == nullptr)
		{
			temp->nextnodes[y] = std::make_shared<BinaryTrie>();
			temp = temp->nextnodes[y]; 
		}
		else
		{
			temp = temp->nextnodes[y];
		}
	}
	temp->finished = true;
}

bool FindNumberInTrie(const trie xor_trie, const long long& num)
{
	auto q = FindinBinary(num);
	auto temp = xor_trie;
	while(!q.empty())
	{
		bool y = q.top();
		q.pop();
		/* Searching Trie Nodes now */
		if(temp->nextnodes[y] == nullptr)
		{
			return false;  
		}
		else
		{
			temp = temp->nextnodes[y];
		}
	}
	return true;
}

int main()
{
	long long x = 0;
	auto head = std::make_shared<BinaryTrie>();
	for(auto i = 0; i < 8950000; i ++)
	{
		addNumber(head, i);
	}
	while(cin >> x)
	{
		auto q = FindinBinary(x);
		cout << "Number : " << x << "\n";
		cout << "Binary : 0b0";
		while(!q.empty())
		{
			bool y = q.top();
			q.pop();
			cout << y;
		}
		cout << "\n";
		cout << "Result : " << FindNumberInTrie(head, x) << "\n";
	}
	return 0;
}
