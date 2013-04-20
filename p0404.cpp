//============================================================================
// Name        : p0404.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Create a linked lists for nodes at each depth of a BST
//============================================================================
#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

#include "p0402_node.h"

void printWSF(Node* root){
	if(root==nullptr){
		cout<<"No node. Nothing to print. You are stupid!"<<endl;
		return;
	}
	queue<Node*> que;
	que.push(root);

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

void depthListDSF(Node* root, vector<list<Node*>>& vl, size_t d=1){
	if(!root)
		return;
	if(vl.size()<d){
		list<Node*> ln;
		vl.push_back(ln);
	}
	vl[d-1].push_back(root);
	depthListDSF(root->left, vl, d+1);
	depthListDSF(root->right, vl, d+1);
}

void depthListWSF(Node* root, vector<list<Node*>>& vl){
	if(!root)
		return;

	list<Node*>* ln = new list<Node*> ();
	ln->push_back(root);
	vl.push_back(*ln);

	for( size_t pLevel = 0, cLevel = pLevel + 1; pLevel < vl.size() ; ++pLevel, ++cLevel){
		for(auto it = vl[pLevel].begin(); it != vl[pLevel].end(); ++it){
			if( (*it)->left || (*it)->right ){
				if( vl.size() < cLevel+1 ){
					ln = new list<Node*> ();
					vl.push_back(*ln);
				}
				if( (*it)->left )
					vl[cLevel].push_back((*it)->left);
				if( (*it)->right )
					vl[cLevel].push_back((*it)->right);
			}
		}
	}

}

void printVectorList(vector<list<Node*>> &vl){
	int i = 1;
	for(vector<list<Node*>>::iterator it = vl.begin(); it != vl.end(); ++it, ++i){
			cout<<"Level: "<<i;
			for(auto it2 = it->begin(); it2 != it->end(); ++it2)
				cout<<"\t"<<(*it2)->data<<flush;
			cout<<endl;
		}
}

int main() {
	cout<<"Program running(程序开始):"<<endl;
	const size_t arraySize = 20;
	int a[arraySize];
	for(int i = 0; i<arraySize; ++i)
		a[i] = i+1;

	Node* root = arrayToBST(a,a+arraySize-1);

	vector<list<Node*>> vl;
	cout<<endl<<"This is width first search printout."<<endl<<endl;
	printWSF(root);
//	resetDSF(root);
	cout<<endl<<"This is in-order depth first search printout."<<endl<<endl;
	printInOrderDSF(root);
	cout<<endl<<"This is pre-order depth first search printout."<<endl<<endl;
	printPreOrderDSF(root);
	cout<<endl<<"This is post-order depth first search printout."<<endl<<endl;
	printPostOrderDSF(root);

	depthListDSF(root,vl);
	cout<<"\nThis is the lists from dSF: "<<endl;
	printVectorList(vl);

	vl.clear();

	depthListWSF(root,vl);
	cout<<"\nThis is the lists from WSF: "<<endl;
	printVectorList(vl);
	cout<<"\nThe END(程序结束)."<<endl<<endl;
	return 0;
}
