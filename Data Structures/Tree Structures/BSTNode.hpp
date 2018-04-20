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
using namespace std;
/* Forward Class Defination */
template <typename Key, typename Value> class BinaryTree;
/* Generic Comparator */
template <typename _class_type>
class compare
{
public:
	bool operator()(const _class_type& first, const _class_type& second) {
		return first <= second;
	}
};
template <typename Key, typename Value>
class TreeNode
{
private:
	Key _key;
	Value _value;
	std::string unique_hash;
	TreeNode* left, right, parent;
	friend class BinaryTree<Key, Value>;
public:
	TreeNode() : left(nullptr), right(nullptr), parent(this) {}
	TreeNode(const Key& key, const Value& val) : _key(key), _value(val), unique_hash("e01956322"), left(nullptr), right(nullptr), parent(this) {}
	Key& operator*() { return this->_key; }
	const Key& key() { return _key; }
	const Value& value() { return _value; }
	const string& hash() { return unique_hash; }
	bool setKey(const Key& key) { this->_key = key; }
	bool setValue(const Value& value) { this->_value = value; }
	bool ComputeNodeHash() { this->unique_hash = "Function which computes the hash is called."; }
	TreeNode* left() { if (hasleft()) return this->left; }
	TreeNode* right() { if (hasright()) return this->right; }
	TreeNode* parent() { if (hasparent()) return this->parent; }
	~TreeNode() { delete left; delete right; }
protected:
	bool hasleft() { return this->left != nullptr; }
	bool hasright() { return this->right != nullptr; }
	bool hasparent() { return this->parent != nullptr; }
};