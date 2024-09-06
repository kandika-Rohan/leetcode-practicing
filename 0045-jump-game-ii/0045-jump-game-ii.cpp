class Solution {
public:
    int jump(vector<int>& nums) {
        int jumps=0;
        int n=nums.size();
        int l=0;
        int r=0;
        while(r<n-1){
            int fast=0;
            for(int i=l;i<=r;i++){
                fast=max(fast,nums[i]+i);
            }
            l=r+1;
            r=fast;
            jumps++;
        }
        return jumps;
    }
};