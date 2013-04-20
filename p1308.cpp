//============================================================================
// Name        : p1308.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Smartpointer class template
//============================================================================
#include <iostream>
#include <string>
#include <map>

using namespace std;

template<class T> class SmartPointer{
private:
	T* objPtr;
	unsigned* objCount;
public:
	SmartPointer(T* ptr){
		objPtr = ptr;
		objCount = (unsigned*)malloc(sizeof(unsigned));
		*objCount = 1;
	}
	SmartPointer(SmartPointer<T>& ptr){
		objPtr = ptr.objPtr;
		objCount = ptr.objCount;
		if(ptr.objPtr)
			++(*objCount);
	}
	~SmartPointer(){
		if(*objCount>0)
			--(*objCount);
		if(*objCount==0){
			free(objPtr);
			free(objCount);
		}
	}
	void remove(){
		--(*objCount);
		if(*objCount==0){
			free objPtr;
		}
	}
	SmartPointer<T>& operator=(const SmartPointer<T>& rhs){
		if(this==&rhs)
			return *this;
		if(*objCount>0){
			remove();
			objPtr = rhs.objPtr;
			objCount = rhs.objCount;
			++(*objCount);
		}
		return *this;
	}
	T getValue(){
		return *objPtr;
	}
};

int main(int argc, char** argv)
{
	cout<<"Program starts:\n"<<endl;

	SmartPointer<int> p1 = (int*)malloc(sizeof(int));
	SmartPointer<int> p2 = p1;
	SmartPointer<int> p3(p1);
	

   	cout<<"\nProgram ENDs."<<endl;
    return 0;
}