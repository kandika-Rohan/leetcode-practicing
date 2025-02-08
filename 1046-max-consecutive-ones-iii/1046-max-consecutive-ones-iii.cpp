class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zerocount=0;
        int j=0;
        int i=0;
        int maxi=0;
        while(j<nums.size())
        {
            if(nums[j]==0)
            {
                zerocount++;
            }
            while(zerocount>k)
            {
                if(nums[i]==0)
                {
                    zerocount--;
                }
                i++;
            }
            maxi=max(maxi,j-i+1);
            j++;

        }
        return maxi;
    }
};