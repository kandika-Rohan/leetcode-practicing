
class DSU{
    private:
    vector<int>parent,size;
    public:
    DSU(int n){
        parent.resize(n+1);
        size.resize(n+1,1);

        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int find(int x){
        if(x == parent[x])return x;

        return parent[x]=find(parent[x]);
    }

    void unite(int u,int v){
        int x=find(u);
        int y=find(v);
        if(x == y )return;

        if(size[x]<size[y]){
            size[y]+=size[x];
            parent[x]=y;
        }
        else if(size[x]>size[y]){
            size[x]+=size[y];
            parent[y]=x;
        }
        else{
            size[x]+=size[y];
            parent[y]=x;
        }
    }
};
class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        

        int n=points.size();

        DSU ds(n);

        using p=pair<int,pair<int,int>>;

        vector<p>adj;

        for(int i=0;i<n;i++){

            for(int j=i+1;j<n;j++){

                int dist=abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]);

                adj.push_back({dist,{i,j}});
            }
        }

        sort(adj.begin(),adj.end());

        int ans=0;

        for(auto it:adj){
            int wt=it.first;
            int u=it.second.first;
            int v=it.second.second;
            if(ds.find(u) != ds.find(v)){
                ans+=wt;
                ds.unite(u,v);
            }
            else{
                continue;
            }
        }
        return ans;
    }
};