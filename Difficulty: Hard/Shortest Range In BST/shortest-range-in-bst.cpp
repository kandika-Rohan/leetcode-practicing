//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}



// } Driver Code Ends
// User function Template for C++

class Solution {
    public:
    class node {
        public:
        int key;
        int row;
        int col;
        node(int d, int r, int c) {
            this->key = d;
            this->row = r;
            this->col = c;
        }
    };

    class compare {
        public:
        bool operator()(node* a, node* b) {
            return a->key > b->key;
        }
    };

    pair<int, int> solve(vector<vector<int>>& a) {
        int n = a.size();
        if (n == 0) return {-1, -1};

        int mini = INT_MAX;
        int maxi = INT_MIN;

        priority_queue<node*, vector<node*>, compare> pq;

        for (int i = 0; i < n; i++) {
            int element = a[i][0];
            mini = min(mini, element);
            maxi = max(maxi, element);
            node* newNode = new node(element, i, 0);
            pq.push(newNode);
        }

        int start = mini;
        int end = maxi;

        while (!pq.empty()) {
            node* it = pq.top();
            pq.pop();
            mini = it->key;
            int row = it->row;
            int col = it->col;

            if ((end - start) > (maxi - mini)) {
                start = mini;
                end = maxi;
            }

            if (col + 1 < a[row].size()) {
                int nextElement = a[row][col + 1];
                node* newNode = new node(nextElement, row, col + 1);
                pq.push(newNode);
                maxi = max(maxi, nextElement);
            } else {
                break;
            }
        }

        return {start, end};
    }

    pair<int, int> shortestRange(Node *root) {
        // Your code goes here
        if (!root) {
            return {-1, -1};
        }
        
        vector<vector<int>> levels;
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            int n = q.size();
            vector<int> level;
            
            for (int i = 0; i < n; i++) {
                Node* node = q.front();
                q.pop();
                
                level.push_back(node->data);
                
                if (node->left) {
                    q.push(node->left);
                }
                
                if (node->right) {
                    q.push(node->right);
                }
            }
            
            levels.push_back(level);
        }

        return solve(levels);
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);
        Solution obj;
        pair<int, int> range = obj.shortestRange(root);
        cout << range.first << " " << range.second << "\n";
    }

    return 0;
}
// } Driver Code Ends