//{ Driver Code Starts
//

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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

// } Driver Code Ends

/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    
    Node* construct(int in[], int pre[], int pres, int pre_e, int ins, int ine, unordered_map<int, int>& map) {
        if (pres > pre_e || ins > ine) {
            return nullptr;
        }
        
        Node* root = new Node(pre[pres]);
        int index = map[root->data];
        int left_size = index - ins;
        
        root->left = construct(in, pre, pres + 1, pres + left_size, ins, index - 1, map);
        root->right = construct(in, pre, pres + left_size + 1, pre_e, index + 1, ine, map);
        
        return root;
    }
    
    Node* buildTree(int in[], int pre[], int n) {
        unordered_map<int, int> map;
        
        for (int i = 0; i < n; i++) {
            map[in[i]] = i;
        }
        
        return construct(in, pre, 0, n - 1, 0, n - 1, map);
    }
};




//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}

// } Driver Code Ends