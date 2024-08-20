//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution {
public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    void dfs1(int node, vector<int>& vis, vector<int> adj[], stack<int>& st) {
        vis[node] = 1;
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs1(it, vis, adj, st);
            }
        }
        st.push(node);
    }
    
    void dfs2(int node, vector<int>& vis, vector<int> adj[], vector<int>& component) {
        vis[node] = 1;
        component.push_back(node);
        for(auto it : adj[node]) {
            if(!vis[it]) {
                dfs2(it, vis, adj, component);
            }
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[]) {
        vector<int> vis(V, 0);
        stack<int> st;
        
        // Step 1: Perform DFS to push nodes in stack according to their finishing times
        for(int i = 0; i < V; i++) {
            if(!vis[i]) {
                dfs1(i, vis, adj, st);
            }
        }
        
        // Step 2: Create the transpose of the graph
        vector<int> transpose[V];
        for(int i = 0; i < V; i++) {
            for(auto it : adj[i]) {
                transpose[it].push_back(i);
            }
        }
        
        // Step 3: Perform DFS on the transposed graph in the order defined by the stack
        fill(vis.begin(), vis.end(), 0);  // Reset the visited array
        vector<vector<int>> ans;
        
        while(!st.empty()) {
            int node = st.top();
            st.pop();
            if(!vis[node]) {
                vector<int> component;
                dfs2(node, vis, transpose, component);
                sort(component.begin(), component.end());
                ans.push_back(component);
            }
        }
        
        // Step 4: Sort the strongly connected components themselves
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};


//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    }

    return 0;
}


// } Driver Code Ends