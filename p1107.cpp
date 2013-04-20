//============================================================================
// Name        : p1107.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find the largest number of people in a tower in a circus.
//============================================================================
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct HtWt{
	int height;
	int weight;
	bool isBefore(const HtWt& other) const{
		return this->height < other.height && this->weight < other.weight ;
	}
	HtWt(int h=0, int w=0):height(h),weight(w){}
	virtual ~HtWt(){}
};

typedef vector<HtWt> lst;

bool compare(const HtWt& a, const HtWt& b){
	if(a.height == b.height)
		return a.weight < b.weight;
	return a.height < b.height;
}

lst selectLonger(const lst &a, const lst &b){
	if(a.empty())
		return b;
	if(b.empty())
		return a;
	return a.size()>b.size() ? a : b ;
}

void longestList(const lst& myList, vector<lst>& solution, int x){
	if(x<0 || x>=myList.size())
		return;
	HtWt currentEle = myList[x];
	lst best;
	for( int i=0; i<x; ++i){
		if( myList[i].isBefore(myList[x]) )
			best = selectLonger(solution[i],best);
	}
	lst newList;
	if(!best.empty())
		newList.assign(best.cbegin(),best.cend());
	newList.push_back(currentEle);
	solution[x].assign(newList.cbegin(), newList.cend());
	longestList(myList, solution, x+1);
}

lst longestList(lst& myList){
	sort(myList.begin(),myList.end(),compare);
	auto solution = new vector<lst>(myList.size());
	int start = 0;
	longestList(myList, *solution, start);

	lst best;
	for( auto it = solution->cbegin(); it<solution->cend(); ++it){
		best = selectLonger(best, *it);
	}
	return best;
}

int main(int argc, char** argv)
{
	vector<HtWt> arrStr;
	
	arrStr.push_back(HtWt(3,4));
	arrStr.push_back(HtWt(4,2));
	arrStr.push_back(HtWt(5,4));
	arrStr.push_back(HtWt(1,1));
	arrStr.push_back(HtWt(2,5));
	std::cout << "arrStr contains:\n";
	for ( auto it = arrStr.begin(); it != arrStr.end(); ++it ){
		std::cout << " " << it->height <<"\t"<<it->weight<<endl;
	}
	std::cout << '\n';
	sort(arrStr.begin(),arrStr.end(),compare);
	std::cout << "After sorting:\n";
	for ( auto it = arrStr.begin(); it != arrStr.end(); ++it ){
		std::cout << " " << it->height <<"\t"<<it->weight<<endl;
	}
	std::cout << '\n';

	lst best = longestList(arrStr);
	std::cout << "The longest list is:\n";
	for ( auto it = best.begin(); it != best.end(); ++it ){
		std::cout << " " << it->height <<"\t"<<it->weight<<endl;
	}
	std::cout << '\n';
    return 0;
}