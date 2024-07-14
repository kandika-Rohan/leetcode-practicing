class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        //base case total sum is odd it is not possible to divide the array into tow equal sums

        if(totalsum%2){
            return false;
        }
        int curr_sum=totalsum/2;
        int n=nums.size();

        vector<vector<int>>dp(n,vector<int>(curr_sum+1,0));

        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }

        if(nums[0]<=curr_sum){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int target=0;target<=curr_sum;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(target>=nums[i]){
                    take=dp[i-1][target-nums[i]];
                }
                dp[i][target]=take || nottake;
            }
        }
        return dp[n-1][curr_sum];
    }
};