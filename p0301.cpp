//============================================================================
// Name        : p0301.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : use a single array to implement three stacks
//============================================================================
#include "p0301_stack.h"
#include "p0301_queue.h"

#include <iostream>
using namespace std;

	const int size = 100;
	int a[size*3] = {0};
	int index[3] = {-1,-1,-1};

int absIndex(int s);
bool empty(int s);
bool push(int s, int data);
bool pop(int s, int& data);
int peek(int s);

int main() {
	//cout<<"Program running:"<<endl;
	//MyStack s;
	//for(int i=1; i<6; ++i)
	//	s.push(i);

	//int d = 0;
	//for(int i=1; i<6; ++i){
	//	if(s.pop(d))
	//		cout<<d<<"\t";
	//}
	//cout<<endl;

	//MyQueue q;
	//for(int i=1; i<6; ++i)
	//	q.enQueue(i);

	//for(int i=1; i<6; ++i){
	//	if(q.deQueue(d))
	//		cout<<d<<"\t";
	//}
	//cout<<endl;
	for(int i=0; i<100; ++i){
		push(0, i);
		push(1, 2*i);
		push(2, 3*i);
	}
	cout<<"peek(0):"<<peek(0)<<endl;
	cout<<"peek(1):"<<peek(1)<<endl;
	cout<<"peek(2):"<<peek(2)<<endl;
	return 0;
}

int absIndex(int s){
	return(s*size+index[s]);
}

bool empty(int s){
	return index[s]==-1;
}

bool push(int s, int data){
	if( !(index[s]<size) )
		return false;
	++index[s];
	a[absIndex(s)] = data;
	return true;
}

bool pop(int s, int& data){
	if(empty(s))
		return false;
	data = a[absIndex(s)];
	--index[s];
	return true;
}

int peek(int s){
	if(empty(s))
		return false;
	return a[absIndex(s)];
}
