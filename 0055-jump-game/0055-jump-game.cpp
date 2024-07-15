class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            if (i > maxi) {
                return false;
            }
            maxi = max(maxi, i + nums[i]);
            if (maxi >= n - 1) {
                return true;
            }
        }
       return false;
    }
};