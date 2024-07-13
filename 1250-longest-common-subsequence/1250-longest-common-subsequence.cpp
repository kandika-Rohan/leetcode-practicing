class Solution {
public:
    int f(int ind1,int ind2,string text1,string text2,vector<vector<int>>&dp){
        if(ind1==0 || ind2==0){
            return 0;
        }
        //if both the characters are equal 
        if(dp[ind1][ind2] != -1){
            return dp[ind1][ind2];
        }
        if(text1[ind1-1]==text2[ind2-1]){
            return dp[ind1][ind2]=1+f(ind1-1,ind2-1,text1,text2,dp);
        }
        //if both the characters are not equal;
        else{
            return dp[ind1][ind2]=max(f(ind1-1,ind2,text1,text2,dp),f(ind1,ind2-1,text1,text2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,0));
        // for(int i=0;i<=n;i++){
        //     dp[0][i]=0;
        // }

        // for(int i=0;i<=m;i++){
        //     dp[i][0]=0;
        // }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[n][m];
    }
};