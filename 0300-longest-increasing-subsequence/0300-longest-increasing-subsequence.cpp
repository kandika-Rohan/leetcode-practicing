class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxi=1;
        vector<int>dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j] && dp[j]+1>dp[i]){
                    dp[i]=1+dp[j];
                }
            }
            cout<<dp[i]<<" ";
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};