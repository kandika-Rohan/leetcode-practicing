class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {

        sort(begin(pairs),end(pairs));

        int n=pairs.size();

        vector<int>dp(n,1);

        int maxi=0;

        for(int i=0;i<n;i++){

            for(int j=0;j<i;j++){

                if(pairs[i][0]>pairs[j][1] && dp[j]+1>dp[i]){
                    
                    dp[i]=dp[j]+1;

                }
            }
            maxi=max(maxi,dp[i]);
        }
        return maxi;
    }
};