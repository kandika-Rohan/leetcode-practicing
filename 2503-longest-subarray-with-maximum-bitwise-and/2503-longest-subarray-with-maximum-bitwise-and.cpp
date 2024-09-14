class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int maxiele=*max_element(nums.begin(),nums.end());

        int ans=1;
        int subarraysize=0;

        for(int i=0;i<n;i++){
            if(nums[i] == maxiele){
                subarraysize++;
                ans=max(ans,subarraysize);
            }
            else{
                subarraysize=0;
            }
        }

        return ans;
    }
};