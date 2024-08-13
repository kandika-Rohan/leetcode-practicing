class Solution {
public:
    int minDistance(string word1, string word2) {
        

        int n=word1.size();
        int m=word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i=1;i<=n;i++){
            dp[i][0]=i;
        }
         for(int i=1;i<=m;i++){
            dp[0][i]=i;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(word1[i-1] == word2[j-1]){
                    //we do not need any operations required to do this
                    dp[i][j]=0+dp[i-1][j-1];
                }
                else{
                    
                    int insert=1+dp[i-1][j];
                    int del=1+dp[i][j-1];
                    int replace=1+dp[i-1][j-1];
                    dp[i][j]=min({insert,del,replace});
                }
            }
        }

        for(auto it:dp){
            for(auto i:it){
                cout<<i<<" ";
            }
            cout<<endl;
        }

        return dp[n][m];
    }
};