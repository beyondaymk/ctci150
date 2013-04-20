#include "p0301_stack_template.h"

//template<typename T>
//MyStack<T>::MyStack():head(nullptr),size(0){
//}
//
//template<typename T>
//MyStack<T>::~MyStack(){
//}

template<typename T>
bool MyStack<T>::empty(){
	return 0==size;
}

template<typename T>
bool MyStack<T>::push(T d){
	Node* p = new Node(d);
	p->next = head;
	head = p;
	return true;
}

template<typename T>
T MyStack<T>::top(){
	return head->data;
}

template<typename T>
bool MyStack<T>::pop(T& d){
	Node* p = head;
	d = head->data;
	head = head->next;
	--size;
	delete p;
	return true;
}

template<typename T>
void MyStack<T>::destroy(){
	while(size--){
		Node* p = head;
		head = head->next;
		delete p;
	}
}
