class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        
        int maxi=0;

        

        int cnt=1;

        for(int i=0;i<nums.size()-1;i++){

            if(nums[i]<nums[i+1]){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=1;
            }

        }

        cnt=1;

         for(int i=0;i<nums.size()-1;i++){

            if(nums[i]>nums[i+1]){
                cnt++;
                maxi=max(maxi,cnt);
            }
            else{
                cnt=1;
            }

        }

        return maxi == 0?1:maxi;


    }
};