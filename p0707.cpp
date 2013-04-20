//============================================================================
// Name        : p0707.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find the kth number that has only prime factors like 3, 5 and 7
//============================================================================
#include <iostream>
#include <queue>
using namespace std;

int kthNum(int k){
	queue<int> q3,q5,q7;
	q3.push(3);
	q5.push(5);
	q7.push(7);
	int result=0;
	for(int i=0; i<k; ++i){
		if ( q3.front()<q5.front() && q3.front()<q7.front() ){
			result = q3.front();
			q3.pop();
			q3.push(result*3);
			q5.push(result*5);
			q7.push(result*7);
		}
		else if( q5.front()<q7.front() ){
			result = q5.front();
			q5.pop();
			q5.push(result*5);
			q7.push(result*7);
		}
		else{
			result = q7.front();
			q7.pop();
			q7.push(result*7);
		}
	}
	return result;
}

int main(){
	
	for(int i=1; i<20; ++i)
		cout<<"The "<<i<<"-th number is:\t"<<kthNum(i)<<endl;
	
}
