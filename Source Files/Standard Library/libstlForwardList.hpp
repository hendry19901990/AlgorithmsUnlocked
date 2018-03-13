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
#include <activation.h>
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> ii;
void reverse_Array(int *A, int N)
{
	int *first = A;
	int *last = A + N - 1;
	while (first < last)
	{
		swap(A[*first], A[*last]);
		first++; // Move the first index forward;
		last--; //Move the last index back;
	}
}
template <typename T>
void reverser(T& A, size_t N)
{
	T* f = A;
	T* l = A + N - 1;
	while (f < l)
	{
		swap(A[*f], A[*l]);
		f++;
		l--;
	}

}
void f(const vector<int>& v) {
	int r = 0;
	tr(v, it) {
		r += (*it)*(*it);
	}
}
int lists(int args, char** argv)
{
	return 0;
};