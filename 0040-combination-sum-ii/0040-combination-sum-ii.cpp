class Solution {
public:
void cumsum(int ind,int target,vector<int>& arr,vector<int>&v,vector<vector<int>>&ans)
{
    if(target==0)
    {
        ans.push_back(v);
        return;
    }
    for(int i=ind;i<arr.size();i++)
    {
        if(i>ind && arr[i]==arr[i-1])continue;
        if(arr[i]>target)
        break;
        v.push_back(arr[i]);
        cumsum(i+1,target-arr[i],arr,v,ans);
        v.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>v;
        cumsum(0,target,candidates,v,ans);
        return ans;
    }
};