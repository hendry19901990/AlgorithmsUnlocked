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
#include <functional>
#include <limits>
#include <mutex>
#include <thread>
using namespace std;
int range = 8;
std::vector<int> A;
std::random_device seed_device;
std::default_random_engine generator(seed_device());
std::uniform_int_distribution<int> random_attr(0, range);
auto random = std::bind(random_attr, generator);
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
template<typename T>
void PerformPrim(Graph<T> graph)
{
	vector<T> Q;
	/* Will Contain vertex,vertex pair, namely the edge of the min spanning tree. */
	unordered_map<T, T> min_spanning_tree;
	unordered_map<T, T> parent;
	unordered_map<T, int> key;
	/* Initialized Parent and Key array. All keys are inf, since not visited/computed yet. */
	for(const auto& vertex : graph.vertices) // O(V)
	{
		/* Put all the vertices in the queue */
		Q.emplace_back(vertex);
		key[vertex] = std::numeric_limits<int>::max();
		parent[vertex] = '\0';
	}
	/* Choose a random vertex as the start */
	auto start = graph.vertices[random()];
	key[start] = 0;
	while(!Q.empty())
	{
		/* Choose the vertex with the minimum Key amongst all available vertices */
		auto u = *std::min_element(Q.begin(), Q.end(),[&](char x, char y){return key[x] < key[y];});
		auto itr = remove(Q.begin(), Q.end(), u); // O(V)
		/* Remove the vertex and add it to minimum spanning tree. */
		Q.erase(itr, Q.end());
		if(parent[u] != '\0'){
			/* Since, we choose a vertex with the minimum key, the corresponding edge should be in the minimum spanning tree. */
			min_spanning_tree[u] = parent[u];
		}
		/* Consider all the adjecent vertices of the graph. We update the key value as we check-out each edge. */
		auto adjecent = graph.FindAdjecent(u); // O(E)
		/* We update the key of each vertex, it is the minimum we have seen so far. */
		for(auto &vertex : adjecent)
		{
			/* We do this check to see if vertex is in the queue or not.
			 * We dont want to update the key values of vertices not in consideration.
			 * They are not a part of the minimum spanning tree.
			 */
			if(find(Q.begin(), Q.end(), vertex.first) != Q.end()) // O(V)
			{
				if(vertex.second.weight < key[vertex.first]){
					parent[vertex.first] = u;
					key[vertex.first] = vertex.second.weight;
				}
			}
		}
	}
	/* We return the minimum spanning tree, O(V^2) */
	cout << "Minimum Spanning Tree : Prim Algorithm" << endl;
	for(const auto& item : min_spanning_tree)
	{
		cout << item.first << "---" << item.second << ". " << endl;
	}
}
template <typename T>
class Disjoint_set
{
	/* Store the relation in a HashTable */
	unordered_map<T, T> parent;
	unordered_map<T, int> rank; /* How many elements in set. How deep the tree is after union */
	std::vector<T> vset;
public:
	Disjoint_set() {}
	Disjoint_set(std::vector<T> &universe)
	{
		vset = universe;
		for(const auto& elem : vset)
		{
			/* A set of single-element sets */
			parent[elem] = elem;
			rank[elem] = 0;
		}
	}
	~Disjoint_set() {}
	void Insert_Set(std::vector<T> &universe)
	{
		vset = universe;
		for(const auto& elem : vset)
		{
			/* A set of single-element sets */
			parent[elem] = elem;
		}
	}
	T Find_set(T& item)
	{
		if(parent[item] == item)
		{
			return item;
		}
		else{
			Find_set(parent[item]);
		}
	}
	void Union_Set(T& set_a, T& set_b)
	{
		if(rank[set_a] > rank[set_b])
			parent[set_b] = set_a;
		else if(rank[set_a] < rank[set_b])
			parent[set_a] = set_b;
		else{
			parent[set_a] = set_b;
			++rank[set_b];
		}
	}
	void Make_set(T& vertex)
	{
		parent[vertex] = vertex;
		rank[vertex] = 0;
	}
};
template <typename T>
void PerformKruskal(Graph<T> graph)
{
	Disjoint_set<T> temp_set;
	std::vector<Edge<T> > Edges;
	for(const auto& item : graph.vertices)
	{
		temp_set.Make_set((char&)item);
	}
	std::sort(graph.edges.begin(), graph.edges.end(), [](Edge<T> x, Edge<T> y){return x.weight < y.weight;});
	for(const auto& e : graph.edges)
	{
		char a = temp_set.Find_set((char&)e.vertex1);
		char b = temp_set.Find_set((char&)e.vertex2);
		if(a != b){
			Edges.emplace_back(e);
			temp_set.Union_Set(a, b);
		}
	}
	cout << "Minimum Spanning Tree : Krushkal Algorithm" << endl;
	for(const auto& item : Edges)
	{
		cout << item.vertex1 << "---" << item.vertex2 << ", " << item.weight << ". " << endl;
	}
}
int main()
{
	Graph<char> g;
	char t[] = {'a','b','c','d','e','f','g','h','i'};
	g.vertices = vector<char>(t, t + sizeof(t)/sizeof(t[0]));
	g.edges.emplace_back(Edge<char>('a','b', 9));
	g.edges.emplace_back(Edge<char>('b','g', 54));
	g.edges.emplace_back(Edge<char>('a','g', 1));
	g.edges.emplace_back(Edge<char>('g','f', 72));
	g.edges.emplace_back(Edge<char>('f','d', 15));
	g.edges.emplace_back(Edge<char>('b','d', 7));
	g.edges.emplace_back(Edge<char>('f','i',  6));
	g.edges.emplace_back(Edge<char>('d','i', 48));
	g.edges.emplace_back(Edge<char>('d','h',  3));
	g.edges.emplace_back(Edge<char>('h','i', 45));
	g.edges.emplace_back(Edge<char>('d','e', 2));
	g.edges.emplace_back(Edge<char>('e','c', 5));
	g.edges.emplace_back(Edge<char>('a','c', random()));
	g.edges.emplace_back(Edge<char>('c','d', 32));
	g.edges.emplace_back(Edge<char>('b','f', 46));
	g.edges.emplace_back(Edge<char>('b','e', 9));
	PerformKruskal<char>(g);
	cout << endl;
	PerformPrim<char>(g);
	return 0;
}
