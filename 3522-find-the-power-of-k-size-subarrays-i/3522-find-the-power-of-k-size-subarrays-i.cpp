class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<=n-k;i++) {
            int c =0;
            for(int j=i; j<i+k-1;j++) {
               if((nums[j] >= nums[j + 1]) || (nums[j+1]-nums[j]!=1)) {
                  c=1;
                  break;
                }
            }
        if(c==0) {
            ans.push_back(nums[i + k - 1]); 
        } 
        else {
            ans.push_back(-1);
        }
    }
    return ans;
    }
};