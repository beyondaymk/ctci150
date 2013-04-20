//============================================================================
// Name        : p0107.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : clear columns and rows in MxN matrix, where there is 0 element
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void clearM( int iArr[][6], size_t m){
	vector<int> row;
	vector<int> col;
	for(int i=0; i<4; ++i){
		for(int j=0; j<6; ++j)
			if(0==iArr[i][j]){
				row.push_back(i);
				col.push_back(j);
			}
	}
	for(auto i : row)
		for(int j=0; j<6; ++j)
			iArr[i][j]=0;
	for(auto j : col)
		for(int i=0; i<4; ++i)
			iArr[i][j]=0;
}

int main() {
	int matrix[4][6];

	int n = 1;
	for(auto& i : matrix )
		for(auto& j : i)
			j = n++;
	matrix[2][3] = 0;
	matrix[3][1] = 0;
	for(auto const & i : matrix ){
		for(auto const & j : i)
			cout<<j<<'\t'<<flush;
		cout<<endl;
	}

	clearM(matrix, sizeof(*matrix)/sizeof(matrix[0][0]));
	cout<<"After clearance:"<<endl;
	for(auto const & i : matrix ){
		for(auto const & j : i)
			cout<<j<<'\t'<<flush;
		cout<<endl;
	}
	return 0;
}
