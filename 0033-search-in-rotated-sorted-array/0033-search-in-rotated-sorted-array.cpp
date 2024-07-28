class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[mid]>=nums[l]){
                if(nums[l]<=target && target <= nums[mid]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{//nums[mid]<=target
                if(nums[r]>=target && nums[mid]<=target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }
        }
        return -1;
    }
};