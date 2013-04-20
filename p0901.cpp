//============================================================================
// Name        : p0901.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : How many possilbe ways to run up n stairs
//============================================================================
#include <iostream>
using namespace std;
const int N = 1000;
int ways[N] = {0};

int runUp(int n){
	if( ways[n] != 0 )
		return ways[n];
	if( n==0 || n==1 )
		return 1;
	if( n>=3 )
		return ways[n] = runUp(n-3) + runUp(n-2) + runUp(n-1);
	else if( n==2 )
		return ways[n] = runUp(n-2) + runUp(n-1);
	return ways[n];
}


int main(){
	int n;
	cout<<"Please input n: "<<flush;
	while(cin>>n){
		if(n<0)
			break;
		cout<<"Ways of running up \t"<<n<<" stairs is:\t"<<runUp(n)<<endl;
		cout<<"Please input n: "<<flush;
	}
}
