//============================================================================
// Name        : p0102.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : reverse a null-terminated string
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void reverse(char* str)
{
	size_t len = strlen(str);

	if(len<2)
		return;
// pEnd points to the end of the string.
	char* pEnd = str+len-1;
// swap the values between start and end, then move both pointers to the middle of the string.	
	while(pEnd>str)
	{
		char temp = *pEnd;
		*pEnd = *str;
		--pEnd;
		*str = temp;
		++str;
	}
	
	return;
}

int main() {
	char pStr[] = "a b c d";
	cout<<"The original string is: "<<pStr<<endl;
	reverse(pStr);
	cout<<"The reversed string is: "<<pStr<<endl;

	string s1("0 1 2 3 4 5 6");
	cout<<"The original string is: "<<s1<<endl;
	reverse(const_cast<char*>(s1.c_str()));
	cout<<"The reversed string is: "<<s1<<endl;
	return 0;
}
