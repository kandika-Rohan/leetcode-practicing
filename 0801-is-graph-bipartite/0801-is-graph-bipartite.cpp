class Solution {
public:
    bool dfs(int node,vector<int>&vis,int col,vector<int>&color,vector<int>adj[]){
        vis[node]=1;
        color[node]=col;
        for(auto it:adj[node]){
            if(!vis[it]){
                if(dfs(it,vis,!col,color,adj)==false){
                    return false;
                }
            }
            else if(color[it]==col){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        int m=graph[0].size();
        vector<int>color(n,-1);
        vector<int>vis(n,0);
        vector<int>adj[n];
        for (int i = 0; i < n; i++) {
            for (int j : graph[i]) {
                adj[i].push_back(j);
                adj[j].push_back(i); 
            }
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,vis,0,color,adj)==false){
                    return false;
                }
            }
        }
        return true;
    }
};