class Solution {
public:
    vector<bool> isArraySpecial(const vector<int>& nums, const vector<vector<int>>& queries) {
        int const n = nums.size();
        vector<int> violations(n, 0);
        int count = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] %2 == nums[i] %2){ count++; }
            violations[i] = count;
        }

        int const m = queries.size();
        vector<bool> ans(m);
        for(int i=0; i<m; i++){
            int s = queries[i][0];
            int e = queries[i][1];
            ans[i] = (violations[e] - violations[s] == 0);
        }
        return ans;
    }
};