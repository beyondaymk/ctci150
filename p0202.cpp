//============================================================================
// Name        : p0202.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : find the k-th to the last element of a singly linked list
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct Node{
	int data;
	Node* next;
	Node(int d=0, Node* p=nullptr):data(d),next(p){
	}
};

Node* kthToLast(Node* head, int k){
	if(head==nullptr)
		return head;
	Node* last = head;
	for(int i=1; i<k; ++i){
		if(last->next!=nullptr)
			last = last->next;
		else
			return nullptr;
	}

	while(last->next!=nullptr){
		last = last->next;
		head = head->next;
	}
	return head;
}

void printList(Node* head){
	while(head!=nullptr){
		cout<<head->data<<"\t"<<flush;
		head = head->next;
	}
	cout<<endl;
}
int main() {
	Node n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	Node* head = &n1;
	printList(head);
	int k = 0;
	cout<<"Please input k:"<<endl;
	cin>>k;
	if(kthToLast(head,k)==nullptr){
		cout<<"k is too big"<<endl;
		return 0;
	}
	cout<<k<<"-th element to the last: "<<kthToLast(head,k)->data<<endl;
	return 0;
}
