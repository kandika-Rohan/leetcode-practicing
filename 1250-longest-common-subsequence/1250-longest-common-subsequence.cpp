class Solution {
public:
    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i<0 || j<0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s1[i]==s2[j]){
            return dp[i][j]=1+f(i-1,j-1,s1,s2,dp);
        }
        else{
            return dp[i][j]=0+max(f(i-1,j,s1,s2,dp),f(i,j-1,s1,s2,dp));
        }
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,text1,text2,dp);
    }
};