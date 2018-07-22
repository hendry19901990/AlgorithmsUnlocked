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
std::mutex mutex_lock;
template <typename T>
class ListNode;

template <typename T>
class BSTNode;

template <typename T>
using node_ptr = std::shared_ptr<BSTNode<T> >;

template <typename T>
using list_ptr = std::shared_ptr<ListNode<T> >;

template <typename T>
class BSTNode
{
	T data_item;
	int left_height, right_height;
	node_ptr<T> left, right;
public:
	BSTNode() : data_item(0), left_height(0), right_height(0), left(nullptr), right(nullptr) { }
	BSTNode(T& data) : data_item(data), left_height(0), right_height(0), left(nullptr), right(nullptr) { }
	~BSTNode() {}
	T getdata() const;
	void setdata(T& item); 
	void addLeft(T&);
	void addRight(T&);
	void addItem(T& , const node_ptr<T>&);
	bool SearchMethod(T&, const node_ptr<T>&) const; 
};
template <typename T>
T BSTNode<T>::getdata() const
{
	return this->data_item;	
}
template <typename T>
void BSTNode<T>::setdata(T& item)
{
	this->data_item = item;	
}
template <typename T>
void BSTNode<T>::addLeft(T& item)
{
	this->left = std::make_shared<BSTNode<T> >(item);
}
template <typename T>
void BSTNode<T>::addRight(T& item)
{
	this->right = std::make_shared<BSTNode<T> >(item);
}
template <typename T>
void BSTNode<T>::addItem(T& item, const node_ptr<T> &root)
{
	auto data = root->getdata();
	if(item > data){
		if(root->right != nullptr){
			root->addItem(item, root->right);
		}
		else{
			root->addRight(item);
		}
	}
	if(item < data){
		if(root->left != nullptr){
			root->addItem(item, root->left);
		}
		else{
			root->addLeft(item);
		}
	}
}
template <typename T>
bool BSTNode<T>::SearchMethod(T& item, const node_ptr<T> &root) const
{
	auto data = root->getdata();
	if(item == data){
		cout << "Data found in BST. " << endl;
		return true;
	}
	else if ( (item > data) && root->right != nullptr){
		root->SearchMethod(item, root->right);
	}
	else if ( (item < data) && root->left != nullptr){
		root->SearchMethod(item, root->left);	
	}
	else
	{
		cout << "Not found " << endl; 
	} 
	return false;
}

template <typename T>
class ListNode
{
	T data;
	list_ptr<T> next, prev; 
public:
	ListNode() : data(), next(nullptr) { }
	ListNode(T& item) : data(item), next(nullptr) { }
	~ListNode() {}
	T getlistdata() const;
	void setlistdata(T& item);
	void PrintList(const list_ptr<T> &root);
	void addNode(T& item, const list_ptr<T> &root);
	void deleteNode(const list_ptr<T> &root);
	void UpdateNode(T& item, T& search);
	void SearchList(T& item); 
};
template <typename T>
T ListNode<T>::getlistdata() const 
{
	return this->data;
}
template <typename T>
void ListNode<T>::setlistdata(T& item)
{
	this->data = item;
}
template <typename T>
void ListNode<T>::addNode(T& item, const list_ptr<T> &root)
{
	list_ptr<T> temp = root;
	while(temp->next != nullptr) { temp = temp->next; }
	temp->next = std::make_shared<ListNode<int> >(item);
}
template <typename T>
void ListNode<T>::deleteNode(const list_ptr<T> &root)
{
	list_ptr<T> temp = root;
	while(temp->next->next != nullptr) { temp = temp->next; }
	temp->next->data = 0;
    temp->next = nullptr;
}
template <typename T>
void ListNode<T>::PrintList(const list_ptr<T> &root)
{
	list_ptr<T> temp = root;
	cout << endl << "List is : " << endl;
	while(temp->next != nullptr)
	{ 
		cout << "[ " << temp->data << " ]" << " --> ";
		temp = temp->next;
	}
}
class trienode;
using char_ptr = std::shared_ptr<trienode>;
class trienode
{
	bool isEnd;
	char node_char;
	int up_to_this;
	vector<char_ptr> next_char_array;
public:
	trienode() : isEnd(false), node_char('0'), up_to_this(0) 
	{
		for(auto i = 0; i < 27; i++)
		{
			next_char_array.emplace_back(nullptr);
		}
	}
	trienode(char &ch): isEnd(false), node_char(ch), up_to_this(0) 
	{
		for(auto i = 0; i < 27; i++)
		{
			next_char_array.emplace_back(nullptr);
		}
	}
	~trienode() {}
	bool addWord(const string&, char_ptr&);
	void deleteWord(const string&, char_ptr&);
	bool searchWord(const string&, char_ptr&);
};
bool trienode::addWord(const string &str, char_ptr &root)
{
	auto size = str.size();
	char_ptr temp = root;
	for(auto j = 0; j < size; j++)
	{
		char ch = str[j];
		if(temp->next_char_array[tolower(str[j]) - 'a'] == nullptr)
			temp->next_char_array[tolower(str[j]) - 'a'] = std::make_shared<trienode>(ch);
		++(temp->up_to_this);
		temp = temp->next_char_array[tolower(str[j]) - 'a'];
		temp->isEnd = false;
	}
	temp->isEnd = true;
	return temp->isEnd;
}
bool trienode::searchWord(const string &str, char_ptr &root)
{
	auto size = str.size();
	char_ptr temp = root;
	for(auto j = 0; j < size; j++)
	{
		if(temp->next_char_array[tolower(str[j]) - 'a']->node_char == str[j])
		{
			temp = temp->next_char_array[tolower(str[j]) - 'a'];	
		}
		else return false;
	}
	return true;
}
	unordered_map<int,string> mymap;
	unordered_map<int,string>::hasher hash_func = mymap.hash_function();
	mymap[9] = "Sumit Lahiri";
	mymap[14] = "Shuvradeep Lahiri";
	mymap[86] = "Google";
	mymap[23] = "Pradipta Lahiri";
	mymap[35] = "Pradipta Lahiri";
	mymap[49] = "Susovan Lahiri";
	mymap[52] = "Google";
	mymap[56] = "Microsoft";
	mymap[245] = "Apple";
	mymap[127] = "HackerEarth";
	mymap[364] = "HackerRank";
	mymap[1255] = "HackerRank";
	mymap[732] = "Microsoft";
	mymap.emplace (1701, "J.T. Kirk");
	mymap.emplace (18654, "Rowan Atkinson");
	unsigned size = mymap.bucket_count();
	for(const auto& x : mymap)
	{
		std::cout << "Element [" << x.first << " : " << x.second << "]";
    	std::cout << " is in bucket #" << mymap.bucket(x.first) << std::endl;
	}
   	for (unsigned i = 0; i < size; ++i)
   	{
    	std::cout << "bucket #" << i << " has " << mymap.bucket_size(i) << " elements.\n";
  	}
  	std::cout << "mymap's buckets contain:\n";
  	for (auto i = 0; i < mymap.bucket_count(); ++i)
  	{
    	std::cout << "bucket #" << i << " contains:";
    	for (auto start = mymap.begin(i); start != mymap.end(i); ++start)
    		std::cout << "{" << start->first << " : " << start->second << "}  ";
    	std::cout << std::endl;
  	}
  	stringstream ss;
	string str, newstr; 
	while(getline(std::cin, str))
	{
		ss << str;
	}
	str.clear();
	while(ss >> str) 
	{
		newstr += str;
	}
	regex pattern1("<([[:w:]]+)>");
	regex pattern2("</([[:w:]]+)>");
	sregex_iterator DOM_open_start(newstr.cbegin(), newstr.cend(), pattern1);
	sregex_iterator DOM_end_start(newstr.cbegin(), newstr.cend(), pattern2);
	sregex_iterator end;
	for(; DOM_open_start != end, DOM_end_start != end; DOM_open_start++, DOM_end_start++)
	{
		cout << endl;
		cout << "<parseTreeNode>" << endl;
		cout << "	<start> ";
		cout << " Start Match Tag ::" << DOM_open_start->str(0);
		cout << " 	</start> ";
		cout << endl << "	<DOMElem> "; 
		cout << "  Qualified DOM Element : " << DOM_open_start->str(1);
		cout << "	</DOMElem> "; 
		DOMElementsMap.emplace(i++, DOM_open_start->str(0));
		cout << endl << "	<end>";
		cout << " End Match Tag ::" << DOM_end_start->str(0);
		cout << "	</end> ";
		cout << endl << "	<DOMElem> "; 
		cout << "  Qualified DOM Element : " << DOM_end_start->str(1);
		cout << "	</DOMElem> " << endl; 
		DOMElementsMap.emplace(i++, DOM_end_start->str(0));
		cout << "</parseTreeNode>" << endl;
	}

vector<int> vect;
void process(vector<int> &A)
{
	for(auto i = 0; i < 60; i++)
		A.emplace_back(i);
}

void RandomEngine(size_t index, vector<int> &A)
{
	std::random_device rd;
	std::default_random_engine seed(rd());
	// mutex_lock.lock();
	for(auto i = 0; i < index; i++)
	{
		auto range = (static_cast<int>(A.size()) - 1) - i;
		std::uniform_int_distribution<int> swap_rand(0, range);
		swap(A[i], A[swap_rand(seed)]);
	}
	// mutex_lock.unlock();
}
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
	std::thread th1 (RandomEngine, 50);
  	std::thread th2 (RandomEngine, 30);
  	std::thread th3 (RandomEngine, 35);
  	th1.join();
  	th2.join();
  	th3.join();
	process(vect);
	while(true)
	{
		cout << endl;
		RandomEngine(35, vect);
		for(const auto& i : vect) cout << i << " ";
	}
	for(auto i = 0; i < 25; i++) A.emplace_back(random());
	std::make_heap(A.begin(), A.end());
	for (int i = 0; i < 25; ++i)
	{
		cout << "Extract Max : " << A.front() << endl;
		std::pop_heap(A.begin(), A.end() - i);	
	}
	A.push_back(200); A.push_back(8754); std::push_heap(A.begin(), A.end());
	for (int i = 0; i < 25; ++i)
	{
		cout << "Extract Max : " << A.front() << endl;
		std::pop_heap(A.begin(), A.end() - i);	
	}
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
int main()
{	
	PerformKruskal<char>(g);
	cout << endl;
	PerformPrim<char>(g);
	return 0;
}
