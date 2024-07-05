class Solution {
public:
    void solve(int i,int n,vector<int>&nums,vector<int>&ds,vector<vector<int>>&ans){
        if(i>=n){
            ans.push_back(ds);
            return;
        }
        ds.push_back(nums[i]);
        solve(i+1,n,nums,ds,ans);
        ds.pop_back();
        solve(i+1,n,nums,ds,ans);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>ds;
        solve(0,nums.size(),nums,ds,ans);
        return ans;
    }
};