#ifndef P0301_STACK_TEMPLATE
#define P0301_STACK_TEMPLATE

template<typename T>
class MyStack{
private:
	class Node{
		friend class MyStack<T>;
	private:
		T data;
		Node* next;
	public:
		Node(T d=0, Node* n=nullptr):data(d),next(n){
		}
	};

private:
	Node* head;
	size_t size;
public:
	//MyStack();
	//virtual ~MyStack();
	bool empty();
	bool push(T);
	T top();
	bool pop(T&);
	void destroy();
};

#endif  // define P0301_STACK_TEMPLATE