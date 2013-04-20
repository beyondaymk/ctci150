//============================================================================
// Name        : p0502.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Print a real number between 0 and 1 in binary representation
//============================================================================
#include <iostream>
using namespace std;

int main(){
	double d = 0.0;
	cout<<"Please input a real number between 0 and 1: ";
	cin>>d;
	cout<<"0.";
	int i=0;
	while(abs(d)>0.00001){
		d*=2;
		if(abs(d-1)>0.00001){
			cout<<1;
			d-=1;
		}
		else
			cout<<0;

		if(++i>32){
			cout<<"\nERROR"<<endl;
			return 1;
		}
	}
	//if(d>0)
	//	cout<<"\nERROR"<<endl;
}