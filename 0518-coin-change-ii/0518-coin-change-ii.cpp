class Solution {
public:
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            return (amount%coins[ind]==0);
        }
        if(dp[ind][amount] != -1){
            return dp[ind][amount];
        }
        int nottake=f(ind-1,amount,coins,dp);
        int take=0;
        if(coins[ind]<=amount){
            take=f(ind,amount-coins[ind],coins,dp);
        }
        return dp[ind][amount]=(take+nottake);
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>dp(coins.size(),vector<int>(amount+1,-1));
        return f(coins.size()-1,amount,coins,dp);
    }
};