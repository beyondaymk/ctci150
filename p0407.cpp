//============================================================================
// Name        : p0407.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find the first common ancestor of two nodes in a binary tree
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

bool isChild(Node* root, Node* node){
	if(root==node)
		return true;
	if(root->left && root->right)
		return isChild(root->left,node) || isChild(root->right,node);
	if(root->left)
		return isChild(root->left,node);
	if(root->right)
		return isChild(root->right,node);
	return false;
}

Node* firstCommonAncestor(Node* root, Node* na, Node* nb){
	if( !isChild(root, na) || ! isChild(root, nb) )
		return nullptr;
	if( root == na && root == nb )
		return root;
	if( (isChild(root->left,na) && isChild(root->right,nb)) ||
		(isChild(root->left,nb) && isChild(root->right,na)) )
		return root;
	if( isChild(root->left,na) )
		return firstCommonAncestor(root->left,na,nb);
	else
		return firstCommonAncestor(root->right,na,nb);
}

Node* commonAncestorNotBad(Node* root, Node* na, Node* nb){
	if(!root)
		return nullptr;
	if( root==na && root==nb ){
		root->b = true;
		return root;
	}
	Node* x = commonAncestorNotBad(root->left,na,nb);
//	if( x && x!=na && x!=nb )
	if(x->b)
		return x;
	Node* y = commonAncestorNotBad(root->right,na,nb);
//	if( y && y!=na && y!=nb )
	if(y->b)
		return y;

	if( x && y ){
		root->b = true;
		return root;
	}
	else if ( root==na || root==nb ){
		root->b = x || y ? true : false;
		return root;
	}
	else
		return x ? x : y;
}

int main() {
	cout<<"Program running(程序开始):"<<endl;
	const size_t arraySize = 50;
	int a[arraySize];
	for(int i = 0; i<arraySize; ++i)
		a[i] = i+1;

	Node* root = arrayToBST_withParent(a,a+arraySize-1);

	vector<list<Node*>> vl;
	cout<<endl<<"This is width first search printout."<<endl<<endl;
	printWSF(root);

	depthListDSF(root,vl);
	cout<<"\nThis is the lists from dSF: "<<endl;
	printVectorList(vl);

	Node* na = root;
//	na = nullptr;
	Node temp;
	Node* nb = &temp;
	if(na)
		cout<<"na is:\t"<<na->data;
	if(nb)
		cout<<"\tnb is:\t"<<nb->data<<endl;
	if( firstCommonAncestor(root,na,nb) )
		cout<<"First Common Ancestor is:\t"<<firstCommonAncestor(root,na,nb)->data<<endl;
	else
		cout<<"Node was not found!"<<endl;

	if( commonAncestorNotBad(root,na,nb) )
		cout<<"First Common Ancestor BAD is:\t"<<commonAncestorNotBad(root,na,nb)->data<<endl;
	else
		cout<<"BAD Node was not found!"<<endl;

	cout<<"\nThe END(程序结束)."<<endl<<endl;
	return 0;
}
