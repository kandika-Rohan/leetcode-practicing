class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int m = 1e9 + 7;
        vector<int> sums;
        sums.reserve(n * (n + 1) / 2); 
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            for (int j = i; j < n; ++j) {
                sum = (sum + nums[j]) % m;
                sums.push_back(sum);
            }
        }
        
       
        nth_element(sums.begin(), sums.begin() + left - 1, sums.end());
        nth_element(sums.begin() + left, sums.begin() + right, sums.end());
        
        sort(sums.begin() + left - 1, sums.begin() + right);
        
        int ans = 0;
        for (int i = left - 1; i < right; ++i) {
            ans = (ans + sums[i]) % m;
        }
        
        return ans;
    }
};
