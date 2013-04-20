#ifndef P0301_QUEUE
#define P0301_QUEUE

#include "p0301_node.h"

class MyQueue{
private:
	Node* head;
	Node* tail;
	size_t size;
public:
	MyQueue():head(0),tail(0),size(0){
	}
	~MyQueue(){
	}
	bool enQueue(int);
	bool deQueue(int&);
	bool destroy();
	bool empty() const;
	size_t checkSize() const;
};


#endif	// define P0301_QUEUE