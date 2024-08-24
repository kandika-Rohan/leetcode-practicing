class Solution {
public:
    void dfs(int node,vector<int>adj[],vector<vector<int>>&ans,vector<int>&ds,vector<int>&vis,int dest){

        vis[node]=1;
        ds.push_back(node);
        if(node == dest){
          ans.push_back(ds);
        }
   
       else{
         for(auto it:adj[node]){
            if(!vis[it]){
                dfs(it,adj,ans,ds,vis,dest);
            }
        }
       }
        ds.pop_back();
        vis[node]=0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        int n=graph.size();
        vector<int>adj[n];
        vector<int>vis(n,0);
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }

        vector<int>ds;
        vector<vector<int>>ans;
        
    
        dfs(0,adj,ans,ds,vis,n-1);
       

        return ans;
    }
};