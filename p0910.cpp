//============================================================================
// Name        : p0910.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Build the tallest stack possible, with boxes
//============================================================================
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct Box{
	int h;
	int w;
	int d;
public:
	Box(int h_=0,int w_=0,int d_=0):h(h_),w(w_),d(d_){}
};

bool operator< (Box a, Box b){
	return (a.h<b.h && a.d<b.d && a.w<b.w);
}

bool compare(Box a, Box b){
	return a.h<b.h;
}

void maxHight(vector<Box>& vBox, vector<int>& vMax){
	vMax[0] = vBox[0].h;
	for(size_t i=1; i<vBox.size(); ++i){
		int m = vBox[i].h;
		for(size_t j=0; j<i; ++j){
			if( vBox[j] < vBox[i] && (vBox[i].h+vMax[j] > m) )
				m = vBox[i].h+vMax[j];
		}
		vMax[i] = m;
	}
}

int maxHelper(vector<Box>& vBox){
	vector<int> vMax(vBox.size(),0);
	maxHight(vBox,vMax);
	int maxH = 0;
	for(auto h:vMax){
		if(h>maxH)
			maxH = h;
	}
	return maxH;
}

int hightRecur(vector<Box>& vBox, int index){
	int maxHight = vBox[index].h;
	for(size_t i = 0; i<vBox.size(); ++i){
		if( vBox[i] < vBox[index] && (vBox[index].h+hightRecur(vBox,i) > maxHight) )
		maxHight = vBox[index].h+hightRecur(vBox,i);
	}
	return maxHight;
}

int recurHelper(vector<Box>& vBox){
	vector<int> vMax(vBox.size(),0);
	for(size_t i=0; i<vBox.size(); ++i){
		vMax[i] = hightRecur(vBox,i);
	}
	int maxH = 0;
	for(auto h:vMax){
		if(h>maxH)
			maxH = h;
	}
	return maxH;
}

int main(){
	vector<Box> vb;
	vb.push_back(Box(2,3,2));
	vb.push_back(Box(1,4,1));
	vb.push_back(Box(5,4,3));
	vb.push_back(Box(6,2,3));
	vb.push_back(Box(6,4,3));
	sort(vb.begin(), vb.end(), compare);
	cout<<"Max hight is:\t"<<maxHelper(vb)<<endl;
	cout<<"Recursive is:\t"<<recurHelper(vb)<<endl;
	return 0;
}
