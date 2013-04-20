//============================================================================
// Name        : p0908.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : How many ways to represent n cents in Quarter,Dime,Nickel,Cent
//============================================================================
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

int represent(int total, int denom){
	int next_denom = 0;
	switch(denom){
		case 25:
			next_denom = 10;
			break;
		case 10:
			next_denom = 5;
			break;
		case 5:
			next_denom = 1;
			break;
		case 1:
			return 1;
		default:
			return 0;
	}
	int ways = 0;
	for(int i = 0; total-i*denom>=0; ++i)
		ways += represent(total-i*denom, next_denom);
	return ways;
}

int main(){
	int t;
	cout<<"Please input the total number:"<<endl;
	while(cin>>t){
		cout<<"\t"<<represent(t,25)<<endl;
	}
	return 0;
}
