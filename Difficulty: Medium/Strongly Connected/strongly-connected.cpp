//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//Position this line where user code will be pasted.
class Solution {
  public:
    void dfs1(int node,vector<int>adj[],stack<int>&st,vector<int>&vis){
        
        vis[node]=1;
        
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs1(it,adj,st,vis);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node,vector<int>adj[],vector<int>&vis){
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs2(it,adj,vis);
            }
        }
    }
    int kosaraju(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        
        vector<int>Adj[n];
        
      
        for(int i=0;i<n;i++){
            for(auto it:adj[i]){
                Adj[i].push_back(it);
            }
        }
        
        vector<int>vis(n,0);
        stack<int>st;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs1(i,Adj,st,vis);
            }
        }
   
        vector<int>AdjT[n];
        
        for(int i=0;i<n;i++){
            vis[i]=0;
            for(auto it:adj[i]){
                AdjT[it].push_back(i);
            }
        }
        
        int cnt=0;
        
        while(!st.empty()){
            auto node=st.top();
            st.pop();
            
            if(!vis[node]){
                cnt++;
                dfs2(node,AdjT,vis);
            }
        }
        
        return cnt;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<vector<int>> adj(V);

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.kosaraju(adj) << "\n";

        // cout << "~"
        //      << "\n";
    }

    return 0;
}

// } Driver Code Ends