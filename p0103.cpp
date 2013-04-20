//============================================================================
// Name        : p0103.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : check if str1 is permutation of str2
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

bool permutation(const char* str1, const char* str2)
{
	if( strlen(str1) != strlen(str2) )
		return false;
	size_t len = strlen(str1);
	vector<int> vi(256,0);
// vector vi is used to track the number each character presents in the string.
	for( size_t i=0; i<len; ++i )
		++vi[str1[i]];

	for( size_t i=0; i<len; ++i )
		if(--vi[str2[i]] < 0)
			return false;
		
	return true;
}

int main() {
	char p1[] = "abcd a";
	char p2[] = "bad ac";
	char p3[] = "bac ac";
	cout<<"str1 is permutation of str2: "<<permutation(p1,p2)<<endl;
	cout<<"str1 is permutation of str3: "<<permutation(p1,p3)<<endl;
	return 0;
}
