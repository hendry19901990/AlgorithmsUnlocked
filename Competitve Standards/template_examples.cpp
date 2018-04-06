#include <iostream>
#include <tuple>
#include <sstream>
#include <vector>
#include <cmath>
#include <ctime>
#include <bitset>
#include <cassert>
#include <cstdio>
#include <queue>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>
#include <numeric>
using namespace std;
typedef double *__attribute__((aligned(64))) aligned_double;
void maxArray(aligned_double __restrict x, aligned_double __restrict y) {
	for (int i = 0; i < 65536; i++) {
		x[i] = ((y[i] > x[i]) ? y[i] : x[i]);
	}
}
// Compile with -O3 -march=native to see autovectorization
// assumes input is aligned on 64-byte boundary and that
// length is a multiple of 64.
int testFunction(int* input, int length) {
	// Alignment hints supported on GCC 4.7+ and any compiler
	// supporting the appropriate builtin (clang 3.6+).
#ifndef __has_builtin
#define __has_builtin(x) 0
#endif
#if __GNUC__ > 4 \
    || (__GNUC__ == 4 && __GNUC_MINOR__ >= 7) \
    || __has_builtin(__builtin_assume_aligned)
	input = static_cast<int*>(__builtin_assume_aligned(input, 64));
#endif
#if _MSC_VER
	__assume((length & 63) == 0);
#else
	if (length & 63) __builtin_unreachable();
#endif
	int sum = 0;
	for (int i = 0; i < length; ++i) {
		sum += input[i];
	}
	return sum;
}
int main()
{
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
	int i, j = 0;
	std::vector<int> numbers;
	while (cin >> i)
	{
		numbers.push_back(i);
	}
	size_t sz = numbers.size();
	sort(numbers.begin(), numbers.end());
	for (const auto &i : numbers)
	{
		cout << i << "  " << j++;
		if (j >= 1 && j % 10 == 0)
		{
			cout << endl;
		}
	}
	cerr << endl << clock() << " ms" << endl;
	return 0;
}