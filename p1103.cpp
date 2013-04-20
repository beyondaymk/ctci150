//============================================================================
// Name        : p1103.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Find an element in an sorted array that is rotated unknown times
//============================================================================
#include <iostream>
using namespace std;

#include <array>

const int sz = 10;
array<int,sz> arrStr = {5,5,5,5,5,5,6,3,5,5};

int findRotatedArr(const array<int,sz>& arrStr, const int value,
				   int first, int last){
// This function does NOT work for an array with identical elements.
	if(last<first)
		return -1;
	int mid = first + (last - first) / 2;
	if( value == arrStr[mid] )
		return mid;

	if ( value > arrStr[mid] ){
		if( arrStr[last] >= arrStr[mid] ){ // Be careful of the case "=" !!!
			if( arrStr[last] >= value )    // Be careful of the case "=" !!!
				return findRotatedArr(arrStr, value, mid+1, last);
			else
				return findRotatedArr(arrStr, value, first, mid-1);
		}else{
			return findRotatedArr(arrStr, value, mid+1, last);
		}
	}else{
		if( arrStr[first] <= arrStr[mid] ){
			if( arrStr[first] <= value )
				return findRotatedArr(arrStr, value, first, mid-1);
			else
				return findRotatedArr(arrStr, value, mid+1, last);
		}else{
			return findRotatedArr(arrStr, value, first, mid-1);
		}
	}
}

int findRotatedArr2(const array<int,sz>& arrStr, const int value,
				   int first, int last){
// This function works for an array with identical elements.
	if(last<first)
		return -1;
	int mid = first + (last - first) / 2;
	if( value == arrStr[mid] )
		return mid;

	if ( value > arrStr[mid] ){
		if( arrStr[last] > arrStr[mid] ){
			if( arrStr[last] >= value )
				return findRotatedArr2(arrStr, value, mid+1, last);
			else
				return findRotatedArr2(arrStr, value, first, mid-1);
		}else if( arrStr[last] < arrStr[mid] ){
			return findRotatedArr2(arrStr, value, mid+1, last-1);
		}else if( arrStr[last] == arrStr[mid] ){
			if( arrStr[first] == arrStr[mid] ){
				int temp = -1;
				return (temp=findRotatedArr2(arrStr, value, first+1, mid-1))==-1 ?
					findRotatedArr2(arrStr, value, mid+1, last-1) : temp;
			}else{
				return findRotatedArr2(arrStr, value, first, mid-1);
			}
		}
	}else{
		if( arrStr[first] < arrStr[mid] ){
			if( arrStr[first] <= value )
				return findRotatedArr2(arrStr, value, first, mid-1);
			else
				return findRotatedArr2(arrStr, value, mid+1, last);
		}else if( arrStr[first] > arrStr[mid] ){
			return findRotatedArr2(arrStr, value, first+1, mid-1);
		}else if( arrStr[first] == arrStr[mid] ){
			if( arrStr[last] == arrStr[mid] ){
				int temp = -1;
				return (temp=findRotatedArr2(arrStr, value, first+1, mid-1))==-1 ?
					findRotatedArr2(arrStr, value, mid+1, last-1) : temp;
			}else{
				return findRotatedArr2(arrStr, value, mid+1, last);
			}
		}
	}
	cout<<"This line should not be printed out."<<endl;
	return -1;
}

int findRotatedArr3(const array<int,sz>& arrStr, const int value,
				   int first, int last){
// This function works for an array with identical elements.
// This version is based on the methond in the CTCI150 book.
	if(last<first)
		return -1;
	int mid = first + (last - first) / 2;
	if( value == arrStr[mid] )
		return mid;

	if( arrStr[first] < arrStr[mid] ){
		if( value >= arrStr[first] && value < arrStr[mid] )
			return findRotatedArr3(arrStr, value, first, mid-1);
		else
			return findRotatedArr3(arrStr, value, mid+1, last);
	}else if( arrStr[first] > arrStr[mid] ){
		if( value >= arrStr[first] || value < arrStr[mid] )
			return findRotatedArr3(arrStr, value, first, mid-1);
		else
			return findRotatedArr3(arrStr, value, mid+1, last);
	}else if( arrStr[first] == arrStr[mid] ){
		if( arrStr[last] == arrStr[mid] ){
			int temp = -1;
			return (temp=findRotatedArr3(arrStr, value, first+1, mid-1))==-1 ?
				findRotatedArr3(arrStr, value, mid+1, last-1) : temp;
		}else
			return findRotatedArr3(arrStr, value, mid+1, last);
	}
	cout<<"This line should not be printed out."<<endl;
	return -1;
}


int findWrapper(const array<int,sz>& arrStr, int value){
	int first = 0;
	int last = arrStr.size()-1;
	return findRotatedArr3(arrStr, value, first, last);
}

int main(int argc, char** argv)
{
	std::cout << "arrStr contains:\n";
	for ( auto it = arrStr.begin(); it != arrStr.end(); ++it )
		std::cout << ' ' << *it;
	std::cout << '\n';
	int value = 0;
	cout<<"Input value: "<<flush;
	while(cin>>value){
		int index = findWrapper(arrStr, value);
		cout<<"\t\t\t The index is\t"<<index<<endl;
		cout<<"Input value: "<<flush;
	}
    return 0;
}