//============================================================================
// Name        : p0900.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Dynamic programming for Fibonacci numbers
//============================================================================
#include <iostream>
using namespace std;
const int N = 10000;
int fibonacci[N] = {0};

int fib(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	return fib(n-1) + fib(n-2);
}

int fibDP(int n){
	if(n==0)
		return 0;
	if(n==1)
		return 1;
	if( fibonacci[n]!=0 )
		return fibonacci[n];
	fibonacci[n] = fibDP(n-1) + fibDP(n-2);
	return fibonacci[n];
}

int main(){
	int n;
	cout<<"Please input n: "<<flush;
	while(cin>>n){
		if(!n)
			break;
		cout<<"Fib of \t"<<n<<" is:\t"<<fib(n)<<endl;
		cout<<"Please input n: "<<flush;
		cin>>n;
		if(!n)
			break;
		cout<<"FibDP of \t"<<n<<" is:\t"<<fibDP(n)<<endl;
		cout<<"Please input n: "<<flush;
	}
}
