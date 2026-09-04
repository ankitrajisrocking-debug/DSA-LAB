#include <bits/stdc++.h>
using namespace std;

class node {
	public:
		int val;
		node *next, *prev;
		node( int x){
			val = x;
			prev = next = NULL;
		}
};
node *head = NULL;
	
void insB( int x){
	node *temp = new node(x);
	if ( head == NULL) { head = temp; return;}
	else {
		temp -> next = head;
		head -> prev = temp;
		head = temp;
		}
		
}

void display(){
	
	node* temp = head;
	while( temp != NULL){
		cout<< temp -> val << " -> " ;
		temp = temp -> next;
	}
	cout << "NULL";
	cout<< endl;
}

void insE( int x){
	node *p = new node(x);
	
	if(head == NULL) {
		head = p;
		return;
	}
	
	node* temp = head;
	while( temp -> next != NULL) temp = temp -> next; 
	temp -> next = p;
	p -> prev = temp;
}

void delE(){
	if ( head ==  NULL ) return;
	
	node *temp = head;
	
	while( temp -> next != NULL)
		 temp = temp -> next;
		 
	if( temp -> prev = NULL) head = NULL;
	else temp -> prev -> next = NULL;
	
	delete temp;
}

void delB() {
	if ( head ==  NULL ) return;
	
	node *temp = head;
	head = head -> next;
	
	if ( head!= NULL)
		head -> prev = NULL;
		
	delete temp;
}

void insM( int val, int pos){
	node *n = new node(val);
	if ( head == NULL || pos <= 1) insB(val);
	else {
	
	node *t = head;
	for( int i =1; i < pos-1 && t -> next; i++) t = t-> next;
	n-> next = t -> next;
	n -> prev = t;
	if ( t-> next) t -> next -> prev = n;
	t-> next = n; }
}
	

		
		
		
		
		
	
int main(){
	insB(1); display();
	insB(2); display();
	insE(3); display();
	insB(23); display();
	insE(65); display();
	insM(1000,1); display();
	delB(); display();
	
}
	
	
		

		
	
	
	
