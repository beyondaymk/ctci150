//============================================================================
// Name        : p01.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Determine if a string has all unique characters.
// Description : What is no additional structures are allowed?
//============================================================================

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool stringUnique(const string& s)
{
	if ( s.length()>256 )
		return false;
// vector vb is used to track if the corresponding character is present.
	vector<bool> vb(256, false);
	for(char c : s)
		if (vb[c])
			return false;
		else
			vb[c] = true;

	return true;
}

int main() {
	string s;
	cout<<"Please input a string: "<<endl;
	getline(cin,s);
	cout<<"The string is: "<<s<<endl;
	cout<<"string s is unique?: \t"<<true<<"\t"<<stringUnique(s)<<endl;
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	return 0;
}
