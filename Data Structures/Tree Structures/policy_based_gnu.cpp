#include <iostream>
#include <vector>
#include <cstring>
#include <string.h>
#include <cstdlib>
#include <stdexcept>
#include <memory>
#include <set>
#include <map>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#include <ext/pb_ds/tag_and_trait.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree< pair<int,int>, null_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> red_black_set;
typedef tree< pair<int,int>, mapped_type, less< pair<int,int> >, rb_tree_tag, tree_order_statistics_node_update> red_black_tree;
typedef tree< pair<int,int>, mapped_type, less< pair<int,int> >, splay_tree_tag, tree_order_statistics_node_update> splay_tree_set;

int main()
{
    return 0;
}