//{ Driver Code Starts
// Initial Template for C++

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


// } Driver Code Ends
// User function Template for C++

/*
// a node of the doubly linked list
class DLLNode
{
public:
    int data;
    DLLNode *next;
    DLLNode *prev;
    DLLNode(int val)
    {
        data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
*/
class Solution {
public:
    // Function to sort a k-sorted doubly linked list
    DLLNode* sortAKSortedDLL(DLLNode* head, int k) {
        if (!head) return nullptr;

        // Create a min-heap (priority queue)
        priority_queue<int, vector<int>, greater<int>> minHeap;
        DLLNode* newHead = nullptr, *last = nullptr;
        DLLNode* current = head;

        // Add first k+1 elements into the min-heap
        for (int i = 0; current != nullptr && i <= k; i++) {
            minHeap.push(current->data);
            current = current->next;
        }

        // Extract the minimum element from the heap and fix the doubly linked list
        while (!minHeap.empty()) {
            // Get the smallest element from the heap
            int minValue = minHeap.top();
            minHeap.pop();

            // Create a new node for the sorted DLL
            DLLNode* newNode = new DLLNode(minValue);

            // Set the head if it's the first node
            if (!newHead) {
                newHead = newNode;
                last = newHead;
            } else {
                last->next = newNode;
                newNode->prev = last;
                last = newNode;
            }

            // If there are more nodes in the original list, add them to the heap
            if (current != nullptr) {
                minHeap.push(current->data);
                current = current->next;
            }
        }

        return newHead;
    }
};


//{ Driver Code Starts.

// Function to insert a node at the end
// of the Doubly Linked List
void push(DLLNode **tailRef, int new_data) {
    // allocate node
    DLLNode *newNode = new DLLNode(new_data);

    // since we are adding at the end,
    // next is NULL
    newNode->next = NULL;

    newNode->prev = (*tailRef);

    // change next of tail node to new node
    if ((*tailRef) != NULL)
        (*tailRef)->next = newNode;

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

// Driver
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

        int k;
        cin >> k;
        cin.ignore();

        DLLNode *head = new DLLNode(arr[0]);
        DLLNode *tail = head;

        // Check if the array is empty
        for (size_t i = 1; i < arr.size(); ++i) {
            push(&tail, arr[i]);
        }
        Solution obj;
        printList(obj.sortAKSortedDLL(head, k));
        cout << "\n";
    }

    return 0;
}

// } Driver Code Ends