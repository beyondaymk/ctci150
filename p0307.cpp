//============================================================================
// Name        : p0307.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Design a data structure for dogs and cats
//============================================================================
#include <iostream>

#include "p0307_animal.h"

template <typename T>
void printStack(T s){
	while(!s.empty()){
		cout<<s.front()<<"\t"<<flush;
		s.pop();
	}
	cout<<endl;
}

int main() {
	cout<<"Program running:"<<endl;
	AnimalAdopter a;
	a.pushCat(Animal("c1"));
	a.pushDog(Animal("d2"));
	a.pushDog(Animal("d3"));
	a.pushCat(Animal("c4"));
	a.pushDog(Animal("d5"));
	a.popDog();
	a.pop();
	a.popCat();
	a.pop();
	a.popDog();
	return 0;
}
