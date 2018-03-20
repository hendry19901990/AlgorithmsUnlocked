#include <iostream>
#include <stdio.h>
#include <string.h>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <numeric>
#include <regex>
using namespace std;
#define sz(a) int((a).size()) 
#define pb push_back 
#define all(c) (c).begin(), (c).end()
#define present(c,x) ((c).find(x) != (c).end()) 
#define cpresent(c,x) (find(all(c),x) != (c).end()) 
#define tr(container, it) for(decltype(container.begin()) it = container.begin(); it != container.end(); it++)
/* Value type to typename */
/**
* We say X is a container type such as vector<int> list<int> vector<string> etc.
* X::value_type                Type T, element type
* X::reference                 T & refernce to an element of type T.
* X::const_reference           const T& a const refernce to an element of type T.
* X::iterator                  iterator type pointing to T, behves like type T*. Basically a pointer to T.
* X::const_iterator            iterator type pointing to const T. behaves like a const T*
* X::difference_type           Like a signed interger that tells the distance from one iterator to the other iterator.
* X::size_type                 Size of data objects. Unsigned int.
* */
typedef vector<int>::value_type value_type;
typedef vector<int>::reference VectorReference;
typedef vector<int>::const_reference  constVectorReferenece;
typedef vector<int>::iterator  Veciterator;
typedef vector<int>::reverse_iterator  reverse_iterator;
typedef vector<int>::const_iterator constVectorIterator;
typedef vector<int>::difference_type difference_type;
typedef vector<int>::size_type size_type;
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
int vector()
{
	std::vector<int> vec;
	std::vector<char> myvector;
	std::vector<int> vec2;
	std::vector<int> first;
	std::vector<int> second;
	do{
		cin >> input;
		myvector.push_back(input);
		input = input + 9;
		vec2.push_back(input);
	}while(input);
	first.assign(7, 100);
	auto it = first.begin() + 2;
	second.assign(it, first.end() - 1);
	int myints[] = {15,541,5,85,25,87,41,58,4,456,8,7,415};
	second.assign(myints, myints + 8);
	auto front  = myvector.front();
	auto back = myvector.back();
	myvector.at(3) = 90;
	auto iter = myvector.begin();
	auto const_iter = myvector.end();
	auto rev_iter = myvector.rbegin();
	cout << myvector.capacity() << myvector.size() << myvector.max_size() ;
	myvector.pop_back();
	myvector.swap(vec2);
	vec.reserve(1024);
	first.resize(10);
	second.resize(10,6); 
	int myarraynums[] = {584518,184127,183,1748658,18};
	auto last = myvector.end();
	myvector.insert(last, myarraynums, myarraynums + 3);
	int N = 5, M = 2;
	vector< vector<int> > Matrix(M, vector<int>(N, -1));
	vector<int> v(11, 0);
	for (auto i = 0; i <= 10; i++)
	{
		v[i] = (i + 1)*(i + 1);
	}
	for (auto i = 10; i > 0; i--)
	{
		v[i] -= v[i - 1];
	}
	bool is_notempty = !v.empty();
	vector<int> k;
	for (auto i = 0; i < 100; i *= 2)
	{
		v.push_back(i);
	}
	int elements_count = v.size();
	pair<string, pair<int, int> >	P;
	string s = P.first;
	int x = P.second.first;
	int y = P.second.second;
	/*Vector on polar coordinate system*/
	vector< pair< double, pair<int, int> > > coordinate_system(10);
	double polar_angle = coordinate_system[1].first;
	int x_coordinate = coordinate_system[1].second.first;
	int y_coordinate = coordinate_system[1].second.second;
};

