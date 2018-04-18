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
	int count() const { return _counter; }
	int color() const { return (int)_color; }
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
	int			_counter;
};
Vertex::Vertex(std::string name, int weight, int id)
	: _name(std::move(name))
	, _weight(weight) 
	, _id(id)
{
	_is_visited = false;
	_is_parent_traversal = false;
	_is_connected = true;
	_is_convoluted_array = false;
	_counter = 0;
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
void BFS(AdjacencyList& graph)
{
	/*
	
	
	*/

}
std::deque<vertex> q;
AdjacencyList graph;
int main()
{
	Vertex v2{ "2" };
	Vertex v3{ "3" };
	Vertex v5{ "5" };
	Vertex v7{ "7" };
	Vertex v8{ "8" };
	Vertex v9{ "9" };
	Vertex v10{ "10" };
	Vertex v11{ "11" };
	addEdge(graph, &v7, &v11, 84);
	addEdge(graph, &v7, &v8, 856);
	addEdge(graph, &v5, &v11, 14);
	addEdge(graph, &v3, &v8, 54);
	addEdge(graph, &v3, &v10, 541);
	addEdge(graph, &v8, &v9, 112);
	addEdge(graph, &v11, &v9, 226);
	addEdge(graph, &v9, &v2, 412);
	addEdge(graph, &v7, &v2, 65);
	cout << "Graph --> Adjacency list : " << endl;
	for (const auto& vrtxlist : graph)
	{
		cout << "Vertex : " << vrtxlist.first->name() << " init : " << vrtxlist.first->color() << " is connected to :" << endl;
		for (const auto &vrtx : vrtxlist.second)
		{
			cout << "   " << vrtx.first->name() << " Weight : " << vrtx.second << "$" << endl;
		}
	}
	q.push_back(&v2);
	while (!q.empty())
	{
		vertex u = q.front();
		u->visited(true);
		q.pop_front();
		for (const auto& w : graph[u])
		{
			if (w.first->is_visited() != true)
			{
				cout << " Node : " << w.first->name() << " Edge-Weight : " << w.second << endl;
				q.push_back(w.first);
			}
			w.first->visited(true);
		}
	}
	return 0;
}