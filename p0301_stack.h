#ifndef P0301_STACK
#define P0301_STACK

#include "p0301_node.h"

class MyStack{
private:
	Node* head;
	size_t size;
public:
	MyStack():head(0),size(0){}
	virtual ~MyStack(){}
	bool empty(){
		return head==nullptr;
	}
	bool top(int&);
	bool push(int);
	bool pop(int&);
	bool destroy();
};

#endif // define P0301_STACK
