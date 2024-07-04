class Solution {
public:
const int mod=1e9+7;
    int f(int ind, vector<int>& nums, int target,vector<vector<int>>&dp) {
        if (ind == 0) {
            if (target == 0 && nums[0] == 0) {
                return 2;
            }
            if (target == 0 || target == nums[0]) { // Corrected: Check if target is 0 or if the target is the first element
                return 1;
            }
            return 0;
        }
        if(dp[ind][target] != -1){
        return dp[ind][target];
        }

        int nottake = f(ind - 1, nums, target,dp);
        int take = 0;
        if (target >= nums[ind]) {
            take = f(ind - 1, nums, target - nums[ind],dp); // Corrected: Subtract the current element from the target
        }
        return dp[ind][target]=(take + nottake)%mod;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int totalsum = accumulate(nums.begin(), nums.end(), 0);
        
        if ((totalsum - target) < 0 || (totalsum - target) % 2 != 0) {
            return 0;
        }
        int s1 = (totalsum - target) / 2;
        vector<vector<int>>dp(nums.size(),vector<int>(s1+1,-1));
        return f(nums.size() - 1, nums, s1,dp);
    }
};
