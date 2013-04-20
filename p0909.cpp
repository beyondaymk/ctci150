//============================================================================
// Name        : p0909.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : How many ways to fill one 8-queen chessboard
//============================================================================
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

static const int SIZE = 8;
int row[SIZE];
int cnt = 0;

void printChess(){
	cout<<cnt<<"\t";
	for(int i=0; i<SIZE; ++i)
		cout<<" "<<row[i];
	cout<<endl;
}
bool check(int r, int c){
	for(int i = 0; i<r; ++i){
		if( c==row[i] || (r+c)==(i+row[i]) || (r-c)==(i-row[i]) )
			return false;
	}
	return true;
}

void search(int r, int c){
	row[r] = c;
	if(r==SIZE-1){
		++cnt;
		printChess();
	}
	for(int i=0; i<SIZE; ++i){
		if(check(r+1, i))
			search(r+1,i);
	}
}

int main(){

	int num = 0;
	for(int i=0; i<SIZE; ++i)
		search(0,i);
	cout<<"cnt = "<<cnt<<endl;
	return 0;
}
