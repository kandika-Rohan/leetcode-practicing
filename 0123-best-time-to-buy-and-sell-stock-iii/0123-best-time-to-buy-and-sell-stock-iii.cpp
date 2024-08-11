class Solution {
public:
    int solve(int i,int buy ,int limit,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(i == prices.size())return 0;
        if(limit==0) return 0;

        if(dp[i][buy][limit] != -1)return dp[i][buy][limit];
        int profit=0;

        if(buy){
            profit=max(solve(i+1,0,limit,prices,dp)-prices[i],solve(i+1,1,limit,prices,dp));
        }
        else{
             profit=max(solve(i+1,1,limit-1,prices,dp)+prices[i],solve(i+1,0,limit,prices,dp));
        }
        dp[i][buy][limit]=profit;
        return dp[i][buy][limit];
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return solve(0,1,2,prices,dp);
    }
};