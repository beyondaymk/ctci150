//============================================================================
// Name        : p1102.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Sort an array of strings so that anagram strings are next to each other
//============================================================================
#include <iostream>
using namespace std;

#include <array>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <list>

const int sz = 7;
array<string,sz> arrStr = {
"bad credit",
"third",
"dear",
"fifth",
"debit card",
"read",
"dare"};

void myStrSort(string& str){
	sort( str.begin(), str.end() );
}

void anagram(array<string,sz> &arrStr){
//	for_each( arrStr.begin(), arrStr.end(), myStrSort);
	for( auto & str : arrStr )
		sort( str.begin(), str.end() );
	sort( arrStr.begin(), arrStr.end() );

	std::cout << "\nAfter in-place sorting, arrStr contains:\n\n";
	for ( auto it = arrStr.begin(); it != arrStr.end(); ++it )
		std::cout << ' ' << *it;
	std::cout << endl;
}

void sortAnagram( array<string,sz> & arrStr ){
	unordered_map<string,list<string>> myMap;
	for( auto str : arrStr ){
		string myStr = str;
		sort( myStr.begin(), myStr.end() );
		if( myMap.find(myStr) == myMap.end() ){
			list<string> myList;
			myList.push_back(str);
			myMap[myStr] = myList;
		}
		else
			myMap[myStr].push_back(str);
	}
	std::cout << "\nAfter map sorting, arrStr contains:\n\n";
	for(auto &it = myMap.cbegin(); it != myMap.cend(); ++it )
		for( auto &myStr : (*it).second )
			cout<<myStr<<endl;
	cout<<endl;

}

int main(int argc, char** argv)
{
	std::cout << "arrStr contains:\n";
	for ( auto it = arrStr.begin(); it != arrStr.end(); ++it )
		std::cout << ' ' << *it;
	std::cout << '\n';
	sortAnagram(arrStr);
	anagram(arrStr);

    return 0;
}