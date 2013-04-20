//============================================================================
// Name        : p0206.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : find the start of a loop in a circular linked list
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
int length(Node* head){
	int len = 0;
	while(head!=nullptr){
		head = head->next;
		++len;
	}
	return len;
}

Node* findLoop(Node* head){
	Node* slow = head;
	Node* fast = head->next;
	while(fast!=slow){
		fast = fast->next->next;
		slow = slow->next;
	}
	slow = head;
	fast = fast->next;
	while(fast!=slow){
		fast = fast->next;
		slow = slow->next;
	}
	return slow;
}

void printList(Node* head){
	while(head!=nullptr){
		cout<<head->data<<"\t"<<flush;
		head = head->next;
	}
	cout<<endl;
}
int main() {
	Node n1(8), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	n7.next = &n4;

	Node* start = findLoop(&n1);
	cout<<"The data of loop start node is:"<<start->data<<endl;
	return 0;
}
