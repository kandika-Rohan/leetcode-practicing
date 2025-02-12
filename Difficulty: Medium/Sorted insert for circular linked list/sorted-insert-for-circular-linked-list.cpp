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

void printList(Node *head) {
    if (head == NULL)
        return;

    Node *temp = head;
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);

    cout << "\n";
}


// } Driver Code Ends
/* structure for a node */
/*
struct Node
{
  int data;
  struct Node *next;

  Node(int x){
      data = x;
      next = NULL;
  }

};
 */

// This function should return head of
// the modified list
class Solution {
  public:
    Node* sortedInsert(Node* head, int data) {
    Node* temp = head;
    Node* newHead = new Node(data);

    // If the list is empty, make newHead point to itself and return.
    if (!head) {
        newHead->next = newHead;
        return newHead;
    }

    // Find the last node in the circular list
    while (temp->next != head) {
        temp = temp->next;
    }

    // Case 1: Insert at the beginning (new smallest element)
    if (data < head->data) {
        newHead->next = head;
        temp->next = newHead; // Update last node to point to the new head
        return newHead;
    }

    // Case 2: Insert at the end (new largest element)
    if (data >= temp->data) {
        temp->next = newHead;
        newHead->next = head; // Maintain circular structure
        return head;
    }

    // Case 3: Insert in the middle
    Node* ptr = head;
    
    while (ptr->next != head && ptr->next->data < data) {
        
        ptr = ptr->next;
    }

    newHead->next = ptr->next;
    ptr->next = newHead;

    return head;
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
        while (ss >> number) {
            arr.push_back(number);
        }
        int x;
        cin >> x;
        cin.ignore();
        Node *head = new Node(arr[0]);
        Node *tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            tail->next = new Node(arr[i]);
            tail = tail->next;
        }
        tail->next = head; // Make it circular
        Solution ob;
        Node *ans = ob.sortedInsert(head, x);
        printList(ans);
    }
    return 0;
}
// } Driver Code Ends