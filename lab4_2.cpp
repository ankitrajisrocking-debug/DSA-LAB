#include <bits/stdc++.h>
using namespace std;

#define MAX 5

int main(){
	int stack[MAX], top = -1, ch, x;
	
	while(true){
		cout<< "\n1.push	2.pop	3.Display	4.exit\nchoice: ";
		cin>> ch;
		
		if( ch ==1){
			if( top == MAX - 1) cout<< "stack overflow\n";
			else{
				cout<< "enter element: ";
				cin>> x;
				stack[++top] = x;
			}
		}
		
		else if ( ch == 2) {
			if( top == -1) cout<< "stack underflow\n";
			else cout<<  "popped: " << stack[top--] << "\n";
		}
			
		else if( ch ==3) {
			if ( top == -1) cout<< "stack empty\n";
			else {
				cout<< "stack:  ";
				for( int i = top; i>= 0; i--) 
					 cout<< stack[i]<< " ";
			cout<< "\n";
			}
		}
		else break;
	}
}
