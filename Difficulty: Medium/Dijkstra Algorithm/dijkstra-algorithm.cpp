//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.


vector<int> dijkstra(int V, vector<vector<int>> adj[], int S) {
    // Min-heap priority queue to store {distance, node}
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    
    // Initialize distances with infinity
    vector<int> dis(V, 1e9);
    
    // Start with the source node
    minheap.push({0, S}); // {distance, node}
    dis[S] = 0;
    
    while(!minheap.empty()) {
        auto it = minheap.top();
        int node = it.second;
        int dist = it.first;
        minheap.pop();
        
        // Traverse adjacent nodes
        for(auto adjNode : adj[node]) {
            int adjVertex = adjNode[0]; // Get adjacent vertex
            int weight = adjNode[1];    // Get edge weight
            if(dis[node] + weight < dis[adjVertex]) { // Check if shorter path found
                dis[adjVertex] = dis[node] + weight;
                minheap.push({dis[adjVertex], adjVertex}); // Push updated distance
            }
        }
    }
    
    return dis;
}

};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends