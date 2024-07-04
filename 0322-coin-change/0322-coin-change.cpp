class Solution {
public:
    int f(int ind,vector<int>&coins,int amount,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[0]==0){
                return amount/coins[0];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        int nottake=0+f(ind-1,coins,amount,dp);
        int take=1e9;
        if(amount>=coins[ind]){
            take=1+f(ind,coins,amount-coins[ind],dp);
        }
        return dp[ind][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();

        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
    int ans=f(coins.size()-1,coins,amount,dp);
        return ans==1e9?-1:ans;
    }
};