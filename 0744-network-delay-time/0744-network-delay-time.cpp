class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>>adj[n+1];

        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,
        greater<pair<int,int>>>q;

        vector<int>dist(n+1,1e9);

        q.push({0,k});
        dist[k]=0;

        while(!q.empty()){
            auto val=q.top();
            q.pop();
            int time=val.first;
            int node=val.second;

            for(auto it:adj[node]){
                int adjnode=it.first;
                int cost=it.second;
                if(cost+time < dist[adjnode]){
                    dist[adjnode]=cost+time;
                    q.push({cost+time,adjnode});
                }
            }
        }

       int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == 1e9) return -1; 
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;

    }
};