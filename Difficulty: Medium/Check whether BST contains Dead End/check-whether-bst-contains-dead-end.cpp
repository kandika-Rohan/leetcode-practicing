//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>

using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


// } Driver Code Ends
/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
class Solution{
  public:
      void traverse(Node* root, unordered_set<int>& allNodes, unordered_set<int>& leafNodes) {
        if (!root) {
            return;
        }

        allNodes.insert(root->data);

        // If it's a leaf node
        if (!root->left && !root->right) {
            leafNodes.insert(root->data);
            return;
        }

        // Recur for left and right subtrees
        traverse(root->left, allNodes, leafNodes);
        traverse(root->right, allNodes, leafNodes);
    }
    bool isDeadEnd(Node *root)
    {
        //Your code here
                if (!root) {
            return false;
        }

        unordered_set<int> allNodes;
        unordered_set<int> leafNodes;

        traverse(root, allNodes, leafNodes);

        // Check for dead end condition
        for (int leaf : leafNodes) {
            if ((allNodes.find(leaf - 1) != allNodes.end() || leaf - 1 == 0) && 
                allNodes.find(leaf + 1) != allNodes.end()) {
                return true;
            }
        }

        return false;
    }
    
};

//{ Driver Code Starts.
// bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

     Solution ob;
     cout<<ob.isDeadEnd(root);
     cout<<endl;
    }
}


// } Driver Code Ends