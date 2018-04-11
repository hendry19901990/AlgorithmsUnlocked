#include <algorithm>
#include <array>
#include <array>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <exception>
#include <fstream>
#include <future>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <mutex>
#include <numeric>
#include <queue>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <system_error>
#include <thread>
#include <tuple>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;
typedef std::vector<int> vector_int;

template<typename _type>
struct lessthan {
	bool operator() (_type a, _type b) const { return a < b; }
};
template<typename _type>
struct greaterthan {
	bool operator() (_type a, _type b) const { return a > b; }
};

template <typename _Type>
void make_Heap(_Type& con, size_t pos)
{
	size_t max = 0;
	size_t left = 2 * pos;
	size_t right = (2 * pos) + 1;
	if (con[left] > con[pos])
	{
		max = left;
	}
	else if (con[right] > con[pos])
	{
		max = right;
	}
	con[pos] = max;
	makeheap(con, max);
}

template <typename _Type>
void build_max_heap(_Type& con, size_t root)
{
	size_t i = con.size() / 2;
	for (; i >= 1; i--)
	{
		make_Heap(con, i);
	}
}

template <typename _Type>
_Type return_Max(_Type& con)
{
	return con.front();
}

template <typename _Type>
void delete_max(_Type& con)
{
	con.pop_back();
	build_max_heap(con, 0);
}

template <typename _Type>
void update_key(_Type& con, _Type& key, size_t index)
{
	con[index] = key;
	build_max_heap(con, 0);
}

template <typename _Type>
void heap_sort(_Type& con)
{
	// return Max
	// Delete Max
	// if(con.size() != 0)
	// {
	//	  heap_sort(con)
	// }
}

int main()
{
    // heapsort(vector -> v);
}