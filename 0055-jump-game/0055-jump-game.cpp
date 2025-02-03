class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int jumps=0;

        for(int i=0;i<nums.size();i++){

            if(i>jumps){
                return false;
            }
            jumps=max(jumps,nums[i]+i);
            if(jumps>=nums.size()-1)return true;
        }
        return false;
    }
};