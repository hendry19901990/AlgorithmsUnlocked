#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <stdio.h>
#include <unordered_map>
#include <limits>
using namespace std;
int count = 0;
vector<vector<int> > SubsetSumsHelper;
void SubsbetSum(vector<vector<int> > &SubsetSumsHelper, const vector<int> &input, const int index_t, const int sum_t)
{
	SubsetSumsHelper[0][0] = 1;
	for(auto index = 1; index < index_t; index++){
		for(auto sum = 0; sum <= sum_t; sum++){
			SubsetSumsHelper[index][0] = 1;
			if(sum <= input[index - 1]){
				SubsetSumsHelper[index][sum] = SubsetSumsHelper[index - 1][sum];
			}
			else if(sum > input[index - 1])
			{
				SubsetSumsHelper[index][sum] = SubsetSumsHelper[index - 1][sum] || SubsetSumsHelper[index - 1][sum - input[index]];
			}
		}
	}
}

void FillPreFill(vector<vector<int> > &SubsetSumsHelper, const size_t rows, const size_t cols)
{
	vector<int> temp;
	for(auto i = 0; i < rows; i++){
		for(auto j = 0; j < cols + 1; j++){
			temp.emplace_back(0);
		}
		SubsetSumsHelper.emplace_back(temp);
		temp.erase(temp.begin(), temp.end());
	}
}

void printMatrix(vector<vector<int> > &arrays)
{
	for(const auto& array : arrays){
		for(const auto& item : array){
			printf("%3d", item);
		}
		cout << "\n";
	}
}

int main(void)
{
	vector<int> input = {2, 4, 6, 10};
	FillPreFill(SubsetSumsHelper, 4, 16);
	SubsbetSum(SubsetSumsHelper, input, 4, 16);
	printMatrix(SubsetSumsHelper);
	return 0;
}