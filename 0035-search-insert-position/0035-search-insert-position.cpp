class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        int ans=nums.size();
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=target){
                r=mid-1;
                ans=mid;

            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};