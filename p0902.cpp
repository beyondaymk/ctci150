//============================================================================
// Name        : p0902.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : How many possilbe ways walk from (0,0) to (x,y)
//============================================================================
#include <iostream>
using namespace std;
const int N = 100;
int ways[N][N] = {0};

// point that can NOT step on
static int lx = 1;	
static int ly = 2;

int walk(int x, int y){
	if(x<0 || y<0 || (x==lx && y==ly))
		return 0;
	else if( x==0 || y==0 )
		return 1;
	else if( ways[x][y]!=0 )
		return ways[x][y];
	else{
		ways[x][y] = walk(x-1,y) + walk(x,y-1);
		return ways[x][y];
	}
}


int main(){
	int x,y;
	cout<<"Please input n: "<<flush;
	while(cin>>x>>y){
		if(x<0 || y<0)
			break;
		cout<<"Ways of walk to \t("<<x<<", "<<y<<")\t is:\t"<<walk(x,y)<<endl;
		cout<<"Please input n: "<<flush;
	}
}
