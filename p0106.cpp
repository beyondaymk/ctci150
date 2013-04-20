//============================================================================
// Name        : p0105.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : string compression
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void rotate( int (*iArr)[4], size_t m){
	size_t layer = m/2;
	size_t half = (m%2==0)? layer : (layer+1);
	for(size_t i=0; i<layer; ++i)
		for(size_t j=0; j<half; ++j){
			int temp = iArr[i][j];
			iArr[i][j] = iArr[m-j-1][i];
			iArr[m-j-1][i] = iArr[m-i-1][m-j-1];
			iArr[m-i-1][m-j-1] = iArr[j][m-i-1];
			iArr[j][m-i-1] = temp;
		}
}

int main() {
	//int** matrix = new int*[4];
	//for(int i = 0; i<4; ++i)
	//	matrix[i] = new int[4];
	int matrix[4][4];

	int n = 1;
	for(auto& i : matrix )
		for(auto& j : i)
			j = n++;

	for(auto const & i : matrix ){
		for(auto const & j : i)
			cout<<j<<'\t'<<flush;
		cout<<endl;
	}

	rotate(matrix, sizeof(matrix)/sizeof(*matrix));
	cout<<"After rotation of 90 degree:"<<endl;
	for(auto const & i : matrix ){
		for(auto const & j : i)
			cout<<j<<'\t'<<flush;
		cout<<endl;
	}
	return 0;
}
