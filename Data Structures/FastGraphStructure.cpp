#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdio.h>
#include <regex>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <random>
#include <queue>
#include <stack>
#include <deque>
#include <set>
using namespace std;

template<typename T>
class Comp_fn
{
	bool reverse;
public:
	Comp_fn(const bool& t = false)
	{
		reverse = t;
	}
	bool operator() (const T& _lhs, const T& _rhs)
	{
		if (reverse) return (_lhs > _rhs);
		else return (_lhs < _rhs);
	}
};

template<typename T>
struct Edge
{
	T vertex1;
	T vertex2;
	long long weight;
	Edge(T a, T b, long long f) : vertex1(a), vertex2(b), weight(f) {}
	Edge(T a, T b) : vertex1(a), vertex2(b), weight(0) {}
	void setWeight(const long long& w) { this->weight = w; }
};

template<typename T>
struct Graph
{
	vector<T> vertices;
	vector<Edge<T> > edges;
	vector< pair<T, Edge<T> > > FindAdjecent(T u)
	{
		vector< pair<T, Edge<T> > > graph;
		for(Edge<T> e : edges)
		{
			if(e.vertex1 == u){
				graph.push_back( make_pair(e.vertex2, e));
			} else if (e.vertex2 == u){
				graph.push_back( make_pair(e.vertex1, e));
			}
		}
		return graph;
	}
};

int main()
{
	int range = 150;
	std::vector<int> A;
	std::random_device seed_device;
	std::default_random_engine generator(seed_device());
	std::uniform_int_distribution<int> random_attr(0, range);
	auto random = std::bind(random_attr, generator);
	std::priority_queue<char, std::vector<char>, Comp_fn<char> > dijkstra_graph_queue;
	Graph<char> g;
	char t[] = {'a','b','c','d','e','f','g','h','i'};
	g.vertices = vector<char>(t, t + sizeof(t)/sizeof(t[0]));
  /* Some Weights are assigned randomly. */
	g.edges.emplace_back(Edge<char>('a','b', random()));
	g.edges.emplace_back(Edge<char>('b','g', 54));
	g.edges.emplace_back(Edge<char>('a','g', random()));
	g.edges.emplace_back(Edge<char>('g','f', 72));
	g.edges.emplace_back(Edge<char>('f','d', 15));
	g.edges.emplace_back(Edge<char>('b','d', random()));
	g.edges.emplace_back(Edge<char>('f','i',  6));
	g.edges.emplace_back(Edge<char>('d','i', 48));
	g.edges.emplace_back(Edge<char>('d','h',  3));
	g.edges.emplace_back(Edge<char>('h','i', random()));
	g.edges.emplace_back(Edge<char>('d','e', -2));
	g.edges.emplace_back(Edge<char>('e','c', random()));
	g.edges.emplace_back(Edge<char>('a','c', random()));
	g.edges.emplace_back(Edge<char>('c','d', 32));
	g.edges.emplace_back(Edge<char>('b','f', 46));
	g.edges.emplace_back(Edge<char>('b','e', -random()));
  
	map<char, Edge<char> > VisitedMap;
	set<char> VisitedSet;
	stack<char> visit_in_prog_stack;
	queue<char> visit_in_prog_queue;
	cout << "Raw Graph is :  " << endl << endl;
	for(const auto& vertex : g.vertices)
	{
		cout << "Vertex : " << vertex << endl;
		auto res = g.FindAdjecent(vertex);
		for(const auto& item : res){
			cout << "Adjecent vertices : " << item.first  << " Edge weight : " << item.second.weight << endl;
		}
	}
	auto a = g.vertices[6];
	visit_in_prog_queue.push(a);
	VisitedSet.emplace(visit_in_prog_queue.front());
	/* BFS */
	cout << endl << "1. Breadth First Search : " << endl;
	while(!visit_in_prog_queue.empty())
	{
		cout << endl;
		cout << "Visited vertex : " << visit_in_prog_queue.front();
		auto next_vert = g.FindAdjecent(visit_in_prog_queue.front());
		visit_in_prog_queue.pop();
		for(const auto& item : next_vert)
		{
			auto it = VisitedSet.find(item.first);
			if(it == VisitedSet.end())
			{
				VisitedSet.emplace(item.first);
				visit_in_prog_queue.push(item.first);
				cout << "  Pushed vertex : " << visit_in_prog_queue.front();
			}
		}
	}
	a = g.vertices[0];
	VisitedSet.clear();
	visit_in_prog_stack.push(a);
	VisitedSet.emplace(visit_in_prog_stack.top());
	/* DFS */
	cout << endl << endl << "2. Depth First Search : " << endl;
	while(!visit_in_prog_stack.empty())
	{
		cout << endl;
		cout << "Visited vertex : " << visit_in_prog_stack.top();
		auto next_vert = g.FindAdjecent(visit_in_prog_stack.top());
		visit_in_prog_stack.pop();
		for(const auto& item : next_vert)
		{
			VisitedMap.emplace(item);
			auto it = VisitedSet.find(item.first);
			if(it == VisitedSet.end())
			{
				VisitedSet.emplace(item.first);
				visit_in_prog_stack.push(item.first);
				cout << "  Pushed vertex : " << visit_in_prog_stack.top();
			}
		}
	}
	cout << endl << endl << "Map is : " << endl << endl;
	for(const auto& y : VisitedMap){
			cout << "Adjecent vertices : " << y.first  << " Edge weight : " << y.second.weight << endl;
	}
	cout << endl;
	return 0;
}
