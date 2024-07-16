class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n - 2; i++) {
            // Skip duplicates for the first element
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            
            int j = i + 1;
            int r = n - 1;
            
            while (j < r) {
                int sum = nums[i] + nums[j] + nums[r];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[j], nums[r]});
                    
                    // Skip duplicates for the second element
                    while (j < r && nums[j] == nums[j + 1]) j++;
                    // Skip duplicates for the third element
                    while (j < r && nums[r] == nums[r - 1]) r--;
                    
                    j++;
                    r--;
                } else if (sum > 0) {
                    r--;
                } else {
                    j++;
                }
            }
        }
        
        return ans;
    }
};
