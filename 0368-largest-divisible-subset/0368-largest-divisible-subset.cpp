class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>dp(n,1);
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j] == 0 && 1+dp[j]>dp[i]){
                    dp[i]=1+dp[j];
                    hash[i]=j;
                }
            }
        }

        int ans=-1;
        int ind=-1;
        for(int i=0;i<n;i++){
            if(dp[i]>ans){
                ans=dp[i];
                ind=i;
            }
        }
        vector<int>res;
        res.push_back(nums[ind]);

        while(hash[ind] != ind){
            ind=hash[ind];
            res.push_back(nums[ind]);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};