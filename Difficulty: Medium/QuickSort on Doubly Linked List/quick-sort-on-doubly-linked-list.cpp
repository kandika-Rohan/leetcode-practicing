//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// a node of the doubly linked list
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

// Function to insert a node at the end of the Doubly Linked List
void push(DLLNode **headRef, DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end, next is NULL
    newNode->next = NULL;

    // change next of tail node to new node
    if ((*tailRef) != NULL) {
        newNode->prev = (*tailRef);
        (*tailRef)->next = newNode;
    } else {
        // if the list is empty
        (*headRef) = newNode;
        newNode->prev = NULL;
    }

    (*tailRef) = newNode;
}

// Function to print nodes in a given doubly linked list
void printList(DLLNode *head) {
    // if list is empty
    if (head == NULL)
        return;

    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}


// } Driver Code Ends
/* a Node of the doubly linked list */

/*
class DLLNode {
  public:
    int data;
    DLLNode *next;
    DLLNode *prev;

    DLLNode(int val) {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
  public:
  void quickSort(vector<int>&arr, int low, int high)
    {
        // code here
        if(low<high){
            
            int pivot=partition(arr,low,high);
            quickSort(arr,low,pivot-1);
            quickSort(arr,pivot+1,high);
        }
    }
    
    int partition (vector<int>&arr, int low, int high)
    {
       // Your code here
       int i=low;
       int j=high;
       int pivot=arr[low];
       
       
       while(i<j){
           
           
           while(arr[i]<=pivot && i<=high){
               i++;
           }
           while(arr[j]>pivot && j>=low){
               j--;
           }
           if(i<j){
               swap(arr[i],arr[j]);
           }
       }
       swap(arr[low],arr[j]);
       
       return j;
    }
    
    void t(DLLNode*head,vector<int>&ds){
        if(!head)return;
        ds.push_back(head->data);
        t(head->next,ds);
    }
    DLLNode* quickSort(DLLNode* head) {
        // Your code goes here
        
        vector<int>ds;
        t(head,ds);
        quickSort(ds,0,ds.size()-1);
        
        DLLNode*root=new DLLNode(ds[0]);
        
        DLLNode*temp=root;
        
        for(int i=1;i<ds.size();i++){
            
             DLLNode*ptr=new DLLNode(ds[i]);
             
             temp->next=ptr;
             
             ptr->prev=temp;
            
             temp=ptr;
        }
        
        return root;
        
    }
};


//{ Driver Code Starts.

// Driver code
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

        DLLNode *head = nullptr, *tail = nullptr;
        for (int i = 0; i < arr.size(); i++) {
            push(&head, &tail, arr[i]);
        }

        Solution obj;
        head = obj.quickSort(head);
        printList(head);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends