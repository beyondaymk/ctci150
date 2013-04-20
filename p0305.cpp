//============================================================================
// Name        : p0305.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Implement a queue using two stacks
//============================================================================
#include <iostream>
#include <stack>
using namespace std;

class QStack{
private:
	stack<int> si, so;
	size_t s;
public:
	bool empty ( ) const;
	size_t size ( ) const;
	int front ( );
	int back ( ) ;
	void push ( const int& );
	void pop ( );
	void transfer();
	void transferBack();
};

template <typename T>
void printStack(T s){
	while(!s.empty()){
		cout<<s.front()<<"\t"<<flush;
		s.pop();
	}
	cout<<endl;
}

int main() {
	cout<<"Program running:"<<endl;
	QStack qs;
	for(int i=1; i<6; ++i)
		qs.push(i);
	printStack(qs);

	return 0;
}

bool QStack::empty ( ) const{
	return si.empty() && so.empty();
}

size_t QStack::size ( ) const{
	return si.size() + so.size();
}

int QStack::front ( ){
	if(so.empty())
		transfer();
	return so.top();
}

int QStack::back ( ){
	if(si.empty())
		transferBack();
	return si.top();
}

void QStack::push ( const int& x ){
	si.push(x);
}

void QStack::pop ( ){
	if(so.empty())
		transfer();
	so.pop();
}

void QStack::transfer(){
	while(!si.empty()){
		so.push(si.top());
		si.pop();
	}
}

void QStack::transferBack(){
	while(!so.empty()){
		si.push(so.top());
		so.pop();
	}
}
