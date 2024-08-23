
class Disjointset{
    private:
    vector<int>parent,size,rank;
    public:
    Disjointset(int n){
        parent.resize(n+1);
        size.resize(n+1,1);
        rank.resize(n+1,0);
        for(int i=0;i<=n;i++){
            parent[i]=i;
        }
    }
    int findParnet(int x){
        if( x == parent[x])return x;
        return parent[x]=findParnet(parent[x]);
    }

    void unitBySize(int u,int v){
        int x=findParnet(u);
        int y=findParnet(v);
        if( x == y )return ;

        if(size[x] < size[y]){
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        

        int n=edges.size();
        Disjointset ds(n);

        vector<pair<int,int>>ans;
        
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            if(ds.findParnet(u) != ds.findParnet(v)){
                ds.unitBySize(u,v);
            }
            else{
                ans.push_back({u,v});
            }
        }

        int val1=ans.back().first;
        int val2=ans.back().second;
        return {val1,val2};

    }
};