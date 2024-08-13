class Solution {
public:
    int f(int i,int j,vector<int>&nums,vector<vector<int>>&dp){
        if(i>j)return 0;

        if(dp[i][j] != -1)return dp[i][j];
        int op1=nums[i]+min(f(i+2,j,nums,dp),f(i+1,j-1,nums,dp));

        
        int op2=nums[j]+min(f(i+1,j-1,nums,dp),f(i,j-2,nums,dp));


        return dp[i][j]=max(op1,op2);
    }
    bool predictTheWinner(vector<int>& nums) {
        
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(n,-1));
        int val=f(0,n-1,nums,dp);
        cout<<val<<endl;
        int diff=total-val;

        return diff>val?false:true;
    }
};