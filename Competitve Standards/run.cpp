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
