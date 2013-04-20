//============================================================================
// Name        : p0406.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find the 'next' node of a given node in a BST.
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

Node* arrayToBST_withParent(int* beg, int* end){
	if(end<beg)
		return nullptr;
	int* mid = beg + (end-beg)/2;
	Node* root = new Node(*mid);
	if(*mid==3)
		cout<<"error!!!"<<endl;
	if(mid>beg){
		Node* temp = arrayToBST_withParent(beg, mid-1);
		root->left = temp;
		temp->parent = root;
	}
	if(end>mid){
		Node* temp = arrayToBST_withParent(mid+1,end);
		root->right = temp;
		temp->parent = root;
	}
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

bool isBST(Node* root, int big = INT_MAX, int small = INT_MIN){
	if(!root)
		return true;
	if(root->data > big || root->data < small)
		return false;
	//if( root->left && root->left->data > root->data )
	//	return false;
	//if( root->right && root->right->data < root->data )
	//	return false;
	return isBST(root->left, min(root->data, big), small) && isBST(root->right, big, max(root->data,small)) ;
}

Node* nextNodeofBST(Node* current){
	Node* result = nullptr;
	if( current->right ){
		result = current->right;
		if( result->left )
			while( result->left )
				result = result->left;
		return result;
	}
	result = current->parent;
	if(!result)
		return result;
	if(current==result->left)
		return result;
	while(result->parent && result==result->parent->right)
			result = result->parent;
	return result->parent;
}

int main() {
	cout<<"Program running(程序开始):"<<endl;
	const size_t arraySize = 7;
	int a[arraySize];
	for(int i = 0; i<arraySize; ++i)
		a[i] = i+1;

	Node* root = arrayToBST_withParent(a,a+arraySize-1);

	vector<list<Node*>> vl;
	cout<<endl<<"This is width first search printout."<<endl<<endl;
	printWSF(root);
	//resetDSF(root);
	//cout<<endl<<"This is in-order depth first search printout."<<endl<<endl;
	//printInOrderDSF(root);
	//cout<<endl<<"This is pre-order depth first search printout."<<endl<<endl;
	//printPreOrderDSF(root);
	//cout<<endl<<"This is post-order depth first search printout."<<endl<<endl;
	//printPostOrderDSF(root);

	depthListDSF(root,vl);
	cout<<"\nThis is the lists from dSF: "<<endl;
	printVectorList(vl);

	if(isBST(root))
		cout<<"YES, it is binary search tree."<<endl;
	else
		cout<<"NO, it is NOT binary search tree."<<endl;

	Node* node = root->left;
	Node* next = nextNodeofBST(node);
	cout<<"\nNode:\t"<<node->data;
	if(next)
		cout<<"\tNext:\t"<<next->data<<endl;
	else
		cout<<"\tThere is no next node."<<endl;
	
	node = root->right->left;	next = nextNodeofBST(node);
	cout<<"\nNode:\t"<<node->data;
	if(next)
		cout<<"\tNext:\t"<<next->data<<endl;
	else
		cout<<"\tThere is no next node."<<endl;

	node = root->right->right;	next = nextNodeofBST(node);
	cout<<"\nNode:\t"<<node->data;
	if(next)
		cout<<"\tNext:\t"<<next->data<<endl;
	else
		cout<<"\tThere is no next node."<<endl;

	node = root->left->right;	next = nextNodeofBST(node);
	cout<<"\nNode:\t"<<node->data;
	if(next)
		cout<<"\tNext:\t"<<next->data<<endl;
	else
		cout<<"\tThere is no next node."<<endl;

	node = root;	next = nextNodeofBST(node);
	cout<<"\nNode:\t"<<node->data;
	if(next)
		cout<<"\tNext:\t"<<next->data<<endl;
	else
		cout<<"\tThere is no next node."<<endl;

	cout<<"\nThe END(程序结束)."<<endl<<endl;
	return 0;
}
