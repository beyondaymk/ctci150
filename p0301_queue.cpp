#include "p0301_queue.h"

bool MyQueue::empty() const{
	return size==0;
}

bool MyQueue::enQueue(int d){
	Node* p = new Node(d);
	if(!empty())
		tail->next = p;
	else
		head = p;

	tail = p;
	++size;
	return true;
}

bool MyQueue::deQueue(int &d){
	if(empty())
		return false;
	d = head->data;
	Node* p = head;
	head = head->next;
	delete p;
	--size;
	if(empty())
		tail = nullptr;
	return true;
}

size_t MyQueue::checkSize() const{
	return size;
}

bool MyQueue::destroy(){
	while(size--){
		Node* p = head;
		head = head->next;
		delete p;
	}
	tail = nullptr;
	return true;
}