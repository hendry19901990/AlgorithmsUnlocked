// This is not an exact implementation of a PATRICIA trie.

#include <iomanip>
#include <iostream>
#include <algorithm>
#include <array>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <future>
#include <initializer_list>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <typeinfo>
using namespace std;
typedef std::vector<int> vector_int;

const int ALPHABET_SIZE = 26;
struct TrieNode
{
	struct TrieNode *children[ALPHABET_SIZE];
	bool isEndOfWord;
};

struct TrieNode *getNode()
{
	auto *Node = new TrieNode;
	Node->isEndOfWord = false;
	for (auto & i : Node->children) {
		i = nullptr;
    }
	return Node;
}

void insert(struct TrieNode *root, string key)
{
	struct TrieNode *item = root;
	for (char i : key)
	{
		int index = i - 'a';
		if (item->children[index] == nullptr) {
			item->children[index] = getNode();
        }
		item = item->children[index];
	}
	item->isEndOfWord = true;
}

bool search(struct TrieNode *root, string  key)
{
	struct TrieNode *item = root;

	for (char i : key)
	{
		int index = i - 'a';
		if (item->children[index] == nullptr) {
			return false;
        }
		item = item->children[index];
	}
	return (item != nullptr && item->isEndOfWord);
}
