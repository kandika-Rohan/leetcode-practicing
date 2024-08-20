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
    int findparent(int x){
        if(x == parent[x]){
            return x;
        }
        return parent[x]=findparent(parent[x]);
    }

    void uniteBysize(int u,int v){
        int x=findparent(u);
        int y=findparent(v);
        if(x == y)return ;
        if(size[x]<size[y]){
            size[y]+=size[x];
            parent[x]=y;
        }
        else{
            size[x]+=size[y];
            parent[y]=x;
        }
    }
};
class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        
        int n=accounts.size();
        Disjointset ds(n);
        unordered_map<string,int>mapping;

        for(int i=0;i<n;i++){
            // Correction: Changed j<n to j<accounts[i].size() 
            // because you want to iterate over all emails in the account.
            for(int j=1;j<accounts[i].size();j++){
                string email=accounts[i][j];
                if(mapping.find(email) != mapping.end()){
                    ds.uniteBysize(i,mapping[email]);
                }
                else{
                    mapping[email]=i;
                }
            }
        }

        vector<string>merged[n];

        for(auto it:mapping){
            int node=ds.findparent(it.second);
            string mail=it.first;
            merged[node].push_back(mail);
        }

        vector<vector<string>>ans;
        for(int i=0;i<n;i++){

            if(merged[i].size() == 0)continue;

            sort(merged[i].begin(),merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }

            ans.push_back(temp);
        }

        return ans;
    }
};
