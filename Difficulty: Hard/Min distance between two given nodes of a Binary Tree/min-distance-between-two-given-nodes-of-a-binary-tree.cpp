//{ Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

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
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

class Solution{
    public:
    void solve(Node*root,int a,int b,unordered_map<Node*,Node*>&map,
    Node*&temp1,Node*&temp2){
        
        queue<pair<Node*,Node*>>q;
        
        q.push({root,nullptr});
        
        map[root]=nullptr;
        
        while(!q.empty()){
            
            auto it=q.front();
            q.pop();
            
            Node*node=it.first;
            Node*parent=it.second;
            
            if(node->data == a){
                temp1=node;
            }
            if(node->data == b){
                temp2=node;
            }
            
            if(node->left){
                q.push({node->left,node});
                map[node->left]=node;
            }
            if(node->right){
                q.push({node->right,node});
                map[node->right]=node;
            }
            
        }
    }
    int findDist(Node* root, int a, int b) {
        // Your code here
        
        Node*temp1=nullptr;
        Node*temp2=nullptr;
        unordered_map<Node*,Node*>map;
        solve(root,a,b,map,temp1,temp2);
        
        queue<pair<int,Node*>>q;
        
        unordered_map<Node*,bool>vis;
        
        q.push({0,temp1});
        
        vis[temp1]=true;
        
        while(!q.empty()){
            
            auto it=q.front();
            
            q.pop();
            
            int tm=it.first;
            Node*node=it.second;
            if(node == temp2){
                return tm;
            }
            
            if(node->left && !vis[node->left]){
                vis[node->left]=true;
                q.push({tm+1,node->left});
            }
            if(node->right && !vis[node->right]){
                vis[node->right]=true;
                q.push({tm+1,node->right});
            }
            if(map[node] != nullptr && !vis[map[node]]){
                vis[map[node]]=true;
                q.push({tm+1,map[node]});
            }
        }
        return -1;
    }
};


//{ Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        int n1, n2;
        scanf("%d %d ", &n1, &n2);
        Solution ob;
        cout << ob.findDist(root, n1, n2) << endl;
     
    }
    return 0;
}

// } Driver Code Ends