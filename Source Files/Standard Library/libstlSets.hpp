#include <iostream>
#include <stdio.h>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <set>
#include <map>
#include <sstream>
#include <cstdio>
#include <string.h>

#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
template <typename _type>
struct comapre_less
{
	bool operator() (_type& a, _type& b) const
	{
		return (a < b) ? true : false;
	}
};
int setfunc()
{

}