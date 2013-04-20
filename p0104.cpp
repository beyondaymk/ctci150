//============================================================================
// Name        : p0104.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : replace space in a string with '%20'
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

void replaceSpace(char* str)
{
	if(strlen(str)<2)
		return;
// len is used to keep the length upto the last non-space character.
// nSpace is the number of spaces in between the letters.
	size_t len(0),nSpace(0);
	char* endC(nullptr), *endS(nullptr);

	for(size_t i = 0, temp=0; str[i]!='\0'; ++i)
	{
		if(' '!=str[i] ){
			len = i;
			if( temp!=0 ){
				nSpace += temp;
				temp = 0;
			}
		}
		else
			++temp;
	}
//endC points to the location of the last character.
//endS points to the location including the extra spaces.
	endC = str + len;
	endS = endC + nSpace*2;

	for(; endC>str; --endC)
		if(*endC==' ')
		{
			*endS-- = '0';
			*endS-- = '2';
			*endS-- = '%';
		}
		else
			*endS-- = *endC;

	return;
}

int main() {
	char p1[] = "abcd asd  asd          ";
	cout<<"The original string is: "<<p1<<endl;
	replaceSpace(p1);
	cout<<"The converted string is: "<<p1<<endl;
	return 0;
}
