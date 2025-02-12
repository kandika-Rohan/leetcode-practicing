//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// design the class in the most optimal way

#include <iostream>
#include <unordered_map>
using namespace std;

class Node {
public:
    Node* next;
    Node* prev;
    int key;
    int val;

    Node(int key, int val) {
        this->key = key;
        this->val = val;
        next = nullptr;
        prev = nullptr;
    }
};

class LRUCache {
    
private:

    Node* head;
    Node* tail;
    int c;
    unordered_map<int, Node*> map;

public:

    LRUCache(int cap) {
        c = cap;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    void add(Node* node) {
        
        Node* temp = head->next;
        node->next = temp;
        temp->prev = node;
        head->next = node;
        node->prev = head;
    }

    void deleteNode(Node* delnode) {
        
        Node* temp = delnode->prev;
        Node* temp2 = delnode->next;
        temp->next = temp2;
        temp2->prev = temp;
    }

    int get(int key) {
        
        if (map.find(key) != map.end()) {
            
            Node* resNode = map[key];
            
            int res = resNode->val;
            
            deleteNode(resNode);
            
            add(resNode);
            
            map[key] = head->next;
            
            return res;
        }
        
        return -1;
    }

    void put(int key, int value) {
        
        if (map.find(key) != map.end()) {
            
            Node* existingNode = map[key];
            
            map.erase(key);
            
            deleteNode(existingNode);
        }

        if (c == map.size()) {
            
            map.erase(tail->prev->key);
            
            deleteNode(tail->prev);
        }

        Node* newNode = new Node(key, value);
        
        add(newNode);
        
        map[key] = head->next;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {

        int capacity;
        cin >> capacity;
        LRUCache *cache = new LRUCache(capacity);

        int queries;
        cin >> queries;
        while (queries--) {
            string q;
            cin >> q;
            if (q == "PUT") {
                int key;
                cin >> key;
                int value;
                cin >> value;
                cache->put(key, value);
            } else {
                int key;
                cin >> key;
                cout << cache->get(key) << " ";
            }
        }
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends