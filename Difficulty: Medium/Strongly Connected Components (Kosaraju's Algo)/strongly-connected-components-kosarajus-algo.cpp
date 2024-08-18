//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find number of strongly connected components in the graph.
void dfs1(int i, vector<int>& vis, vector<int> adjlist[], stack<int>& st) {
    vis[i] = 1;
    for (auto it : adjlist[i]) {
        if (!vis[it]) {
            dfs1(it, vis, adjlist, st);
        }
    }
    st.push(i); // Corrected: push the node onto the stack after the DFS call
}

void dfs2(int i, vector<int>& vis, vector<int> transpose[]) {
    vis[i] = 1;
    for (auto it : transpose[i]) {
        if (!vis[it]) {
            dfs2(it, vis, transpose);
        }
    }
}

int kosaraju(int V, vector<vector<int>>& adj) {
    vector<int> adjlist[V];
    vector<int> transpose[V];

    // Fill the adjacency list
    for (int i = 0; i < V; i++) {
        for (auto it : adj[i]) {
            adjlist[i].push_back(it);
        }
    }

    // First pass: fill the stack with vertices in order of finishing times
    stack<int> st;
    vector<int> vis(V, 0);
    for (int i = 0; i < V; i++) {
        if (!vis[i]) {
            dfs1(i, vis, adjlist, st);
        }
    }

    // Create the transpose graph
    for (int i = 0; i < V; i++) {
        for (auto it : adjlist[i]) {
            transpose[it].push_back(i);
        }
    }

    // Second pass: process all vertices in the order defined by the stack
    fill(vis.begin(), vis.end(), 0);
    int cnt = 0;
    while (!st.empty()) {
        int node = st.top();
        st.pop();
        if (!vis[node]) {
            cnt++;
            dfs2(node, vis, transpose);
        }
    }

    return cnt;
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

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends