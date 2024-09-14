class Solution {
public:
    bool f(int i,int sum,vector<int>&nums,vector<vector<int>>&dp){
        if(i == 0)return sum == nums[0];
        if( sum == 0)return true;
        if(dp[i][sum] != -1)return dp[i][sum];
        bool nt=f(i-1,sum,nums,dp);
        bool t=false;
        if(sum >= nums[i]){
            t=f(i-1,sum-nums[i],nums,dp);
        }
        return dp[i][sum]=nt||t;
    }
    bool canPartition(vector<int>& nums) {

        int n=nums.size();
        
        int totalSum=accumulate(nums.begin(),nums.end(),0);

        if(totalSum % 2 !=0 || totalSum <0)return false;
        int k=totalSum/2;
        vector<vector<int>>dp(n,vector<int>(k+1,-1));

        return f(n-1,k,nums,dp);
    }
};