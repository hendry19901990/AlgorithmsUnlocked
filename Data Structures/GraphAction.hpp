// Implemenating a graph data structure in C++
// Copyright Sumit Lahiri

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
enum class NodeColor
{
	Black, /*Not Visited*/
	Grey, /*Current Visibility*/
	Red, /*Disconnected*/
	Yellow, /*Node Down*/
	Green, /*Node is active*/
	Blue, /*All pair shortest path node*/
	Orange, /*Like a fruit*/
};
class Vertex
{
public:
	Vertex(std::string name, int weight = 1, int id = 1);
	Vertex(Vertex&&) {}
	Vertex& operator= (Vertex&&) { return *this; }
	virtual ~Vertex(){}
	const std::string& name() const { return _name; }
	int weight() const { return _weight; }
	bool setlevel(int s) noexcept { _level = s; return true; }
	int level() const { return _level; }
	int color() const { return (int)_color; }
	bool parent(Vertex* v) noexcept { _parent = v; return true; }
	Vertex* getparent() { return _parent; }
	bool visited(bool _set) noexcept { _is_visited = _set; return true; }
	bool parent_traversal(bool _set) noexcept { _is_parent_traversal = _set; return true; }
	bool connected(bool _set) noexcept { _is_connected = _set; return true; }
	bool convoluted_array(bool _set) noexcept { _is_convoluted_array = _set; return true; }
	bool is_visited() const { return _is_visited; }
	bool is_parent_traversal() const { return _is_parent_traversal; }
	bool is_connected() const { return _is_connected; }
	bool is_convoluted_array() const { return _is_convoluted_array; }
protected:
	int			_id;
	NodeColor	_color;
	std::string _name;
	int         _weight;
	bool		_is_visited;
	bool		_is_parent_traversal;
	bool		_is_connected;
	bool		_is_convoluted_array;
	int			_level;
	Vertex*		_parent;
};
Vertex::Vertex(std::string name, int weight, int id)
	: _name(std::move(name))
	, _weight(std::move(weight))
	, _id(std::move(id))
{
	_is_visited = false;
	_is_parent_traversal = false;
	_is_connected = true;
	_is_convoluted_array = false;
	_level = -1;
	_parent = nullptr;
	this->_color = NodeColor::Black;
}
using vertex = Vertex * ;
using vertex_list = std::set<std::pair<vertex, int> >;
using AdjacencyList = std::map<vertex, vertex_list>;
template <typename T>
void addEdge(T& graph, vertex u, vertex v, int&& weight)
{
	graph[u].insert(make_pair(v, weight));
	graph[v].insert(make_pair(u, weight));
}

std::deque<vertex> q;
AdjacencyList graph;
int GraphAction()
{
	Vertex a{ "a", 1255, 1 };
	Vertex z{ "z", 1262, 2 };
	Vertex c{ "c", 1254, 3 };
	Vertex s{ "s", 1232, 4 };
	Vertex x{ "x", 1278, 5 };
	Vertex d{ "d", 1652, 6 };
	Vertex f{ "f", 1451, 7 };
	Vertex v{ "v", 1965, 8 };
	addEdge(graph, &a, &s, 20);
	addEdge(graph, &s, &x, 49);
	addEdge(graph, &a, &z, 96);
	addEdge(graph, &x, &d, 54);
	addEdge(graph, &x, &c, 62);
	addEdge(graph, &d, &c, 112);
	addEdge(graph, &d, &f, 226);
	addEdge(graph, &c, &f, 315);
	addEdge(graph, &f, &v, 65);
	addEdge(graph, &c, &v, 85);
	cout << "Graph --> Adjacency list : " << endl;
	for (const auto& vrtxlist : graph)
	{
		cout << " Vertex : " << vrtxlist.first->name() << " Node Weight : " << vrtxlist.first->weight() << " is connected to :" << endl;
		for (const auto &vrtx : vrtxlist.second)
		{
			cout << "   " << vrtx.first->name() << " Edge-Weight : " << vrtx.second << " " << endl;
		}
	}
	s.setlevel(0);
	q.push_back(&s);
	while (!q.empty())
	{ 
		vertex u = q.front();
		u->visited(true);
		q.pop_front();
		for (const auto& w : graph[u])
		{
			if (w.first->level() == -1)
			{
				w.first->setlevel(u->level() + 1);
				cout << " Level : " << w.first->level() << " Node : " << w.first->name() << " Edge-Weight : " << w.second << endl;
				w.first->parent(u);
				q.push_back(w.first);
				w.first->visited(true);
			}
		}
	}
	return 0;
}