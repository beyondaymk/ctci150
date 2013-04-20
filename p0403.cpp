//============================================================================
// Name        : p0403.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Generate a binary search tree from an increasing array
//============================================================================
#include <iostream>
#include <array>
#include <queue>
using namespace std;

#include "p0402_node.h"

void printWSF(Node* root){
	if(root==nullptr){
		cout<<"No node. Nothing to print. You are stupid!"<<endl;
		return;
	}
	queue<Node*> que;
	que.push(root);
	/*while(!que.empty()){
		que.front()->b = true;
		cout<<"Visiting: "<<que.front()->data<<endl;
		if( que.front()->left && !que.front()->left->b )
			que.push(que.front()->left);
		if( que.front()->right && !que.front()->right->b )
			que.push(que.front()->right);
		que.pop();
	}*/

	while(!que.empty()){
		cout<<"Visiting: "<<que.front()->data<<endl;
		if( que.front()->left )
			que.push(que.front()->left);
		if( que.front()->right )
			que.push(que.front()->right);
		que.pop();
	}
}

void printInOrderDSF(Node* root){
	/*if(!root)
		return;
	if( root->left && !root->left->b)
		printInOrderDSF(root->left);
	if( !root->b){
		cout<<"Visiting: "<<root->data<<endl;
		root->b = true;
	}
	if( root->right && !root->right->b)
		printInOrderDSF(root->right);*/

	if(!root)
		return;
	if( root->left )
		printInOrderDSF(root->left);
	cout<<"Visiting: "<<root->data<<endl;
	if( root->right )
		printInOrderDSF(root->right);
}

void printPreOrderDSF(Node* root){
	if(!root)
		return;
	cout<<"Visiting: "<<root->data<<endl;
	if( root->left )
		printPreOrderDSF(root->left);
	if( root->right )
		printPreOrderDSF(root->right);
}

void printPostOrderDSF(Node* root){
	if(!root)
		return;
	if( root->left )
		printPostOrderDSF(root->left);
	if( root->right )
		printPostOrderDSF(root->right);
	cout<<"Visiting: "<<root->data<<endl;
}

void resetDSF(Node* root){
	if(!root)
		return;
	if( root->left )
		resetDSF(root->left);
	root->b = false;
	if( root->right )
		resetDSF(root->right);
}

//void arrayToBST(array<int,size_t> ary, iterator b,){
//}

Node* arrayToBST(int* beg, int* end){
	if(end<beg)
		return nullptr;
	int* mid = beg + (end-beg)/2;
	Node* root = new Node(*mid);
	if(mid>beg)
		root->left = arrayToBST(beg, mid-1);
	if(end>mid)
		root->right = arrayToBST(mid+1,end);
	return root;
}

int main() {
	cout<<"Program running(程序开始):"<<endl;
	
	array<int,20> ary;
	auto b = ary.begin();
	while(b!=ary.end()){
		ary.at(b-ary.begin()) = b-ary.begin() +1;
		++b;
	}

	int a[20];
	for(int i = 0; i<20; ++i)
		a[i] = i+1;

	Node* root = arrayToBST(a,a+20-1);
	cout<<endl<<"This is width first search printout."<<endl<<endl;
	printWSF(root);
//	resetDSF(root);
	cout<<endl<<"This is in-order depth first search printout."<<endl<<endl;
	printInOrderDSF(root);
	cout<<endl<<"This is pre-order depth first search printout."<<endl<<endl;
	printPreOrderDSF(root);
	cout<<endl<<"This is post-order depth first search printout."<<endl<<endl;
	printPostOrderDSF(root);

	cout<<"The END(程序结束)."<<endl;
	return 0;
}
