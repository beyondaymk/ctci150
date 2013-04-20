//============================================================================
// Name        : p0905.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find out all the permutations of a string
//============================================================================
#include <iostream>
#include <vector>
#include <list>
#include <string>
using namespace std;

list<string> strPermu( string s ){
	list<string> ls;
	if( s.size()==0 )
		return ls;
	else if( s.size()==1 ){
		ls.push_back(s);
		return ls;
	}
	else{
		string s2 = s.substr(1);
		list<string> lst = strPermu( s2 );
		for(auto str:lst){
				for(size_t i=0; i<=str.size(); ++i){
					string temp(str);
					temp.insert(i, s.substr(0,1) );
					ls.push_back(temp);
				}
		}
	}
	return ls;
}

int main(){
	vector<list<string>> vls;
	string s = "abcd";
	
	int i = 1;
	for(auto str:strPermu( s ))
		cout<<i++<<"\t"<<str<<endl;
}
