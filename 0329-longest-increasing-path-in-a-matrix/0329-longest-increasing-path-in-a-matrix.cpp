class Solution {
public:
    int delrow[4]={-1,0,1,0};
    int delcol[4]={0,1,0,-1};

    int f(int i,int j,vector<vector<int>>&dp,vector<vector<int>>&mat,int n,int m){
        if(dp[i][j] != -1 ){
            return dp[i][j];
        }

        int maxlen=1;
        for(int k=0;k<4;k++){
            int x=i+delrow[k];
            int y=j+delcol[k];

            if(x >=0 && x<n && y>=0 && y< m && mat[i][j] < mat[x][y]){
                maxlen=max(maxlen,1+f(x,y,dp,mat,n,m));
            }
        }
        dp[i][j]=maxlen;

        return dp[i][j];

    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        int res=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res=max(res,f(i,j,dp,matrix,n,m));
            }
        }
        return res;
    }
};