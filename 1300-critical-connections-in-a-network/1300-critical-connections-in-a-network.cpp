class Solution {
public:

    int time=1;
    void dfs(int node,int parent,vector<int>&vis,vector<int>adj[],int low[],int timein[],
    vector<vector<int>>&bridges){
        vis[node]=1;
        low[node]=timein[node]=time;
        time++;
        for(auto it:adj[node]){
            if(it == parent)continue;
            if(!vis[it]){
                dfs(it,node,vis,adj,low,timein,bridges);

            }
                //after completing node's traversal
                low[node]=min(low[it],low[node]);

                if(low[it]>timein[node]){
                    bridges.push_back({min(it,node),max(it,node)});
                }
                else{
                    low[it]=min(low[it],low[node]);
                }
            
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        
        vector<int>adj[n];

        for(auto it:connections){
            int u=it[0];
            int v=it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }

        vector<vector<int>>bridges;
        vector<int>vis(n,0);
        int timein[n];
        int low[n];

        dfs(0,-1,vis,adj,low,timein,bridges);
        return bridges;
    }
};