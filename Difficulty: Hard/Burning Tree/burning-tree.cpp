//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
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
        if (i >= ip.size())
            break;
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
//User function Template for C++

/*
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
class Solution {
  public:
    Node*makeparent(Node*root, unordered_map<Node*,Node*>&parent,int target){
        Node*res=nullptr;
        
        queue<Node*>q;
        q.push(root);
        parent[root]=nullptr;
        
        while(!q.empty()){
            
            auto node=q.front();
            q.pop();
            
            if(node->data == target){
                res=node;
            }
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        
        return res;
    }
    int minTime(Node* root, int target) 
    {
        
        if(!root)return 0;
       unordered_map<Node*,Node*>parent;
       Node*res=makeparent(root,parent,target);
       if(res == nullptr){
           return 0;
       }
       int t=0;
       unordered_map<Node*,bool>visited;
       queue<pair<Node*,int>>q;//[node,time]
       q.push({res,0});
       visited[res]=true;
       
       while(!q.empty()){
           auto it=q.front();
           q.pop();
           int tm=it.second;
           t=max(t,tm);
           Node*node=it.first;
           
           if(node->left && visited[node->left]==false && parent[node->left]
           != nullptr){
               visited[node->left]=true;
               q.push({node->left,tm+1});
           }
           
            if(node->right && visited[node->right]==false && parent[node->right]
           != nullptr){
               visited[node->right]=true;
               q.push({node->right,tm+1});
           }
           
           if(parent[node] != nullptr && visited[parent[node]] == false){
               visited[parent[node]]=true;
               q.push({parent[node],tm+1});
           }
       }
       
       return t;
    }
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends