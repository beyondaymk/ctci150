#ifndef P0401_NODE
#define P0401_NODE

class Node{
public:
	int data;
	bool b;
	Node* left;
	Node* right;
	Node(int d=0):data(d),b(false),left(nullptr),right(nullptr){
	}
};

#endif	// define P0401_NODE