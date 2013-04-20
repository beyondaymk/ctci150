//============================================================================
// Name        : p1309.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : write aligned malloc and free functions
//============================================================================
#include <iostream>
#include <string>
#include <map>

using namespace std;

void* alignedMalloc(size_t nBytes, size_t alignment){
	void* p1;
	void** p2;
	size_t offSet = alignment - 1 + sizeof(void*);
	p1 = (void*)malloc(nBytes + offSet);
	if(!p1)
		return nullptr;
	p2 = (void**)( (size_t(p1) + offSet) & ~(alignment-1));
	p2[-1] = p1;
	return p2;
}

void alignedFree(void* p2){
	void* p1 = ((void**)p2)[-1];
	free(p1);
}

int main(int argc, char** argv)
{
	cout<<"Program starts:\n"<<endl;

	void* p = alignedMalloc(1234, 256);
	((int*)(p))[2] = 3;
	alignedFree(p);

   	cout<<"\nProgram ENDs."<<endl;
    return 0;
}