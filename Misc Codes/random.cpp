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
#include <set>
#include <functional>
using namespace std;
vector<int> vect;
void process(vector<int> &A)
{
	for(auto i = 0; i < 35; i++)
		A.emplace_back(i);
}
void RandomEngine(size_t index, vector<int> &A)
{
	std::random_device rd;
	std::default_random_engine seed(rd());
	for(auto i = 0; i < index; i++)
	{
		auto range = (static_cast<int>(A.size()) - 1) - i;
		std::uniform_int_distribution<int> swap_rand(0, range);
		swap(A[i], A[swap_rand(seed)]);
	}
}
int main()
{	
	
	long long range = 900;
	set<long long> redblacktree;
	std::random_device rd;
	std::default_random_engine seed(rd());
	std::uniform_int_distribution<int> rand(0, range);
	auto random = std::bind(rand, seed);
	for(auto i = 0; i < 40; i++)
	{
		cout << endl;
		redblacktree.emplace(random());
		for(const auto& item : redblacktree)
		{
			cout << item << ", ";
		}
	}
	process(vect);
	while(true)
	{
		cout << endl;
		RandomEngine(35, vect);
		for(const auto& i : vect) cout << i << " ";
	}
	return 0;
}