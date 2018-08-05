#include <iostream>
#include <vector>
#include <stdio.h>
#include <unordered_map>
#include <unordered_set>
#include <limits>
using namespace std;
unordered_map <int, pair<int, int> > matrix;
unordered_set<int> splits;
vector<vector<int> > value;
void Initialize(vector<vector<int> > &Cost, size_t n)
{
	vector<int> temp(n, -1);
	for(size_t i = 0; i < n; i++){
		value.emplace_back(temp);
	}
	for(size_t i = 0; i < n; i++){
		for(size_t j = 0; j < n; j++){
			i == j ? ( value[i][j] = 0 ) : ( value[i][j] = value[i][j] );
			((i == j + 1) || (j == i + 1)) ? ( value[i][j] = matrix[i].first * matrix[j].first * matrix[j].second, value[j][i] = matrix[i].first * matrix[j].first * matrix[j].second ) 
												: value[i][j] = value[i][j];
		}
	}
}

int minCostChain(const size_t i, const size_t j)
{
	if(i == j) 
		return 0;
	if((i == j + 1) || (j == i + 1)) 
		return value[i][j];
	if(value[i][j] > 0)
		return value[j][i];
	else if(value[i][j] == -1)
	{
		int cost = 0, min_cost = std::numeric_limits<int>::max();
		int k = i, index = 0;
		for( ; k < j; k++)
		{
			cost = minCostChain(i, k) + minCostChain(k + 1, j) + (matrix[i].first * matrix[j].first * matrix[j].second);
			if(min_cost > cost) { min_cost = cost; index = k; }
		}
		value[i][j] = min_cost;
		value[j][i] = min_cost;
		splits.emplace(index);
		return value[i][j];
	}
} 

void StoreMatrixChainInfo()
{
	matrix[0] = std::make_pair(1, 3);
	matrix[1] = std::make_pair(3, 4);
	matrix[2] = std::make_pair(4, 2);
	matrix[3] = std::make_pair(2, 5);
	matrix[4] = std::make_pair(5, 3);
	matrix[5] = std::make_pair(3, 8);
}

void printMatrix(vector<vector<int> > &arrays)
{
	for(const auto& array : arrays){
		for(const auto& item : array){
			cout << item << ", ";
		}
		cout << "\n";
	}

}

int main(void)
{
	StoreMatrixChainInfo();
	Initialize(value, 6);
	printMatrix(value);
	cout << minCostChain(0, 5) << "\n";
	printMatrix(value);
	for(const auto& split : splits) cout << split << ", " << "\n";
	return 0;
}