class Solution {
public:
    int f(int ind,vector<int>&arr,int n,int k,vector<int>&dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind] != -1){
            return dp[ind];
        }
        int maxians=0;
        int maxiele=0;
        int len=0;
        for(int j=ind;j<min(n,ind+k);j++){
            len++;
            maxiele=max(maxiele,arr[j]);
            int sum=len*maxiele+f(j+1,arr,n,k,dp);
            maxians=max(maxians,sum);
        }
        return dp[ind]=maxians;

    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int>dp(arr.size(),-1);
        return f(0,arr,arr.size(),k,dp);
    }
};