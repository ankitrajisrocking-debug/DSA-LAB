#include <bits/stdc++.h>
using namespace std;

struct Node{
	char data;
	Node* next;
};

void push( Node*& top, char c){
	Node* n = new Node{ c, top};
	top = n;

}

char pop( Node*& top) {
	char c = top-> data;
	Node* temp = top;
	top = top-> next;
	delete temp;
	return c;
}

int main(){
	string s;
	Node* top = NULL;
	cout<< "Enter String: ";
	cin>> s;
	
	for( char c : s) 
		push ( top, c);
	
	cout<< "Reversed String: ";
	while( top) 
		 cout<< pop( top);
		
	return 0;
}

