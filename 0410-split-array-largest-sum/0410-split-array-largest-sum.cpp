class Solution {
public:
    bool ispossible(int mid,vector<int>& nums, int k){
        int cnt=1;
        int sum=0;
        for(int i=0;i<nums.size();i++){
            if(sum+nums[i]<=mid){
                sum+=nums[i];
            }
            else{
                cnt++;
                if(cnt > k || nums[i]>mid){
                    return false;
                }
                sum=nums[i];
            }
        }
        return cnt <=k;
    }
    int splitArray(vector<int>& nums, int k) {
        int l=*max_element(nums.begin(),nums.end());
        int r=accumulate(nums.begin(),nums.end(),0);
        int ans=l;
        while(l<=r){
            int mid=(l+r)/2;
            if(ispossible(mid,nums,k)){
                r=mid-1;
                ans=mid;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};