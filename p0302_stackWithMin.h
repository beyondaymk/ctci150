#ifndef P0302_STACKWITHMIN
#define P0302_STACKWITHMIN

#include "p0301_node.h"

class MyStack{
	friend class StackWithMin;
private:
	Node* head;
	size_t size;
public:
	MyStack():head(0),size(0){}
	virtual ~MyStack(){}
	bool empty(){
		return head==nullptr;
	}
	virtual bool top(int&);
	virtual bool push(int);
	virtual bool pop(int&);
	bool destroy();
};

#endif // define P0302_STACKWITHMIN
