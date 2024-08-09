//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*

struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to rotate a linked list.
    void solve(Node*root,vector<int>&ds){
        if(!root)return;
        ds.push_back(root->data);
        solve(root->next,ds);
    }
    Node*construct(vector<int>&ds){
        Node*root=new Node(ds[0]);
        Node*temp=root;
        for(int i=1;i<ds.size();i++){
            Node*ptr=new Node(ds[i]);
            temp->next=ptr;
            temp=ptr;
        }
        return root;
    }
    Node* rotate(Node* head, int k) {
        // Your code here
        if(!head)return head;
        vector<int>ds;
        solve(head,ds);
        
        int n=ds.size();
        k=k%n;
        std::rotate(ds.begin(),ds.begin()+k,ds.end());
        
        Node*root=construct(ds);
        return root;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;

        // Read numbers from the input line
        while (ss >> number) {
            arr.push_back(number);
        }

        Node* head = nullptr;

        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node* tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        int k;
        cin >> k;
        cin.ignore();

        Solution ob;
        head = ob.rotate(head, k);
        printList(head);
    }
    return 1;
}

// } Driver Code Ends