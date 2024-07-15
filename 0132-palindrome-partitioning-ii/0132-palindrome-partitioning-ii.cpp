class Solution {
public:
    bool isPalindrome(string &s,int i,int j){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    int dfs(int i,int j,string s,vector<int> &dp){
        if(i >= j or isPalindrome(s,i,j)) return 0;
        if(dp[i] != -1) return dp[i];
        int ans = INT_MAX;
        for(int k=i;k<j;k++){
            if(isPalindrome(s,i,k)){
                int count = 1+dfs(k+1,j,s,dp);
                ans = min(ans,count);
            }
            
        }
        return dp[i] = ans;
    }
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        return dfs(0,n-1,s,dp);
    }
};