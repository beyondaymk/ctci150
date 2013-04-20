//============================================================================
// Name        : p1307.cpp
// Author      : Zhengwei
// Version     :
// Copyright   : Your copyright notice
// Description : Write a function the make a complete copy of passed node
//============================================================================
#include <iostream>
#include <string>
#include <map>

using namespace std;

class Node{
public:
	Node* left;
	Node* right;
};

typedef map<Node*, Node*> NodeMap;

Node* constructNodeMap(Node* cur, NodeMap& nodeMap){
	if(nullptr==cur)
		return cur;
	
	NodeMap::iterator it = nodeMap.find(cur);
	if(nodeMap.end()!=it)
		return nodeMap[cur];
//		return it->second;

	Node* temp = new Node;
	nodeMap[cur] = temp;
	temp->left = constructNodeMap(cur->left,  nodeMap);
	temp->right= constructNodeMap(cur->right, nodeMap);
	return temp;	
}

Node* constructNodeMap(Node* root){
	NodeMap nodeMap;
	return constructNodeMap(root, nodeMap);
}

size_t getPtrSize( char *ptr )
{
   return sizeof( ptr );
}

int main(int argc, char** argv)
{
	cout<<"Program starts:\n"<<endl;

	char szHello[] = "Hello, world!";

   cout  << "The size of a char is: "
         << sizeof( char )
         << "\nsizeof szHello\t" << szHello << " is: "
         << sizeof szHello
		 << "\nsizeof(szHello)\t" << szHello << " is: "
         << sizeof(szHello)
		 << "\nsizeof(&(*szHello))\t" << szHello << " is: "
         << sizeof(&(*szHello))
         << "\ngetPtrSize( szHello )\t"
         << getPtrSize( szHello ) << endl;

   	cout<<"\nProgram ENDs."<<endl;
    return 0;
}