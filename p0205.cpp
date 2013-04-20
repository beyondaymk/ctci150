//============================================================================
// Name        : p0205.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : add two numbers presented in linked lists
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

Node* addInt(Node* n1, Node* n2){
	if(n1==nullptr && n2==nullptr)
		return nullptr;
	if(n1==nullptr)
		return n2;
	if(n2==nullptr)
		return n1;

	Node* head = new Node();
	Node* p = head;
	p->data = (n1->data + n2->data)%10;
	int carry = (n1->data + n2->data)/10;;
	while(n1->next!=nullptr || n2->next!=nullptr || carry!=0){
		p->next = new Node();
		p = p->next;
		int d1=0, d2=0;
		if(n1->next!=nullptr){
			n1 = n1->next;
			d1 = n1->data;
		}
		if(n2->next!=nullptr){
			n2 = n2->next;
			d2 = n2->data;
		}
		p->data = (d1+d2+carry)%10;
		carry = (d1+d2)/10;;
	}

	return head;
}
// If pointer is expected to be modified, reference to pointer should be used !!
int addInvertInt(Node* n1, Node* n2, Node* &sum){
	if(n1==nullptr && n2==nullptr)
		return 0;
	sum = new Node();

	int s = n1->data + n2->data + addInvertInt(n1->next, n2->next, sum->next);
	sum->data = s%10;
	return s/10;
}
void fillup(Node* &head, int n){
	while(n-->0){
		Node* p = new Node(0);
		p->next = head;
		head = p;
	}
	return;
}
Node* addInvertHelper(Node* n1, Node* n2){
	int carry=0;
	Node* head=nullptr;
	if(n1!=nullptr || n2!=nullptr){
		int len1 = length(n1);
		int len2 = length(n2);
		(len1>len2) ? fillup(n2,len1-len2) : fillup(n1,len2-len1);
		Node* sum=nullptr;
		carry = addInvertInt(n1,n2,sum);
		if(carry!=0){
			head = new Node(1);
			head->next = sum;
		}
		else
			head = sum;
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
	Node n1(8), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
	n1.next = &n2;
	n2.next = &n3;

	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;

	Node* head1 = &n1;
	Node* head2 = &n4;
	Node* sum = nullptr;
	cout<<"List 1 is:"<<endl;
	printList(head1);
	cout<<"List 2 is:"<<endl;
	printList(head2);
	sum = addInt(head1,head2);
	cout<<"The sum of above two integers is:"<<endl;
	printList(sum);

	cout<<endl<<"List 1 is:"<<endl;
	printList(head1);
	cout<<"List 2 is:"<<endl;
	printList(head2);
	sum = addInvertHelper(head1,head2);
	cout<<"The sum of above two inverted integers is:"<<endl;
	printList(sum);
	return 0;
}
