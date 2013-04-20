//============================================================================
// Name        : p0204.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : sort linked list based on x
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

void sortX(Node* head, int x){
	if(head==nullptr)
		return;
	Node* pNode = head;
	vector<Node> small, big;
	while(head!=nullptr){
		head->data<x?small.push_back(Node(head->data)):big.push_back(Node(head->data));
		head = head->next;
	}
	head = pNode;
	small.insert(small.end(),big.begin(),big.end());
	for(auto n : small){
		head->data = n.data;
		head = head->next;
	}
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
	Node n1(5), n2(3), n3(2), n4(4), n5(1);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	Node* head = &n1;
	printList(head);
	sortX(head,n2.data);
	cout<<"After sorting based on value 3:"<<endl;
	printList(head);
	return 0;
}
