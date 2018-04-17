#include <iostream>
#include <algorithm>
#include <array>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <initializer_list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <system_error>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
class Vertex
{
public:
	Vertex(std::string name, int weight = 1);
	Vertex(Vertex&&) {}
	Vertex& operator= (Vertex&&) {}
	virtual ~Vertex(){}
	const std::string& name() const { return _name; }
	int weight() const { return _weight; }
protected:
	std::string _name;
	int         _weight;
	bool		_is_visited;
	bool		_is_parent_traversal;
	bool		_is_connected;
	bool		_is_convoluted_array;
	int			_counter;
};
Vertex::Vertex(std::string name, int weight)
	: _name(std::move(name))
	, _weight(weight) 
{
	_is_visited = false;
	_is_parent_traversal = false;
	_is_connected = true;
	_is_convoluted_array = false;
	_counter = 0;
}
using vertex = Vertex * ;
using vertex_list = std::set<std::pair<vertex,int> >;
using AdjList = std::map<vertex, vertex_list>;
AdjList adjecencylist;
void addEdge(vertex u, vertex v, int&& w)
{
	adjecencylist[v];               
	adjecencylist[u].insert(make_pair(v, w));  
	adjecencylist[v].insert(make_pair(u, w));
}

int main()
{
	freopen("min-number-practice.in", "r", stdin);
	freopen("output_buffer.in", "w", stdout);
	std::ios::sync_with_stdio(false);
	Vertex v2{ "2",147 };
	Vertex v3{ "3" };
	Vertex v5{ "5" };
	Vertex v7{ "7" };
	Vertex v8{ "8" };
	Vertex v9{ "9" };
	Vertex v10{ "10" };
	Vertex v11{ "11" };
	addEdge(&v7, &v11, 84);
	addEdge(&v7, &v8, 856);
	addEdge(&v5, &v11, 14);
	addEdge(&v3, &v8, 54);
	addEdge(&v3, &v10, 541);
	addEdge(&v8, &v9, 112);
	addEdge(&v11, &v9, 226);
	addEdge(&v9, &v2, 412);
	addEdge(&v7, &v2, 65);
	addEdge(&v3, &v5, 122);
	addEdge(&v5, &v2, 14);
	addEdge(&v2, &v8, 123);
	addEdge(&v2, &v7, 147);
	addEdge(&v10, &v9, 996);
	addEdge(&v9, &v10, 121);
	addEdge(&v8, &v2, 85);
	addEdge(&v7, &v11, 84);
	addEdge(&v7, &v8, 856);
	addEdge(&v5, &v11, 14);
	addEdge(&v3, &v8, 54);
	addEdge(&v3, &v10, 541);
	addEdge(&v8, &v9, 112);
	addEdge(&v11, &v9, 226);
	addEdge(&v9, &v2, 412);
	addEdge(&v7, &v2, 65);
	addEdge(&v3, &v5, 122);
	addEdge(&v5, &v2, 14);
	addEdge(&v2, &v8, 123);
	addEdge(&v2, &v7, 147);
	addEdge(&v10, &v9, 996);
	addEdge(&v9, &v10, 124);
	addEdge(&v8, &v2, 85);
	addEdge(&v7, &v11, 84); // Repeated values will be added. 
	addEdge(&v7, &v8, 856);
	addEdge(&v5, &v11, 14);
	addEdge(&v3, &v8, 54);
	addEdge(&v3, &v10, 541);
	addEdge(&v8, &v9, 112);
	addEdge(&v11, &v9, 226);
	addEdge(&v9, &v2, 412);
	addEdge(&v7, &v2, 65);
	addEdge(&v3, &v5, 122);
	addEdge(&v5, &v2, 14);
	addEdge(&v2, &v8, 123);
	addEdge(&v2, &v7, 147);
	addEdge(&v10, &v9, 996);
	addEdge(&v9, &v10, 121);
	addEdge(&v8, &v2, 85);
	addEdge(&v7, &v11, 84);
	addEdge(&v7, &v8, 856);
	addEdge(&v5, &v11, 14);
	addEdge(&v3, &v8, 54);
	addEdge(&v3, &v10, 541);
	addEdge(&v8, &v9, 112);
	addEdge(&v11, &v9, 226);
	addEdge(&v9, &v2, 412);
	addEdge(&v7, &v2, 65);
	addEdge(&v3, &v5, 122);
	addEdge(&v5, &v2, 14);
	addEdge(&v2, &v8, 123);
	addEdge(&v2, &v7, 147);
	addEdge(&v10, &v9, 996);
	addEdge(&v9, &v10, 124);
	addEdge(&v8, &v2, 85);
	addEdge(&v7, &v11, 84);
	addEdge(&v7, &v8, 856);
	addEdge(&v5, &v11, 14);
	addEdge(&v3, &v8, 54);
	addEdge(&v3, &v10, 541);
	addEdge(&v8, &v9, 112);
	addEdge(&v11, &v9, 226);
	addEdge(&v9, &v2, 412);
	addEdge(&v7, &v2, 65);
	addEdge(&v3, &v5, 122);
	addEdge(&v5, &v2, 14);
	addEdge(&v2, &v8, 123);
	addEdge(&v2, &v7, 147);
	addEdge(&v10, &v9, 996);
	addEdge(&v9, &v10, 121);
	addEdge(&v8, &v2, 85);
	addEdge(&v7, &v11, 84);
	addEdge(&v7, &v8, 856);
	addEdge(&v5, &v11, 14);
	addEdge(&v3, &v8, 54);
	addEdge(&v3, &v10, 541);
	addEdge(&v8, &v9, 112);
	addEdge(&v11, &v9, 226);
	addEdge(&v9, &v2, 412);
	addEdge(&v7, &v2, 65);
	addEdge(&v3, &v5, 122);
	addEdge(&v5, &v2, 14);
	addEdge(&v2, &v8, 123);
	addEdge(&v2, &v7, 147);
	addEdge(&v10, &v9, 996);
	addEdge(&v9, &v10, 124);
	addEdge(&v8, &v2, 85);
	std::cout << "Graph --> Adjacency list :\n";
	for (const auto& list : adjecencylist)
	{
		cout << "Vertex : " << list.first->name() << " is connected to :" << endl;
		for (const auto &vrtx : list.second)
		{
			cout << "   " << vrtx.first->name() << " Weight : " << vrtx.second << " $" << endl;
		}
	}
    return 0;
}