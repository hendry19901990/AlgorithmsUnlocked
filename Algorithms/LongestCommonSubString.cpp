#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <stdio.h>
#include <algorithm> 
using namespace std;

void printMatrix(vector<vector<int> > &arrays)
{
	cout << endl;
	for(const auto& array : arrays){
		for(const auto& item : array){
			printf(" %2d ", item);
		}
		cout << "\n";
	}
}

pair<int, int> ComputeLongCommSubStr(const string& X, const string& Y)
{
	int result = 0, index_i = 0, index_j = 0;
	vector<vector<int> > LCSMatrix;
	for(auto k = 0; k < X.size() + 1; k++){
		LCSMatrix.emplace_back(vector<int>(Y.size() + 1, 0));
	}
	for(auto i = 1; i < X.size() + 1; i++){
		for(auto j = 1; j < Y.size() + 1; j++){
			if(X[i - 1] == Y[j - 1] && X[i - 1] != ' ' && Y[j - 1] != ' ' ){
				LCSMatrix[i][j] = 1 + LCSMatrix[i - 1][j - 1];
				if(LCSMatrix[i][j] > result){
					index_i = i;
					result = LCSMatrix[i][j];
				}
			}
			else{
				LCSMatrix[i][j] = 0;
			}
		}
	}
	pair<int, int> indices = std::make_pair(index_i - result, index_i - 1);
	return indices;
}

int main(void)
{
	string X = "susdgu eeasd eawddu mttitll sgdftdg";
	string Y = "12111 21 51 51 51 851 ";
	auto g = ComputeLongCommSubStr(X, Y);
	cout << endl << "Max Substring Match : " ;
	for(auto i = g.first; i <= g.second; i++)
	{
		cout << X[i];
	}
	cout << endl << "Max length Match : " << g.second - g.first + 1;
	return 0;
}