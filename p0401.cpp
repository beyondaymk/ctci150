//============================================================================
// Name        : p0401.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Check if a tree is balanced
//============================================================================
#include <iostream>
using namespace std;

#include "p0401_node.h"

bool balancedTree(Node* node, int& Min, int& Max, int n=1 ){
	if(node==nullptr)
		return true;
	if( node->left==nullptr || node->right==nullptr ){
		if(Min==0 || Max==0){
			Min = n;
			Max = n;
		}else{
			Min = min(Min,n);
			Max = max(Max,n);
			if( (Max-Min) > 1 )
				return false;
		}
	}

	return (balancedTree(node->left,Min,Max,n+1)) && (balancedTree(node->right,Min,Max,n+1)) ;
}

int main() {
	cout<<"Program running(程序开始):"<<endl;
	
	Node root(0);
	Node a(1), b(2), c(3), d(4), e(5), f(6), g(7), h(8), i(9);
	root.left = &a;		 root.right = &b;
	a.left = &c;		 a.right = &d;
	b.left = &e;		 //b.right = &f;
	c.left = &g;

//	g.left = &h;
	
	int Min = 0;
	int Max = 0;
	if( balancedTree(&root,Min,Max) )
		cout<<"This tree is balanced."<<endl;
	else
		cout<<"This tree is NOT balanced."<<endl;

	cout<<"The END(程序结束)."<<endl;
	return 0;
}
