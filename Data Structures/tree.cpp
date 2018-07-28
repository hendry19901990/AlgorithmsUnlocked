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
struct node;
using node_ptr = std::shared_ptr<node> ;
struct node
{
	int data;
	node_ptr left, right;
	node(int num) : data(num)
	{
		left = nullptr; right = nullptr;
	}
};
void BuildTree(node_ptr root, int num)
{
	if(num < 0) return;
	else
	{
		int left_num = num/2;
		int right_num = (num/2) - 1;
		if(right_num < 0) return;
		root->left = std::make_shared<node>(left_num);
		root->right = std::make_shared<node>(right_num);
		BuildTree(root->left, left_num);
		BuildTree(root->right, right_num);
	}
}
void InOrderTraversal(node_ptr root)
{
	if(root == nullptr) return;
	InOrderTraversal(root->left);
	cout << root->data << ", ";
	InOrderTraversal(root->right);
}
int main()
{
	auto root = std::make_shared<node>(12);
	BuildTree(root, 12);
	InOrderTraversal(root);
	return 0;
}
