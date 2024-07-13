class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>hash(n);
        for(int i=0;i<n;i++){
            hash[i]=i;
        }
        vector<int>dp(n,1);

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 && 1+dp[j]>dp[i])){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
        }

        int ans=-1;
        int lastind=-1;
        for(int i=0;i<n;i++){
            if(ans<dp[i]){
                ans=dp[i];
                lastind=i;
            }
        }
        vector<int>temp;
        temp.push_back(nums[lastind]);
        while(hash[lastind] != lastind){
            lastind=hash[lastind];
            temp.push_back(nums[lastind]);
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};