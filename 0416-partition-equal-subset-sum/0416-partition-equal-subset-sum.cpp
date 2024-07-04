class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int totalsum=accumulate(nums.begin(),nums.end(),0);
        
        
        if(totalsum %2 != 0){
            return false;
        }
        int k=totalsum/2;
        int n=nums.size();
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        if(nums[0]<=k){
            dp[0][nums[0]]=true;
        }
        for(int i=0;i<n;i++){
            dp[i][0]=true;
        }
        for(int i=1;i<n;i++){
            for(int target=1;target<=k;target++){
                bool nottake=dp[i-1][target];
                bool take=false;
                if(nums[i]<=target){
                    take=dp[i-1][target-nums[i]];
                }
                dp[i][target]=nottake || take;
            }
        }
        return dp[n-1][k];
    }
};