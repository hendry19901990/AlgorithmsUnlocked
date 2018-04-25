#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
#include <string.h>
#include <math.h>
#include <vector>
#include <memory>
#include <sstream>
#include <map>
#include <stdexcept>
#include "utilities.hpp"
/* PLease include it int the tree files*/
using namespace std;
template <typename Key, typename Value> class BinaryTree;

template <typename Key, typename Value>
class TreeNode
{
private:
	Hash HashObject("0xceed78f");
	size_t height;
	bool isVisited;
	bool isExplored;
	Key _key;
	Value _value;
	std::string unique_hash;
	TreeNode *left, *right, *parent;
	friend class BinaryTree<Key, Value>;
public:
	TreeNode() : left(nullptr), right(nullptr), parent(nullptr)
	{
		isVisited = false;
		isExplored = false;
		_key = 0;
		_value = 0;
	}
	TreeNode(const Key& key, const Value& val) : _key(key), _value(val), unique_hash(), left(nullptr), right(nullptr), parent(nullptr)
	{
		isVisited = false;
		isExplored = false
	}
	const Key& key()
	{
		return _key;
	}
	const Value& value()
	{
		return _value;
	}
	const string& hash()
	{
		return unique_hash;
	}
	bool setKey(const Key& key)
	{
		this->_key = key; return true;
	}
	bool setValue(const Value& value)
	{
		this->_value = value; return true;
	}
	std::string Nodehash()
	{
		return this->ComputeNodeHash();
	}
	TreeNode* Left()
	{
		return this->left;
	}
	TreeNode* Right()
	{
		return this->right;
	}
	TreeNode* Parent()
	{
		return this->parent;
	}
	~TreeNode()
	{
		delete left;
		delete right;
		delete parent;
	}
	bool setParentNode(TreeNode* node)
	{
		return true;			
	}
	bool setLeftNode(TreeNode* node)
	{
		this->left = node;
		return true;
	}
	bool setRightNode(TreeNode* node)
	{
		this->right = node;
		return true;
	}
	bool swap(TreeNode* first, TreeNode* second)
	{
		TreeNode* temp = new TreeNode();
		temp = first;
		first = second;
		second = temp;
		return true;
	}
	bool hasleft()
	{
		return this->left != nullptr;
	}
	bool hasright()
	{
		return this->right != nullptr;
	}
	bool hasparent()
	{
		return this->parent != nullptr;
	}
protected:
	std::string ComputeNodeHash()
	{
		HashObject(this->unique_hash);
		this->unique_hash = HashObject.stringize();
		return this->unique_hash;
	}
};

