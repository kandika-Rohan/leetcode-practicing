class Solution {
public:
    int f(int i,int buy,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i == prices.size())return 0;
        if(k == 0)return 0;
        if(dp[i][buy][k] != -1)return dp[i][buy][k];
        int profit=0;
        if(buy){
            profit=max(f(i+1,0,k,prices,dp)-prices[i],f(i+1,1,k,prices,dp));
        }
        else{
             profit=max(f(i+1,1,k-1,prices,dp)+prices[i],f(i+1,0,k,prices,dp));
        }
        dp[i][buy][k]=profit;
        return dp[i][buy][k];
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return f(0,1,k,prices,dp);
    }
};