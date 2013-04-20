//============================================================================
// Name        : p1108.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Define a data structure and method to find the rank of a given number
//============================================================================
#include <iostream>
#include <string>

using namespace std;

struct RankNode{
	int data;
	int left_num;
	RankNode* left;
	RankNode* right;

	void insert(int);
	int getRankNum(int);

	RankNode(int x=0) : data(x), left_num(0), left(nullptr), right(nullptr) {}
	virtual ~RankNode(){}
};

void RankNode::insert(int x){
	if(x<=data){
		if(left==nullptr)
			left = new RankNode(x);
		else
			left->insert(x);
		left_num++;
	}
	else{
		if(right==nullptr)			
			right = new RankNode(x);
		else
			right->insert(x);
	}
}

int RankNode::getRankNum(int x){
	if(data==x)
		return left_num;
	if(x<data && left!=nullptr)
		return left->getRankNum(x);
	if(x>data && right!=nullptr){
		int temp = right->getRankNum(x);
		return temp == -1 ? -1 : left_num+1+ temp;
	}
	return -1;
}

void track(RankNode* root, int x){
	if( root==nullptr )
		root = new RankNode(x);
	else
		root->insert(x);
}

int main(int argc, char** argv)
{

    return 0;
}