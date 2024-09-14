class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=nums[0];
        int prev2=0;
        for(int i=1;i<n;i++){
            int take=nums[i];
            if(i>1){
                take+=prev2;
            }
            int nontake=prev1+0;
            int curr=max(take,nontake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};