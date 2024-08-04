class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(1 << n, -1)); // dp table to store results
        sort(nums.begin(), nums.end()); // Sort nums to ensure we handle subsets properly

        return countBeautifulSubsets(nums, k, 0, 0, dp) - 1; // Subtract 1 to exclude the empty subset
    }

private:
    int countBeautifulSubsets(vector<int>& nums, int k, int index, int mask, vector<vector<int>>& dp) {
        if (index == nums.size()) {
            return 1; // Return 1 for each valid subset (including empty subset initially)
        }

        if (dp[index][mask] != -1) {
            return dp[index][mask];
        }

        // Exclude current element
        int result = countBeautifulSubsets(nums, k, index + 1, mask, dp);

        // Include current element if it does not violate the beautiful subset condition
        bool canInclude = true;
        for (int i = 0; i < nums.size(); ++i) {
            if (mask & (1 << i)) { // Check if element i is included in the current subset
                if (abs(nums[index] - nums[i]) == k) {
                    canInclude = false;
                    break;
                }
            }
        }

        if (canInclude) {
            result += countBeautifulSubsets(nums, k, index + 1, mask | (1 << index), dp);
        }

        return dp[index][mask] = result;
    }
};
