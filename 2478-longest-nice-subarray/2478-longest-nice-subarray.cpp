class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int i=1;
        int lul=nums[0];
        int j=0;
        int ans=1;
        while(i<nums.size()){
        while(j<=i && (lul & nums[i])){
            lul^=nums[j++];
            ans=max(ans,i-j+1);
        }
        lul|=nums[i];
        ans=max(ans,i-j+1);
        i++;
        }
        return ans;
    }
};