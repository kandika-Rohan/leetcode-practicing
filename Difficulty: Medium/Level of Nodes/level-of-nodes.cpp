//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
	public:
	//Function to find the level of node X.
	int nodeLevel(int V, vector<int> adj[], int X) 
	{
	    queue<pair<int,int>>q;
	    vector<bool>vis(V,false);
	    q.push({0,0});
	    vis[0]=true;
	    while(!q.empty()){
	        auto val=q.front();
	        q.pop();
	        
	        int node=val.first;
	        int level=val.second;
	        if(node == X)return level;
	        for(auto it:adj[node]){
	            if(!vis[it]){
	                vis[it]=true;
	                q.push({it,level+1});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E, X;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
    	cin>>X;

    	Solution obj;
    	cout << obj.nodeLevel(V, adj, X) << "\n";
    }

    return 0;
}


// } Driver Code Ends