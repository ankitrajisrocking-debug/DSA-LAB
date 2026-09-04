#include <bits/stdc++.h>
using namespace std;


struct Node {
	int data;
	Node *next, *prev;
	Node( int x) : data(x), next(this), prev(this) {}
};

void insert( Node* &head, int x, int pos ){
	Node *n = new Node(x);
	
	if( !head) {
		head = n;
		return;
	}
	
	Node *p = head;
	for( int i =1; i< pos; i++) p = p-> next;
	n-> next = p-> next;
	n-> prev = p;
	p-> next-> prev = n;
	p-> next = n;
	
	if (pos == 1) head = n;
}
void del( Node* &head, int pos) {
	if( !head) return;
	
	Node *p = head;
	for( int i = 1; i< pos; i++) p = p-> next;
	if( p-> next == p) {
		delete p;
		head = nullptr;
		return;
	}
	
	p-> prev-> next = p-> next;
	p-> next-> prev = p-> prev;
	
	if( p == head) 
		head = p-> next;
		delete p;
}

void display( Node *head) {
	if( !head) return;
	Node *p = head;
	do{
		cout<< p-> data << " ";
		p = p-> next;
	} while( p != head);
	cout<< endl;
}

int main(){
	Node* head = nullptr;
	
	insert( head, 10, 1);
	insert( head, 20, 2);
	//display( head); cout<< " *";
	insert( head, 30, 3);
	//display( head); cout<< " **";
	
	insert( head, 15, 2);
	
	display( head);
	
	del( head, 3);
	display( head );
}

	
		
		
		
