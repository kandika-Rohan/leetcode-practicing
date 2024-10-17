class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int h=nums.size()-1;
        int l=0;
        int ind=nums.size();
        while(l<=h)
        {
            int mid=l+(h-l)/2;
            if(nums[mid]>=target)
            {
                ind=mid;
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ind;
    }
};