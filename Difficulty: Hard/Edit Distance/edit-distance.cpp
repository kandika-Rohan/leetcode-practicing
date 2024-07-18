//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int f(int i,int j,string s,string t,int n,int m,vector<vector<int>>&dp){
        if(i<0){
            return j+1;
        }
        if(j<0){
            return i+1;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i]==t[j]){
            return 0+f(i-1,j-1,s,t,n,m,dp);
        }
        int insert=1+f(i,j-1,s,t,n,m,dp);
        int delete1=1+f(i-1,j,s,t,n,m,dp);
        int replace=1+f(i-1,j-1,s,t,n,m,dp);
        
        return dp[i][j]=min({insert,delete1,replace});
    }
    int editDistance(string s, string t) {
        // Code here
        int n=s.size();
        int m=t.size();
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return f(n-1,m-1,s,t,n,m,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends