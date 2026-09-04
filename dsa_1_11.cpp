#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val): data(val), next(nullptr){}
};

struct LinkedList {
	Node* head = nullptr;
	
	void insertBegin( int val) {
		Node* newNode = new Node(val);
		newNode->next = head;
		head = newNode;
	}
	
	void insertMiddle(int val, int pos) {
		if( pos<=1 || !head) {
			insertBegin(val);
			return;
		}
		Node* temp = head;
		
		for(int i=0; i< pos-1 && temp->next; i++)
		temp = temp->next;
		
		Node* newNode = new Node(val);
		newNode->next = temp->next;
		temp->next = newNode;
		
	}
	
	void insertEnd(int val) {
		Node* newNode = new Node(val);
		if(!head) { head = newNode; return;}
		Node* temp = head;
		while (temp->next) temp = temp->next;
		temp->next = newNode;
	}
	
	void deleteBegin(){
		if (!head) return;
		Node* t = head;
		head = head->next;
		delete t;
	}
	
	void deleteMiddle(int pos) {
		if (!head) return;
		if(pos <= 1) { deleteBegin(); return;}
		Node* temp = head;
		for (int i=1; i< pos-1 && temp->next; i++) temp = temp->next;
		if(temp->next){
			Node* t = temp->next;
			temp->next = t->next;
			delete t;
		}
	}
	
	void deleteEnd(){
		if(!head) return;
		if(!head->next) return;
		Node* temp = head;
		while(temp->next->next)temp = temp->next;
		delete temp->next;
		temp->next = nullptr;
	}
	
	void print(){
		Node* temp = head;
		while (temp) { cout << temp->data << "->"; temp = temp->next;}
		cout<<"NULL\n";
	}
};

int main() {
	LinkedList list;
	list.insertEnd(10);
	list.insertEnd(20);
	list.insertEnd(30);
	
	cout<< "Initial List: "; list.print();

	list.insertBegin(5);
	cout<< "After InsertBegin: "; list.print();
	
	list.insertMiddle(15, 3);
	cout<< "After insertMiddle: "; list.print();
	
	list.insertEnd(40);
	cout<< "after insertEnd: ";
	list.print();
	
	list.deleteBegin();
	cout<< "after deleteBegin: ";
	list.print();
	
	list.deleteMiddle(2);
	cout<< "after deleteMiddle: ";
	list.print();
	
	list.deleteEnd();
	cout<< "after deleteEnd: "; list.print();
	
	return 0;
	
}
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
		
	
	
	
	
	
		
		
		
	
