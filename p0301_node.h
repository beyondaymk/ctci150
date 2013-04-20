#ifndef P0301_NODE
#define P0301_NODE

class MyStack;
class MyQueue;

struct Node{
	friend class MyStack;
	friend class StackWithMin;
private:
	int data;
	Node* next;
	Node(int d=0, Node* p=nullptr):data(d),next(p){
	}
};

#endif	// define P0301_NODE