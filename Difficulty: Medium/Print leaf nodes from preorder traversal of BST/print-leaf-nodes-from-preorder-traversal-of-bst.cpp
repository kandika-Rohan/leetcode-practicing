//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    class Node{
        public:
        int data;
        Node*left;
        Node*right;
        Node(int d){
            this->data=d;
            left=nullptr;
            right=nullptr;
        }
    };
    Node*construct(int arr[],int N,int &i,int mini,int maxi){
        if(i>=N){
            return nullptr;
        }
        if(arr[i]< mini || arr[i] > maxi){
            return nullptr;
        }
        Node*root=new Node(arr[i]);
        i++;
        root->left=construct(arr,N,i,mini,root->data);
        root->right=construct(arr,N,i,root->data,maxi);
        return root;
    }
    void preorder(Node*root,vector<int>&ds){
        if(!root){
            return ;
        }
        if(!root->left && !root->right){
            ds.push_back(root->data);
        }
        preorder(root->left,ds);
        preorder(root->right,ds);
    }
    vector<int> leafNodes(int arr[],int N) {
        // code here
        int i=0;
        Node*root=construct(arr,N,i,INT_MIN,INT_MAX);
        vector<int>ds;
        preorder(root,ds);
        return ds;
        
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin >> N;
        int arr[N];
        for(int i=0;i<N;i++)cin>>arr[i];
        Solution ob;
        vector<int>ans=ob.leafNodes(arr,N);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends