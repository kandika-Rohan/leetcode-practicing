class Solution {
public:
    bool canPartition(vector<int>& nums) {

        int totalsum=accumulate(nums.begin(),nums.end(),0);

        int n=nums.size(); 

        if(totalsum <0 || (totalsum%2 != 0)){
            return false;
        }
        int sum=totalsum/2;

        vector<vector<bool>>dp(n,vector<bool>(sum+1,false));

        for(int i=0;i<n;i++){
            dp[i][0]=true; // if the totalsum is zero 
        }
        if(nums[0] <= sum){
            dp[0][nums[0]]=true;
        }

        for(int i=1;i<n;i++){
            for(int target=1;target<=sum;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target){
                    take=dp[i-1][target-nums[i]];
                }
                dp[i][target]=take || nottake;
            }
        }
        return dp[n-1][sum];
    }
};