class Solution {
public:

    bool ispossible(int mid,vector<int>&nums,int k){
        int sum=0;
        for(int i=0;i<nums.size();i++){
            sum+=ceil((double)nums[i]/(double)mid);
            if(sum >k){
                return false;
            }
        }
        return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        // int totalsum=accumulate(nums.begin(),nums.end(),0);
        int l=1;
        int r=*max_element(nums.begin(),nums.end());
        int ans=-1;
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(ispossible(mid,nums,threshold)){
                ans=mid;
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};