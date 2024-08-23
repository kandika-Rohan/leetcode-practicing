class Solution {
public:
    int f(int prev,int i,int curr,int k,vector<int>&nums,int n,vector<vector<vector<int>>>&dp){
        if(i == n){
            return 0;
        }

        if(dp[i][prev+1][curr] != -1)return dp[i][prev+1][curr];
        
        int nottake=f(prev,i+1,curr,k,nums,n,dp);
        int take=0;
        if(prev == -1 || nums[i] == nums[prev]){
            take=1+f(i,i+1,curr,k,nums,n,dp);
        }
        else if(curr < k){
            take=1+f(i,i+1,curr+1,k,nums,n,dp);
        }
        return dp[i][prev+1][curr]=max(take,nottake);
    }
    int maximumLength(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(n,vector<int>(k+1,-1)));
        return f(-1,0,0,k,nums,nums.size(),dp);
    }
};