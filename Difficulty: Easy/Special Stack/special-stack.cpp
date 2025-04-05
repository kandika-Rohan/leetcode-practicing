//{ Driver Code Starts
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);
//This is the STL stack (http://quiz.geeksforgeeks.org/stack-container-adaptors-the-c-standard-template-library-stl/).
stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends

#include<bits/stdc++.h>
void push(stack<int>& s, int a){
	// Your code goes here
	s.push(a);
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	return s.size() == n;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	
	return s.size() == 0;
}

int pop(stack<int>& s){
	// Your code goes here
	
	if(s.empty()){
	    return -1;
	}
	
	int x=s.top();
	s.pop();
	
	return x;
}

int getMin(stack<int>& s){
	// Your code goes here
	stack<int>st;
	
	int mini=INT_MAX;
	
	while(!s.empty()){
	    mini=min(mini,s.top());
	    st.push(s.top());
	    s.pop();
	}
	
	while(!st.empty()){
	    
	    if(mini == st.top()){
	        st.pop();
	        continue;
	    }
	    else{
	        s.push(st.top());
	        st.pop();
	    }
	}
	return mini;
	
}