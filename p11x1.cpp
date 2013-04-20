//============================================================================
// Name        : p11x1.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Quicksort
//============================================================================
#include <iostream>
#include <math.h>
#include "p11x1_myRandomInt.h"
using namespace std;

int partition(int* a, int left, int right);

void swap(int& a, int& b){
	int temp = a;
	a = b;
	b = temp;
	return;
}

void quickSort(int a[], int left, int right){
	int index = partition(a, left, right);
	if(left<index-1)				// here use (index-1)
		quickSort(a,left,index-1);	// here use (index-1)
	if(index<right)
		quickSort(a,index,right);
}

int partition(int a[], int left, int right){
	int mid = a[(left+right)/2];
	while(left<=right){				// here use (left<=right)
		while(a[left]<mid)	++left;
		while(mid<a[right])	--right;
		if(left<=right){			// here use (left<=right)
			swap(a[left],a[right]);
			++left;
			--right;
		}
	}
	return left;
}

void printArray(int a[], int length){
	for(int i=0; i<length; ++i)
		cout<<a[i]<<"  ";
	cout<<endl;
}

int main(){
	const int MAX = 3;
	int a[MAX];
	for(int i=0; i<MAX; ++i)
		a[i] = myRandomInt(1,20);
	printArray(a,MAX);
	quickSort(a,0,MAX-1);
	printArray(a,MAX);
	return 0;
}
