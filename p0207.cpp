//============================================================================
// Name        : p0207.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : check if a linked list is palindrome
//============================================================================

#include <iostream>
#include <vector>
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

bool isPalindromeVec(Node* head){
	vector<decltype(head->data)> v;
	while(head!=nullptr){
		v.push_back(head->data);
		head = head->next;
	}
	auto begin = v.begin();
	auto end = v.end();
	while(begin<end){
		if( *(--end) != *begin++ )
			return false;
	}
	return true;
}

bool isPalindromeRecurse(Node* head, int len, Node* &last){
	if(len==0  || head==nullptr ){
		last = head;
		return true;
	}
	if(len==1 && head!=nullptr ){
		last = head->next;
		return true;
	}
	//if(len==2 && head!=nullptr ){
	//	last = head->next->next;
	//	return head->data==head->next->data;
	//}

	if( isPalindromeRecurse(head->next, len-2, last) )
		if (head->data==last->data){
			last = last->next;
			return true;
		}

	return false;
}

void printList(Node* head){
	while(head!=nullptr){
		cout<<head->data<<"\t"<<flush;
		head = head->next;
	}
	cout<<endl;
}
int main() {
	Node n1(1), n2(2), n3(3), n4(4), n5(3), n6(2), n7(1);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;
	n5.next = &n6;
	n6.next = &n7;
	Node* head = &n1;
	Node* temp = nullptr;
	cout<<"Vectro method - The list is palindrome\t\t(1-YES 2-NO):\t"
		<<isPalindromeVec(head)<<endl;
	cout<<"Recursive method - The list is palindrome\t(1-YES 2-NO):\t"
		<<isPalindromeRecurse(head,length(head),temp)<<endl;
	return 0;
}
