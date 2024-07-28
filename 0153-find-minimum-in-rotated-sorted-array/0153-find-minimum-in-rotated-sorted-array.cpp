class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid=(l+r)/2;
            if(nums[mid]>=nums[l]){
                ans=min(ans,nums[l]);//for the window the l is the min from mid to l
                l=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                r=mid-1;
            }
        }
        return ans;
    }
};