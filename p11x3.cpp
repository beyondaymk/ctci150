//============================================================================
// Name        : p11x3.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Binary search
//============================================================================
#include <iostream>
#include <math.h>
#include "p11x1_myRandomInt.h"
using namespace std;

static const int MAX = 20;

void printArray(int a[], int length){
	for(int i=0; i<length; ++i)
		cout<<a[i]<<"  ";
	cout<<endl;
}

int binarySearch(int a[], int value, int first, int last){
	while(first<=last){
		int middle = (last + first) / 2;
		if(a[middle]==value)
			return middle;
		else if(a[middle]<value)
			first = middle+1;
		else
			last = middle-1;
	}
	return -1;
}

int binarySearchRecur(int a[], int value, int first, int last){
	if(first<=last){
		int middle = (last + first) / 2;
		if(a[middle]==value)
			return middle;
		else if(a[middle]<value)
			return binarySearchRecur(a, value, middle+1, last);
		else
			return binarySearchRecur(a, value, first, middle-1);
	}
	return -1;
}

int main(){
	int a[MAX];
	for(int i=0; i<MAX; ++i)
		a[i] = myRandomInt(1,20);
	printArray(a,MAX);
	int index, value;

	value = 7;
	index = binarySearch(a,value,0,MAX-1);
	if(index!=-1)
		cout<<value<<" is NO. "<<index<<endl;
	else
		cout<<value<<" was not found."<<endl;
	
	value = 1;
	index = binarySearch(a,value,0,MAX-1);
	if(index!=-1)
		cout<<value<<" is NO. "<<index<<endl;
	else
		cout<<value<<" was not found."<<endl;

	value = 7;
	index = binarySearchRecur(a,value,0,MAX-1);
	if(index!=-1)
		cout<<value<<" is NO. "<<index<<endl;
	else
		cout<<value<<" was not found."<<endl;
	
	value = 1;
	index = binarySearchRecur(a,value,0,MAX-1);
	if(index!=-1)
		cout<<value<<" is NO. "<<index<<endl;
	else
		cout<<value<<" was not found."<<endl;

	return 0;
}
