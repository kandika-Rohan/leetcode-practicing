class Solution {
public:
    int f(int n,vector<int>&dp){

        if(n<=1)return 1;
        if(dp[n] != -1)return dp[n];
        int ans=0;
        for(int i=1;i<=n;i++){
            ans+=f(i-1,dp)*f(n-i,dp);
        }

        return dp[n]=ans;
    }
    int numTrees(int n) {
        vector<int>dp(n+1,-1);
        return f(n,dp);
    }
};