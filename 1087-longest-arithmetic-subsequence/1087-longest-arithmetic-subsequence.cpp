
class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;

        
        vector<unordered_map<int, int>> dp(n);

        int maxLength = 2;

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                int diff = nums[i] - nums[j]; 

                
                dp[i][diff] = dp[j].count(diff) ? dp[j][diff] + 1 : 2;

               
                maxLength = max(maxLength, dp[i][diff]);
            }
        }

        return maxLength;
    }
};
