//============================================================================
// Name        : p0203.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : delete a node in the middle of a singly linked list
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

void deleteMid(Node* node){
	if(node==nullptr)
		return;
	if(node->next==nullptr){
		cerr<<"Not a node in the Middle!!!"<<endl;
		return;
	}
	node->data = node->next->data;
	node->next = node->next->next;
	return;
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
	deleteMid(&n3);
	cout<<"After deleting the node 3:"<<endl;
	printList(head);
	return 0;
}
