//============================================================================
// Name        : p0105.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : string compression
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include "boost/lexical_cast.hpp"
using namespace std;

template <typename T>
int numDigits(T num){
	int digits(0);
	if(num<0)
		return 1;
	while(num){
		++digits;
		num /= 10;
	}
	return digits;
}

size_t compressedLength(char* str){
	size_t len(0);
	if(strlen(str)==0)
		return 0;
	else if(strlen(str)==1)
		return 2;
	char pre = str[0];
	size_t count = 1;
	for(size_t i=1; str[i]!='\0'; ++i)
	{
		if( str[i]==pre )
			++count;
		else{
			len += numDigits(count) + 1;
			count = 1;
			pre = str[i];
		}
	}
	len += numDigits(count) + 1;
	return len;
}

void compression(char* str)
{
	size_t len(0), repeat(0), comLen(0);
	len = strlen(str);
	if( len<compressedLength(str) )
		return;
	char* newP = new char[compressedLength(str)];
	char* newP2 = newP;
	char pre = str[0];
	size_t count = 1;
	for(size_t i=1; str[i]!='\0'; ++i)
	{
		if( str[i]==pre )
			++count;
		else{
			strcpy( newP2, (boost::lexical_cast<string>(count)).c_str() );
			newP2 += numDigits(count);
			*newP2++ = pre;
			count = 1;
			pre = str[i];
		}
	}
	strcpy( newP2, (boost::lexical_cast<string>(count)).c_str() );
	newP2 += numDigits(count);
	*newP2++ = pre;
	*newP2 = '\0';
	strcpy(str,newP);
	return;
}

int main() {
	char p1[] = "aabbbcdddd";
	cout<<"The original string is: "<<p1<<endl;
	cout<<"The numDigits of 23 is: "<<numDigits(23)<<endl;
	cout<<"The compressedLength of p1 is: "<<compressedLength(p1)<<endl;

	compression(p1);
	cout<<"The compressed string is: "<<p1<<endl;
	return 0;
}
