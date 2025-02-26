class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        
        int sum=0;

        int maxi=0;
        int mini=0;

        for(int i=0;i<nums.size();i++){

           maxi=max(maxi+nums[i],0);

           mini=min(mini+nums[i],0);
        }

        return maxi-mini;

        
    }
};