//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution {
  private:
  int timer=1;
  void dfs(int node, int parent,vector<int>adj[],
  vector<int>&visited,int low[], int tn[], vector<int>&mark) {
      
      visited[node] = 1;
      
      low[node] = tn[node] = timer;
      
      timer++;
      
      int child=0;
      
      for(auto it:adj[node]) {
          
          if(it==parent) continue;
          
          if(!visited[it]) {
              
              dfs(it,node,adj,visited,low,tn,mark);
              
              low[node] = min(low[node],low[it]);
              
              if(low[it] >= tn[node] && parent!=-1) {
                  
                  mark[node] = 1;
              }
              child++;
          }
          
          else {
              
              low[node] = min(low[node],tn[it]);
          }
      }
      
      if(child>1 && parent==-1) {
          mark[node] = 1;
      }
  }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        
        vector<int>visited(V,0);
        
        int low[V],tn[V];
        
        vector<int>mark(V,0);
        
        for(int i=0;i<V;i++){
            if(!visited[i]) {
                dfs(i,-1,adj,visited,low,tn,mark);
            }
        }
        
        vector<int>ans;
        for(int i=0;i<V;i++) {
            if(mark[i]==1) ans.push_back(i);
        }
        if(ans.size()==0) return {-1};
        return ans;
    }
};


//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	
cout << "~" << "\n";
}
	return 0;
}
// } Driver Code Ends