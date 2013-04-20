//============================================================================
// Name        : p1101.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Merge two sorted arrays
//============================================================================
#include <iostream>
#include <math.h>
#include "p11x1_myRandomInt.h"
using namespace std;

static const int MAX = 16;

void printArray(int a[], int length){
	for(int i=0; i<length; ++i)
		cout<<a[i]<<"  ";
	cout<<endl;
}

void merge(int a[], int first, int middle, int last, int arrSize){
	int* arr = new int[arrSize];
	for(int i = 0; i<arrSize; ++i)
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

void mergeSort(int a[], int first, int last, int arrSize){
	if(first < last){
		int middle = ( first + last ) / 2;
		mergeSort(a, first, middle, arrSize);
		mergeSort(a, middle+1, last, arrSize);
		merge(a, first, middle, last, arrSize);
	}
}

void mergeArrays(int a[], int b[], int aSize, int bSize){
	int current = aSize + bSize - 1;
	int aIndex = aSize - 1;
	int bIndex = bSize - 1;
	while(aIndex>=0 && bIndex>=0){
		if(a[aIndex]>=b[bIndex])
			a[current--] = a[aIndex--];
		else
			a[current--] = b[bIndex--];
	}
	while(bIndex>=0){
		a[current--] = b[bIndex--];
	}
}

int main(){
	int a[MAX],b[MAX/2];
	for(int i=0; i<MAX/2; ++i){
		a[i] = myRandomInt(1,30);
		b[i] = myRandomInt(6,26);
	}
	cout<<"Original arrays"<<endl;
	cout<<"Array a:\t";	printArray(a,MAX/2);
	cout<<"Array b:\t";	printArray(b,MAX/2);
	mergeSort(a,0,MAX/2-1,MAX/2);
	mergeSort(b,0,MAX/2-1,MAX/2);
	cout<<"After merge sort"<<endl;
	cout<<"Array a:\t";	printArray(a,MAX/2);
	cout<<"Array b:\t";	printArray(b,MAX/2);
	mergeArrays(a,b,MAX/2,MAX/2);
	cout<<"After merging b to the end of a"<<endl;
	cout<<"Array a:\t";	printArray(a,MAX);
	cout<<"Array b:\t";	printArray(b,MAX/2);

	return 0;
}
