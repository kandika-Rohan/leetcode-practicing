//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Matrix {
  public:
    template <class T>
    static void input(vector<vector<T>> &A, int n, int m) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d ", &A[i][j]);
            }
        }
    }

    template <class T>
    static void print(vector<vector<T>> &A) {
        for (int i = 0; i < A.size(); i++) {
            for (int j = 0; j < A[i].size(); j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
    }
};


// } Driver Code Ends

class Solution {
  public:
    void dfs(int node,vector<int>&vis,vector<int>adj[],vector<int>&ds){
        vis[node]=1;
        ds.push_back(node);
        for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,ds);
            }
        }
    }
    vector<vector<int>> connectedcomponents(int v, vector<vector<int>>& edges) {
        
        vector<int>adj[v];
        
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<vector<int>>ans;
        vector<int>vis(v,0);
        for(int i=0;i<v;i++){
            vector<int>ds;
            if(!vis[i]){
                dfs(i,vis,adj,ds);
            }
            
            if(!ds.empty()){
                sort(ds.begin(),ds.end());
                ans.push_back(ds);
            }
        }
        
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int e;
        scanf("%d", &e);

        int v;
        scanf("%d", &v);

        vector<vector<int>> edges(e, vector<int>(2));
        Matrix::input(edges, e, 2);

        Solution obj;
        vector<vector<int>> res = obj.connectedcomponents(v, edges);
        sort(res.begin(), res.end());
        for (const auto &component : res) {
            for (int node : component) {
                cout << node << " ";
            }
            cout << endl;
        }

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends