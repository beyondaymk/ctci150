//============================================================================
// Name        : p0402.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Check if there is a route between two nodes in a directed grahp
//============================================================================
#include <iostream>
#include <queue>
using namespace std;

#include "p0401_node.h"

bool hasRouteDFS( Node* na, Node* nb ){
	if( na==nullptr || na->b==true )
		return false;
	na->b = true;
	if( na==nb ){
		cout<<na->data<<"\t";
		return true;
	}else{
		if( hasRouteDFS(na->left,nb) ||  hasRouteDFS(na->right,nb) ){
			cout<<na->data<<"\t";
			return true;
		}
	}
	return false;
}

bool hasRouteWFS( Node* na, Node* nb ){
	if( na==nullptr )
		return false;
	queue<Node*> que;
	que.push(na);
	while( !que.empty() ){
		if( que.front()==nb )
			return true;
		que.front()->b = true;
		if( que.front()->left != nullptr && !que.front()->left->b)
			que.push(que.front()->left);
		if( que.front()->right != nullptr && !que.front()->right->b)
			que.push(que.front()->right);
		que.pop();
	}
	return false;
}

int main() {
	cout<<"Program running(程序开始):"<<endl;
	
	Node root(0);
	Node a(1), b(2), c(3), d(4), e(5), f(6), g(7), h(8), i(9);
	root.left = &a;		 root.right = &b;
	a.left = &c;		 a.right = &e;
	b.left = &c;		 //b.right = &f;
	c.left = &root;
	d.left = &c;		d.right = &e;
	e.left = &c;		e.right = &d;
//	g.left = &h;
	
	//if( hasRouteDFS(&root,&d) )
	//	cout<<"There is a route by DFS."<<endl;
	//else
	//	cout<<"There is NOT a route by DFS."<<endl;

	if( hasRouteWFS(&root,&d) )
		cout<<"There is a route by WFS."<<endl;
	else
		cout<<"There is NOT a route by WFS."<<endl;

	cout<<"The END(程序结束)."<<endl;
	return 0;
}
