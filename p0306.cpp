//============================================================================
// Name        : p0306.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Sort a stack in accending order (with biggest on the top)
//============================================================================
#include <iostream>
#include <stack>
using namespace std;

template <typename T>
void printStack(T s){
	while(!s.empty()){
		cout<<s.top()<<"\t"<<flush;
		s.pop();
	}
	cout<<endl;
}

void sortStack(stack<int>&);
void sortStackNew(stack<int>&);

int main() {
	cout<<"Program running:"<<endl;
	stack<int> s;
	s.push(3);	s.push(5);	s.push(7);	s.push(2);	s.push(6);	s.push(1);	s.push(4);
	cout<<"Befroe sorting:"<<endl; printStack(s);
	sortStackNew(s);
	cout<<"After sorting:"<<endl; printStack(s);
	return 0;
}

void sortStack(stack<int>& s1){
	if(s1.size()<2)
		return;
	stack<int> s2, s3;
	while(!s1.empty()){
		int temp = s1.top();
		if( s2.empty() || temp>=s2.top() )
			s2.push(temp);
		else{
			while( !s2.empty() && temp<s2.top() ){
				s3.push(s2.top());
				s2.pop();
			}
			s2.push(temp);
			while(!s3.empty()){
				s2.push(s3.top());
				s3.pop();
			}
		}
		s1.pop();
	}
	while(!s2.empty()){
		s3.push(s2.top());
		s2.pop();
	}
	while(!s3.empty()){
		s1.push(s3.top());
		s3.pop();
	}
}

void sortStackNew(stack<int>& s1){
	stack<int> s2;
	while(!s1.empty()){
		int temp = s1.top();
		s1.pop();
		while( !s2.empty() && temp>s2.top() ){
			s1.push(s2.top());
			s2.pop();
		}
		s2.push(temp);
	}
	while(!s2.empty()){
		s1.push(s2.top());
		s2.pop();
	}
}
