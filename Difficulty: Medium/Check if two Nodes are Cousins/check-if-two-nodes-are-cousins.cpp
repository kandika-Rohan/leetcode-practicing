//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

bool isCousins(Node* root, int x, int y);

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root = buildTree(s);
        int x, y;
        scanf("%d ", &x);
        scanf("%d ", &y);
        if (x == y) {
            cout << "0\n";
            continue;
        }
        cout << isCousins(root, x, y) << endl;
    }
    return 1;
}
// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
bool solve(unordered_map<Node*, Node*>& parentMap, Node* root, int a, int b) {
    int alevel = -1, aparent = -1;
    int blevel = -1, bparent = -1;
    
    queue<pair<int, Node*>> q;  // {level, node}
    q.push({0, root});
    parentMap[root] = nullptr;  // Root has no parent
    
    while (!q.empty()) {
        int n = q.size();
        
        for (int i = 0; i < n; i++) {
            auto it = q.front();
            q.pop();
            
            int level = it.first;
            Node* node = it.second;
            
            if (node) {
                // Check if node is either 'a' or 'b'
                if (node->data == a) {
                    alevel = level;
                    aparent = parentMap[node] ? parentMap[node]->data : -1;  // Check if parent exists
                }
                if (node->data == b) {
                    blevel = level;
                    bparent = parentMap[node] ? parentMap[node]->data : -1;  // Check if parent exists
                }

                // Process left and right children
                if (node->left) {
                    parentMap[node->left] = node;
                    q.push({level + 1, node->left});
                }
                if (node->right) {
                    parentMap[node->right] = node;
                    q.push({level + 1, node->right});
                }
            }
        }
    }

   
    if (alevel != -1 && blevel != -1 && alevel == blevel && aparent != bparent) {
        return true;
    }
    
    return false;
}

bool isCousins(Node* root, int a, int b) {
    if (!root) return false;  // Handle edge case where tree is empty
    
    unordered_map<Node*, Node*> parentMap;
    return solve(parentMap, root, a, b);
}

