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
			printf("%3d", item);
		}
		cout << "\n";
	}
}

void printMatrix(vector<vector<char> > &arrays)
{
	cout << endl;
	for(const auto& array : arrays){
		for(const auto& item : array){
			printf(" %c ", item);
		}
		cout << "\n";
	}
}

void printLCSCommon(vector<vector<char> > &PosMatrix, const string& X, size_t i, size_t j)
{
	if(i == 0 || j == 0)
		return;
	if(PosMatrix[i][j] == 'S'){
		printLCSCommon(PosMatrix, X, i - 1, j - 1);
		cout << X[i - 1]; 
	} else if (PosMatrix[i][j] == 'X'){
		printLCSCommon(PosMatrix, X, i, j - 1);
	} else {
		printLCSCommon(PosMatrix, X, i - 1, j);
	}

}

void ComputeLCSMatrix(const string& X, const string& Y)
{
	vector<vector<int> > LCSMatrix;
	vector<vector<char> > PosMatrix;
	for(auto k = 0; k < X.size(); k++){
		LCSMatrix.emplace_back(vector<int>(Y.size(), 0));
		PosMatrix.emplace_back(vector<char>(Y.size(), '*') );
	}
	for(auto i = 1; i < X.size(); i++){
		for(auto j = 1; j < Y.size(); j++){
			if(X[i - 1] == Y[j - 1]){
				LCSMatrix[i][j] = 1 + LCSMatrix[i - 1][j - 1];
				PosMatrix[i][j] = 'S';
			}
			else{
				LCSMatrix[i][j] = std::max( LCSMatrix[i][j - 1], LCSMatrix[i - 1][j] );
				PosMatrix[i][j] = LCSMatrix[i][j - 1] > LCSMatrix[i - 1][j] ? 'X' : 'Y';
			}
		}
	}
	printMatrix(LCSMatrix);
	printMatrix(PosMatrix);
	cout << endl;
	cout << "Commmon Subsequence is : "; 
	printLCSCommon(PosMatrix, X, X.size() - 1, Y.size() - 1);
}

int main(void)
{
	string X = "ACCTCGATCGAACTCCGTACGGCTC";
	string Y = "ACTGACTAAAAGAAACAATACG";
	ComputeLCSMatrix(X, Y);
	return 0;
}