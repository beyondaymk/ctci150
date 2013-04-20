//============================================================================
// Name        : p0503.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find the next smallest and largest number of an integer with same number of 1 in binary
//============================================================================
#include <iostream>
using namespace std;

int getNext(int num){
	int one, zero;
	for(int i=0; i<32; ++i){
		if(num & 1<<i){
			one = i;
			break;
		}
	}
	for(int i=one+1; i<32; ++i){
		if((num & 1<<i) == 0){
			zero = i;
			break;
		}
	}
	num |= 1<<zero;
	num = num>>zero;
	num = num<<zero;
	int mask = 1<<(zero-one-1) - 1;
	num = num | mask;
	return num;
}

int getPrevious(int num){
	int one, zero;
	for(int i=0; i<32; ++i){
		if((num & 1<<i) == 0 ){
			zero = i;
			break;
		}
	}
	for(int i=zero+1; i<32; ++i){
		if(num & 1<<i){
			one = i;
			break;
		}
	}
	num = num - (1<<zero) - (1<<(one-zero-1)-1);
	return num;
}

int main(){
	int num = 6;
	cout<<"The smallest larger number is: "<<getNext(num)<<endl;
	cout<<"The largest smaller number is: "<<getPrevious(getNext(num))<<endl;
	cout<<"The smallest larger number is: "<<getNext(getPrevious(getNext(num)))<<endl;
	
}