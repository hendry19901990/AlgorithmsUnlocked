#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <stdio.h>
#include <unordered_map>
#include <limits>
using namespace std;
vector<vector<int> > ProfitMatrix;

void KnapsackMatrixInit(vector<vector<int> > &ProfitMatrix, const size_t items_nums, const size_t knapsack_weight)
{
	vector<int> temp;
	for(auto i = 0; i < items_nums; i++){
		for(auto j = 0; j < knapsack_weight + 2; j++){
			temp.emplace_back(0);
		}
		ProfitMatrix.emplace_back(temp);
		temp.erase(temp.begin(), temp.end());
	}
}

void KnapsackMatrixSolver(vector<vector<int> > &ProfitMatrix, const vector<int> &weights, const vector<int> &profits, const size_t items_nums, const size_t knapsack_weight)
{
	for(auto i = 0; i < items_nums; i++){
		for(auto j = 0; j < knapsack_weight + 2; j++){
			if((weights[i] < j)){
				ProfitMatrix[i + 1][j] = (profits[i] + ProfitMatrix[i][j - weights[i]] > ProfitMatrix[i][j]) ? profits[i] + ProfitMatrix[i][j - weights[i]] :  ProfitMatrix[i][j];
			}
		}	
	}
}

void printMatrix(vector<vector<int> > &arrays)
{
	for(const auto& array : arrays){
		for(const auto& item : array){
			printf("%4d", item);
		}
		cout << "\n";
	}
}

int main(void)
{
	vector<int> weights = {1, 3, 4, 8, 6, 9, 12, 14, 19, 7, 25, 36, 44, 31, 34, 39, 51, 45, 30, 41, 66, 95, 100};
	vector<int> profits = {10, 22, 35, 4, 2, 7, 48, 115, 6, 58, 67, 92, 73, 45, 110, 154, 25, 32, 114, 41, 52, 120};
	size_t items_nums = profits.size();
	size_t knapsack_weight = 45;
	KnapsackMatrixInit(ProfitMatrix, items_nums, knapsack_weight);
	KnapsackMatrixSolver(ProfitMatrix, weights, profits, items_nums, knapsack_weight);
	printMatrix(ProfitMatrix);
	return 0;
}