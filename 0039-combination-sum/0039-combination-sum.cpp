class Solution {
public:
   void solve(int ind,int n,int target,vector<int>&candidates,vector<int>&ds,vector<vector<int>>&ans){
    if(ind==n){
        if(target==0){
            ans.push_back(ds);
        }
        return ;
    }
    if(target>=candidates[ind]){
        ds.push_back(candidates[ind]);
        solve(ind,n,target-candidates[ind],candidates,ds,ans);
        ds.pop_back();
    }
    solve(ind+1,n,target,candidates,ds,ans);
   }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,candidates.size(),target,candidates,ds,ans);
        return ans;
    }
};