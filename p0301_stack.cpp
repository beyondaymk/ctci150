#include "p0301_stack.h"
#include <iostream>
using namespace std;

bool MyStack::push(int d){
	Node* p = new Node(d);
	p->next = head;
	head = p;
	++size;
	return true;
}

bool MyStack::top(int& d){
	if(!this->empty()){
		d = head->data;
		return true;
	}
	return false;
}

bool MyStack::pop(int& d){
	if(empty())
		return false;
	d = head->data;
	Node* p = head;
	head = head->next;
	delete p;
	--size;
	return true;
}

bool MyStack::destroy(){
	while(size--){
		Node* temp = head;
		head = head->next;
		delete temp;
	}
	return true;
}