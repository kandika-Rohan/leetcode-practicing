class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {


        vector<int>dist(n+1,1e9);

        vector<pair<int,int>>adj[n+1];

        for(auto it:times){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u].push_back({v,wt});
        }
        using p=pair<int,int>;
        priority_queue<p,vector<p>,greater<p>>q;

        q.push({0,k});

        dist[k]=0;
        dist[0]=0;

        while(!q.empty()){
            auto val=q.top();
            q.pop();
            int time=val.first;
            int node=val.second;

            for(auto it:adj[node]){
                int t=it.second;
                int adjnode=it.first;
                if(dist[adjnode]>t+time){
                    dist[adjnode]=t+time;
                    q.push({t+time,adjnode});
                }
            }
        }
        int maxi=0;
        for(auto it:dist){
            if(it == 1e9)return -1;
            maxi=max(maxi,it);
            cout<<it<<" ";
        }
        return maxi;
    }
};