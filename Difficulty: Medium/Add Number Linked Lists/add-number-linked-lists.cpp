//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to add two numbers represented by linked list.
    Node*reverse(Node*head){
        Node*curr=head;
        Node*prev=nullptr;
        Node*next=nullptr;
        
        while(curr != nullptr){
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
    
    int no_of_nodes(Node*head){
        if(!head)return 0;
        return 1+no_of_nodes(head->next);
    }
    Node*adding_zeros_front(Node*head,int diff){
        
        Node*root=nullptr;
        Node*temp=nullptr;
        while(diff != 0){
            if(!root){
                root=new Node(0);
                temp=root;
            }
            else{
                Node*ptr=new Node(0);
                temp->next=ptr;
                temp=ptr;
            }
            diff--;
        }
        
        temp->next=head;
        
        return root;
    }
    Node* addTwoLists(Node* num1, Node* num2) {
        
        int n1=no_of_nodes(num1);
        int n2=no_of_nodes(num2);
        
        if(n2>n1){
            int diff=n2-n1;
            num1=adding_zeros_front(num1,diff);
            
        }
        else if(n2<n1){
            
            int diff=n1-n2;
            num2=adding_zeros_front(num2,diff);
        }
        
        num1=reverse(num1);
        num2=reverse(num2);
        
        Node*root=nullptr;
        Node*temp=nullptr;
        
        Node*ptr1=num1;
        Node*ptr2=num2;
        int carry=0;
        while(ptr1 != nullptr && ptr2 != nullptr){
            int val=ptr1->data+ptr2->data;
            val+=carry;
            carry=val/10;
            Node*digitval=new Node(val%10);
            if(!root){
                root=digitval;
                temp=root;
            }
            else{
                temp->next=digitval;
                temp=digitval;
            }
            ptr1=ptr1->next;
            ptr2=ptr2->next;
        }
        if(carry>0){
            temp->next=new Node(carry%10);
        }
        root=reverse(root);
        Node*correct=root;
        while(correct->data == 0){
            correct=correct->next;
        }
        return correct;
        
    }
};



//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends