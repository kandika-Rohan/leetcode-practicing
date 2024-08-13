class Solution {
public:
    int f(int i,int j,vector<int>&nums){
        if(i>j)return 0;

        int op1=nums[i]+min(f(i+2,j,nums),f(i+1,j-1,nums));

        
        int op2=nums[j]+min(f(i+1,j-1,nums),f(i,j-2,nums));


        return max(op1,op2);
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);

        int val=f(0,n-1,nums);
        cout<<val<<endl;

        int diff=total-val;

        return diff>val?false:true;
    }
};