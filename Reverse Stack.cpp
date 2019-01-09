#include<bits/stdc++.h>
using namespace std;
 
// using std::stack for stack implementation
stack<int> st, stack_;

void printst();
 
// Below is a recursive function that inserts an element at the bottom of a stack.
void insert_at_bottom(int x)
{
    if(stack_.size() == 0)
    	stack_.push(x);
 
    else {
        int a = stack_.top();
        stack_.pop();
        insert_at_bottom(x);
 	   	stack_.push(a);
    }
}
 
void reverse()
{
    if(stack_.size()>0) {
        int x = stack_.top();
        stack_.pop();
        reverse();
        insert_at_bottom(x);
    }
}
 
int main() {
 	int noOfNumbers;
 	int x;
 	cin >> noOfNumbers;  	
   	for (int i = 0; i < noOfNumbers; i++) {
   		cin >> x;
   		stack_.push(x);
   	}
    
    reverse();
    st = stack_;
    printst();
}

void printst() {
	while (!st.empty()) {
		int top = st.top();
		st.pop();
		cout << top << "\n";
	}
}