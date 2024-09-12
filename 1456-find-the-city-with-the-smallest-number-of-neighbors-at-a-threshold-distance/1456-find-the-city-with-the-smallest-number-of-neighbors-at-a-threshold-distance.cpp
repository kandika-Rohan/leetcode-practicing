class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        vector<vector<int>>mat(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i == j){
                mat[i][j]=0;
                }
            }
        }

        for(auto it:edges){
            int  u=it[0];
            int v=it[1];
            int wt=it[2];
            mat[u][v]=wt;
            mat[v][u]=wt;
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
                }
            }
        }
        for(auto it:mat){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        int ans=-1;
        int cnt=INT_MAX;
        for(int i=0;i<n;i++){
            int c=0;
            for(int j=0;j<n;j++){
                if(mat[i][j] <= distanceThreshold){
                    c++;
                }
            }
            if(c<=cnt){
                cnt=c;
                ans=i;
            }
        }
        return ans;

    }
};