class Solution {
public:
    int function(int n,vector<int>&nums,vector<int>&dp){

        if(n==0){
            return nums[n];
        }

        if(n<0){
            return 0;

        }
        if(dp[n] != -1){
            return dp[n];
        }

        int first=nums[n]+function(n-2,nums,dp);

        int second=0+function(n-1,nums,dp);

        return dp[n]=max(first,second);
    }
    int rob(vector<int>& nums) {
        int n=nums.size();

        vector<int>dp(n+1,-1);

        return function(n-1,nums,dp);
        
    }
};