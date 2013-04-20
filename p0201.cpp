//============================================================================
// Name        : p0201.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : remove duplicated nodes from unsorted linked list
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

void removeDup(Node* head){
	if(head==nullptr || head->next==nullptr)
		return;
	set<int> mySet;
	Node* pre = head;
	mySet.insert(head->data);
	head = head->next;
	while(head!=nullptr){
		if(mySet.count(head->data)==0){
			mySet.insert(head->data);
			pre = head;
		}
		else{
			pre->next = head->next;
		}
		head = head->next;
	}
}

void printList(Node* head){
	while(head!=nullptr){
		cout<<head->data<<"\t"<<flush;
		head = head->next;
	}
	cout<<endl;
}
int main() {
	Node n1(1), n2(2), n3(3), n4(1), n5(3);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	Node* head = &n1;
	printList(head);
	cout<<"After remove duplicates:"<<endl;
	removeDup(head);
	printList(head);
	return 0;
}
