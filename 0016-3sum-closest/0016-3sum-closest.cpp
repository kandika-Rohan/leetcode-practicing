class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int curr_sum=INT_MAX/2;
        int n=nums.size();
        for(int i=0;i<n-2;i++){
            int j=i+1;
            int k=n-1;
            while(j<k){
                int sum=nums[i]+nums[j]+nums[k];
                if(abs(sum -target)<abs(curr_sum-target)){
                    curr_sum=sum;
                }
                if(sum <target){
                    j++;
                }
                else if(sum > target){
                    k--;
                }
                else{
                    return sum;
                }
            }
      
        }
        return curr_sum;
    }
};