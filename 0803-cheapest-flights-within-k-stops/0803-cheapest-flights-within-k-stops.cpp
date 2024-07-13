class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        //making graph using the adjacency list
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }

        queue<pair<int,pair<int,int>>>q;//{stops,{node,weight}};
        vector<int>dist(n,1e9);
        dist[src]=0;
        q.push({0,{src,0}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();

            int stops=node.first;
            int v=node.second.first;
            int cost=node.second.second;
            if(stops>k){
                continue;
            }
            for(auto it:adj[v]){
                if(it.second+cost<dist[it.first] && stops<=k){
                   dist[it.first]=it.second+cost;
                   q.push({stops+1,{it.first,cost+it.second}});
                }
            }
        }
        if(dist[dst]==1e9){
            return -1;
        }
        return dist[dst];
    }
};