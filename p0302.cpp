//============================================================================
// Name        : p0302.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : stack with min() function
//============================================================================
#include "p0302_stackWithMin.h"

#include <iostream>
#include <climits>
using namespace std;

class StackWithMin : public MyStack{
public:
	MyStack minS;
	int minV();
	StackWithMin():minValue(INT_MAX){
	}
	bool push(int d);
	bool pop(int &d);
private:
	int minValue;
};

int StackWithMin::minV(){
	return minValue;
}

bool StackWithMin::push(int d){
	Node* p = new Node(d);
	p->next = head;
	head = p;
	++size;
	if(d<minValue){
		minS.push(d);
		minS.top(minValue);
	}
	return true;
}

bool StackWithMin::pop(int& d){
	if(empty())
		return false;
	d = head->data;
	Node* p = head;
	head = head->next;
	delete p;
	--size;
	if(d==minValue){
		minS.pop(minValue);
		minS.top(minValue);
		if(minS.empty())
			minValue = INT_MAX;
	}
	return true;
}

int main() {
	cout<<"Program running:"<<endl;
	StackWithMin sMin;
	sMin.push(5);
	sMin.push(3);
	sMin.push(6);
	sMin.push(2);
	sMin.push(1);
	int temp = 0;
	cout<<sMin.minV()<<"\t"<<endl;
	sMin.pop(temp); cout<<sMin.minV()<<"\t"<<endl;
	sMin.pop(temp); cout<<sMin.minV()<<"\t"<<endl;
	sMin.pop(temp); cout<<sMin.minV()<<"\t"<<endl;
	sMin.pop(temp); cout<<sMin.minV()<<"\t"<<endl;
	sMin.pop(temp); cout<<sMin.minV()<<"\t"<<endl;
	return 0;
}
