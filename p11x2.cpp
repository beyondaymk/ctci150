//============================================================================
// Name        : p11x2.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : MergeSort
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

void merge(int a[], int first, int middle, int last){
	int* arr = new int[MAX];
	for(int i = 0; i<MAX; ++i)
		arr[i] = a[i];
	int low = first;
	int high = middle+1;
	int current  = first;

	while(low<=middle && high<=last){
		if(arr[low]<=arr[high]){
			a[current] = arr[low];
			++low;
		}
		else {
			a[current] = arr[high];
			++high;
		}
		++current;
	}

	while(low<=middle)
		a[current++] = arr[low++];
	delete [] arr;
}

void mergeSort(int a[], int first, int last){
//	if(first < last){
		int middle = ( first + last ) / 2;
		if( first < middle )
			mergeSort(a, first, middle);
		if( middle+1 < last )
			mergeSort(a, middle+1, last);
		merge(a, first, middle, last);
//	}
}

int main(){
	int a[MAX];
	for(int i=0; i<MAX; ++i)
		a[i] = myRandomInt(1,20);
	printArray(a,MAX);
	mergeSort(a,0,MAX-1);
	printArray(a,MAX);
	return 0;
}
