class Solution {
public:
    // int f(int ind,int prev_ind,vector<int>&nums,int n,vector<vector<int>>&dp){
    //     if(ind == n){
    //         return 0;
    //     }
    //     if(dp[ind][prev_ind+1] != -1){
    //         return dp[ind][prev_ind+1];
    //     }
    //     int nottake=f(ind+1,prev_ind,nums,n,dp);
    //     int take=0;
    //     if(prev_ind == -1 || nums[prev_ind] < nums[ind]){
    //         take=1+f(ind+1,ind,nums,n,dp);
    //     }
    //     return dp[ind][prev_ind+1]=max(take,nottake);
    // }
  int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;

    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int i = n - 1; i >= 0; --i) {
        for (int prev = i - 1; prev >= -1; --prev) {
            int notTake = dp[i + 1][prev + 1];
            int take = 0;
            if (prev == -1 || nums[i] > nums[prev]) {
                take = 1 + dp[i + 1][i + 1];
            }
            dp[i][prev + 1] = max(take, notTake);
        }
    }

    return dp[0][0];
}

};