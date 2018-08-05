#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <stdio.h>
#include <unordered_map>
#include <limits>
using namespace std;

void printMatrix(vector<vector<int> > &arrays)
{
	for(const auto& array : arrays){
		for(const auto& item : array){
			printf("%3d", item);
		}
		cout << "\n";
	}
}

void ComputeLongestSubInc(const vector<int> &input)
{
	vector<vector<int> > L(input.size());
	L[0].emplace_back(input[0]); /* First Element is the LIS at index 0 */
	for(auto i = 1; i < input.size(); i++){
		for(auto j = 0; j < i; j++){
			if( (input[j] < input[i]) && (L[i].size() < L[j].size() + 1) )
			{
				L[i] = L[j];
			}
		}
		L[i].emplace_back(input[i]);
	}
	printMatrix(L);
}

int main(void)
{
	vector<int> input = {3, 2, 1, 5, 4, 5, 6, 9, 5, 95, 65, 62, 63,  54,  84, 41, 25, 62, 41, 12, 13, 15, 26, 29, 51, 66};
	ComputeLongestSubInc(input);
	return 0;
}