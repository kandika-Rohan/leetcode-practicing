class DisjointSet{
    vector<int>parent,size,rank;
    public:
    DisjointSet(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }

    int findParent(int x){
        if(x == parent[x])return x;
        return parent[x]=findParent(parent[x]);
    }

    void uniteBySize(int u,int v){
        int x=findParent(u);
        int y=findParent(v);
        if(x == y)return;
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
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        DisjointSet ds(n);

        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u) == ds.findParent(v))continue;
            if(ds.findParent(u) != ds.findParent(v)){
                ds.uniteBySize(u,v);
            }
        }

        if(ds.findParent(source) == ds.findParent(destination))return true;
        return false;
    }
};