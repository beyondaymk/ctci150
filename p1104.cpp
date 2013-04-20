//============================================================================
// Name        : p1104.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find a string in a sorted array of strings which is interspersed with empty strings.
//============================================================================
#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef vector<string>::const_iterator cIter;

cIter findString(const vector<string>& arrStr, const string value, cIter first, cIter last){
	if(last<first)
		return arrStr.cend();
	cIter mid = first + (last - first) / 2;

	if( *mid=="" ){
		cIter left = mid;
		cIter right = mid;
		while(true){
			if(left<first && right>last)
				return arrStr.cend();
			else if(left>=first && *left!=""){
				mid = left;
				break;
			} else if(right<=last && *right!=""){
				mid = right;
				break;
			}
			--left;
			++right;
		}
	}

	if( *mid == value )
		return mid;
	else if( mid->compare(value) < 0 )
		return findString(arrStr, value, mid+1, last);
	else
		return findString(arrStr, value, first, mid-1);
	
}

int findWrapper(const vector<string>& arrStr, const string value){
	if( arrStr.empty() || value.empty() || value=="" )
		return -1;
	
	auto first = arrStr.cbegin();
	auto last = arrStr.cend()-1;
	auto it = findString(arrStr, value, first, last);
	return it==arrStr.cend()? -1 : it-first;
}

int main(int argc, char** argv)
{
	vector<string> arrStr;
	arrStr.push_back("afirst");	arrStr.push_back("bsecond");
	arrStr.push_back("");		arrStr.push_back("");
	arrStr.push_back("cthird");
	arrStr.push_back("");
	arrStr.push_back("dforth");
	arrStr.push_back("");
	arrStr.push_back("efifth");
	arrStr.push_back("");

	std::cout << "arrStr contains:\n";
	for ( auto it = arrStr.begin(); it != arrStr.end(); ++it ){
		if(*it=="")
			std::cout << " space";
		else
			std::cout << " " << *it;
	}
	std::cout << '\n';
	string value;
	cout<<"Input value: "<<flush;
	while(cin>>value){ // ctrl + z to end the input.
		int index = findWrapper(arrStr, value);
		cout<<"\t\t\t The index is\t"<<index<<endl;
		cout<<"Input value: "<<flush;
	}
    return 0;
}