class Solution {
public:
    bool f(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(i==0){
            return true;
        }
        if(j==0){
            return false;
        }
        if(dp[i][j]  != -1){
            return dp[i][j];
        }
        if(s[i-1] == t[j-1]){
            return dp[i][j]=f(i-1,j-1,s,t,dp) || f(i,j-1,s,t,dp);
        }
        else return dp[i][j]=f(i,j-1,s,t,dp);
    }
    bool isSubsequence(string s, string t) {
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n,m,s,t,dp);
    }
};