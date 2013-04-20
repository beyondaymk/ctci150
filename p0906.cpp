//============================================================================
// Name        : p0906.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Print out all the permutations of n pair parentheses
//============================================================================
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

void parenPermu(vector<string>& vs, string& s, int left, int right, int count){
	if(left<0 || left>right)
		return;
	if( left==0 && right==0 )
		vs.push_back(s);
	else{
		if(left>0){
			s[count] = '(';
			parenPermu(vs,s,left-1,right,count+1);
		}
		if(right>left){
			s[count] = ')';
			parenPermu(vs,s,left,right-1,count+1);
		}
	}
}
vector<string> parenPermuHelper(int n){
	string s(2*n,' ');
	vector<string> vs;
	parenPermu(vs, s, n, n,0);
	return vs;
}

int main(){
	vector<string> vs;
	int n = 4;
	vs = parenPermuHelper(n);
	
	int i=1;
	for(auto str:vs)
		cout<<i++<<"\t"<<str<<endl;
	return 0;
}
