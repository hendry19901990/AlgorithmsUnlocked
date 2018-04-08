#include <iostream>
#include <tuple>
#include <type_traits>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cstring>
#include <string>
#include <cassert>
#include <cstdio>
#include <queue>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <array>
#include <cstdint>
#include <algorithm>
#include <numeric>
#include <future>
#include <initializer_list>
#include <mutex>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <ratio>
#include <chrono>
#include <thread>
#include <stack>
#include <array>
#include <utility>
#include <exception>
#include "hash.hpp"
#include "except.hpp"

/* #define */
auto start = std::chrono::high_resolution_clock::now();
#define bit(x, i) ( x & (1<<i) )  //select the bit of position i of x
#define lowbit(x) ( (x)&((x)^((x)-1)) ) //get the lowest bit of x
#define hBit(msb, n) asm("bsrl %1,%0" : "=r"(msb) : "r"(n)) //get the highest bit of x, maybe the fastest
#define MOD 1000000007
#define print(vec) for (const auto& i : vec) cout << i << endl;
#define fori(vec) for (const auto& i : vec) 
#define fill(vec,size) for (auto i = 0; i < size; i++) { vec.pb(i); }
#define input(ss, inputbuffer) while(cin.good()) { getline(cin, inputbuffer); ss << inputbuffer << endl; }
#define inputLL(j, vec) while(cin.good()) { cin >> j;  vec.pb(j); }
#define sz(a) int((a).size())
#define vect(T) std::vector<T>
#define stck(T) std::stack<T>
#define dq(T) std::deque<T>
#define q(T) std::queue<T>
#define arr(T) std::array<T>
#define bits(T) std::bitset<T>
#define SIZE 65536
#define itn int
#define mp make_pair
#define mt make_tuple
#define pb push_back 
#define pf push_front
#define popf pop_front
#define popb pop_back
#define max(a, b) (a < b ? b : a)
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define rev(A) std::reverse(A.begin(), A.end())
#define sort(A) std::sort(A.begin(),A.end())
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end())
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define forvec(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
#define abs(x) ( x < 0 ? (-x) : x) // big bug here if "-x" is not surrounded by "()"
using std::chrono::duration_cast;
using namespace std;
 
/* Templates */
template<class T> bool uin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool uax(T &a, T b) { return a < b ? (a = b, true) : false; }
template<class T> bool smaller(T &a, T &b) { return a < b ? true : false; }
template<class T> bool bigger(T &a, T &b) { return a > b ? true : false; }
template<class T, class U> modulo(T& a, U& b) { return a % b; }

/* Global Typedefs */
typedef double long_float;
typedef long long long_64;
typedef std::vector<long_64> vector_long;
typedef std::vector<long_64>::iterator long_iter;
typedef std::vector<long_64>::const_iterator c_long_iter;
typedef std::vector<int> vector_int;
typedef std::vector<int>::iterator int_iter;
typedef std::vector<int>::const_iterator c_int_iter;
typedef std::vector<string> vector_string;
typedef std::vector<string>::iterator string_iter;
typedef std::vector<string>::const_iterator c_string_iter;
typedef std::vector<char> vector_char;
typedef std::vector<char>::iterator char_iter;
typedef std::vector<char>::const_iterator c_char_iter;
typedef pair<int, int> pii;
typedef std::map<int, int> intmap;
typedef std::map<string, int> hashmap;
typedef std::vector< deque<int> > vector_queue;
typedef std::stringstream ss;

/* Global Variables */
class elem;
class type;
class GenericPointer;
enum class State
{
	Running,
	Wait,
	Suspended,
	HangUp,
	Terminated,
};
enum class PointerType
{
	RawPointer,
	UniquePtr,
	SharedPtr,
};
std::vector<int> autovector;
std::vector<string> hashvector;
std::stringstream global, input, output, dump, temp;
std::string text, word, line, substrg;
const long_64 bignumber = 1000000000;
std::array<int, SIZE> ARR;
static int count = 0;
static char ch = 'a';

/* Code Here */

int main(void)
{
	freopen("number_array.txt", "r", stdin);
	freopen("output_buffer.txt", "w", stdout);
	std::ios::sync_with_stdio(false);
	int i = 0, j = 0, k = 0;









































	auto end = std::chrono::high_resolution_clock::now();
	std::chrono::duration<double, std::milli> time = end - start;
	cerr << time.count() << " ms." << endl;
	return 0;
} 