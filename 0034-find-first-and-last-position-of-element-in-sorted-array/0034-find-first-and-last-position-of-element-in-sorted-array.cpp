class Solution {
public:
    int first(vector<int>&nums,int target){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                r=mid-1;
                ans=mid;
            }
            else if(nums[mid] > target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return ans;
    }
       int second(vector<int>&nums,int target){
        int l=0;
        int r=nums.size()-1;
        int ans=-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]==target){
                l=mid+1;
                ans=mid;
            }
            else if(nums[mid] > target){
                r=mid-1;
            }
            else{
                l=mid+1;
            }
            
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int one=first(nums,target);
        int two=second(nums,target);
        return {one,two};
    }
};