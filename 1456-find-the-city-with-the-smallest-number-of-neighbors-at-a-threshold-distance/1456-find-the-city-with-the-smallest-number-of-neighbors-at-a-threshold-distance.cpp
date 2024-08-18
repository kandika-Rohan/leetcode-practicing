class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        


        vector<vector<int>>adj(n,vector<int>(n,1e9));
        for(int i=0;i<n;i++){
            adj[i][i]=0;
        }
        for(auto it:edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            adj[u][v]=wt;
            adj[v][u]=wt;
        }

        for(int via=0;via<n;via++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(adj[i][via] == 1e9 || adj[via][j] == 1e9)continue;
                    adj[i][j]=min(adj[i][j],adj[i][via]+adj[via][j]);
                }
            }
        }

        for(auto it:adj){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        int city=-1;
        int citycnt=n;

        for(int i=0;i<n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(adj[i][j] <= distanceThreshold){
                    cnt++;
                }
            }

            if (cnt <= citycnt) { 
                citycnt = cnt;
                city = i;
            }
        }
        return city;
    }
};