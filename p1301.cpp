//============================================================================
// Name        : p1301.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Print the last N lines of a file
//============================================================================
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int N = 15;

void printLastNLines(char* inputFile){
	fstream file(inputFile);
	string str[N];
	int sz = 0;

	while(file.good()){
		getline(file,str[sz%N]);
		++sz;
	}

	int start = sz>N ? sz%N : 0;
	int count = min(sz, N);

	for( /*volatile */ int i = 0; i<count; ++i){
		cout<<i<<"\t"<<str[(start+i)%N]<<endl;
	}
}

int main(int argc, char** argv)
{
	cout<<"Program starts:\n"<<endl;
	printLastNLines("p1108.cpp");
	cout<<"\nProgram ENDs."<<endl;
    return 0;
}