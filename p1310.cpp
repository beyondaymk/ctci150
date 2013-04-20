//============================================================================
// Name        : p1310.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : write a C function that allocates a 2D array
//============================================================================
#include <iostream>
#include <string>
#include <map>

using namespace std;

int** my2DArray(int row, int column){
	size_t head = row*sizeof(int*);
	size_t data = row*column*sizeof(int);
	int** ptr = (int**)malloc(head+data);
	if(!ptr)							// after malloc, check the status
		return nullptr;
	int* buf = (int*)(ptr + row);		// here buf is the address for an int
	if( buf == (int*)(&ptr[row]) )		// ptr: int**; ptr+row: int**; ptr[row] int*;
		cout<<"buf == ptr[row]"<<endl;
	cout<<"size of int:\t"<<sizeof(int)<<endl;
	cout<<"size of int*:\t"<<sizeof(int*)<<endl;
	int b = 1;
	int c = 2;
	int d = 3;
	int a[10]={0};
	int e = 4;
	int f = 5;
	if(a+0 == a)
		cout<<"a+0 == a"<<endl;
	cout<<"size of a:\t"<<sizeof(a)<<endl;
	cout<<"size of a+0:\t"<<sizeof(a+0)<<endl;
	cout<<"a+0 as int:\t"<<(size_t)(a+0)<<endl;
	for(int i = 0; i<row; ++i){
		ptr[i] = buf + i*column;	// here it is i*column; not i*column*sizeof(int)
//		ptr[i] = ptr[row] + i*column;	// here it is i*column; not i*column*sizeof(int)
	}
	return ptr;
}

int main(int argc, char** argv)
{
	cout<<"Program starts:\n"<<endl;

	int** p = my2DArray(3,5);
	int i = 0;
	int j = 0;
	for(i=0; i<3; ++i)
		for(j=0; j<5; ++j)
			p[i][j] = i + j*j;

   	cout<<"\nProgram ENDs."<<endl;
    return 0;
}