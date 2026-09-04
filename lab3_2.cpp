#include <bits/stdc++.h>
using namespace std;

struct node {
	int data;
	node* next;
	node(int x){
		data = x;
		next = NULL;
	}
};

class CLL {
	node* last = nullptr;
	
	public:
		void insert ( int val, int pos) {
			node* n = new node(val);
			if ( last == nullptr ) {
				n-> next = n;
				last = n;
				return;
			}
			
			
			if ( pos <= 1) {
				n -> next = last -> next;
				last -> next = n;
				return;
			}
			
			node* t = last -> next;
			for( int i = 1; i < pos - 1 && t != last; i++) t = t -> next;
			n -> next = t->next;
			t -> next = n;
			if ( t == last ) last = n;
		}
		
		void delAt( int pos) {
			if ( last == nullptr){
				cout<< "List is Empty" << endl;
				return;
			}
			node* t = last -> next;
			node* p = last;
			if ( t == last) {
				delete t;
				last = nullptr;
				return;
			}
			for( int i = 1; i < pos; i++) { p =t; t = t-> next ;}
			p -> next = t-> next;
			if ( t == last ) last = p;
			delete t;
		}
	
	void display(){
		if ( last == nullptr) { cout<< "list empty\n" ; return; }
		node* t = last-> next;
		cout << "List: ";
		do { cout << t -> data << " " ; t = t-> next; } while ( t!= last -> next);
		cout << endl;
	}


};

int main() {
	CLL list;
	list.insert(10, 1); list.display();
	list.insert(20, 2); list.display();
	list.insert(30, 2); list.display();
	list.delAt(2); list.display();
	
	return 0;
}

	
	
