class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        vector<int>dp(pairs.size(),1);
        int maxi=1;
        for(int i=1;i<pairs.size();i++){
            for(int j=0;j<i;j++){
                if(pairs[i][0] > pairs[j][1] && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};