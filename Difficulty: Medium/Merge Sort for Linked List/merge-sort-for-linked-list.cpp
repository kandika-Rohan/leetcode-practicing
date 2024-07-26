//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node *node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  public:
    // Function to sort the given linked list using Merge Sort.
    void solve(Node* head,vector<int>&ans){
        if(!head){
            return;
        }
        ans.push_back(head->data);
        solve(head->next,ans);
    }
    void merge(int low,int mid,int high,vector<int>&ans){
        int s=low;
        int e=mid+1;
        vector<int>temp;
        while(s<=mid && e<=high){
            if(ans[s]<=ans[e]){
                temp.push_back(ans[s]);
                s++;
            }
            else{
                temp.push_back(ans[e]);
                e++;
            }
        }
        
        while(s<=mid){
            temp.push_back(ans[s++]);
        }
        while(e<=high){
            temp.push_back(ans[e++]);
        }
        
        int i=low;
        for(auto it:temp){
            ans[i]=it;
            i++;
        }
   }
    void mergesort(int low,int high,vector<int>&ans){
        if(low >= high){
            return ;
        }
        int mid=(high+low)/2;
        
        mergesort(low,mid,ans);
        mergesort(mid+1,high,ans);
        merge(low,mid,high,ans);
    }
    Node* mergeSort(Node* head) {
        // your code here
        vector<int>ans;
        solve(head,ans);
        int n=ans.size();
        mergesort(0,n-1,ans);
        Node*newnode=new Node(ans[0]);
        Node*ptr=newnode;
        
        for(int i=1;i<ans.size();i++){
            Node*temp=new Node(ans[i]);
            ptr->next=temp;
            ptr=temp;
        }
        return newnode;
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
        Node *head = nullptr;
        // Check if the array is empty
        if (!arr.empty()) {
            head = new Node(arr[0]);
            Node *tail = head;
            for (size_t i = 1; i < arr.size(); ++i) {
                tail->next = new Node(arr[i]);
                tail = tail->next;
            }
        }
        Solution obj;
        Node *ans = obj.mergeSort(head);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends