//============================================================================
// Name        : p0304.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Hanoi tower: move from the first tower to the last one
//============================================================================
#include <iostream>
#include <stack>
using namespace std;

stack<int> s1, s2, s3;
void printStack(stack<int> s){
	while(!s.empty()){
		cout<<s.top()<<"\t"<<flush;
		s.pop();
	}
	cout<<endl;
}

void Hanoi(stack<int>&,stack<int>&,stack<int>&,int);

int main() {
	cout<<"Program running:"<<endl;
	const int N = 7;
	for(int i=N; i>0; --i)
		s1.push(i);
	cout<<"Stack 1:"<<endl;
	printStack(s1);
	Hanoi(s1,s2,s3,N);
	cout<<"After move, stack 3:"<<endl;
	printStack(s3);

	return 0;
}

void Hanoi(stack<int>& s1,stack<int>& s2, stack<int>& s3, int n){
	/*if(n==1){
		s3.push(s1.top());
		s1.pop();
		return;
	}*/
	if(n<=0)
		return;
	Hanoi(s1,s3,s2,n-1);
	if(!s3.empty() && s1.top()>s3.top()){
		cerr<<"Illegal move!!!"<<endl;
		cerr<<"Trying to move "<<s1.top()<<" over "<<s3.top()<<endl;
	}
	s3.push(s1.top());
	s1.pop();
	Hanoi(s2,s1,s3,n-1);
	return;
}