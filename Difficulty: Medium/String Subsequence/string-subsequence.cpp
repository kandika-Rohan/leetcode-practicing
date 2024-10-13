//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    const int mod=1e9+7;
    int f(int i,int j,string s1,string s2,vector<vector<int>>&dp){
        if(i == 0 && j != 0)return 0;
        if(i != 0 && j == 0)return 1;
        if(i == 0 && j == 0)return 1;
        
        if(dp[i][j] != -1)return dp[i][j];
  
        if(s1[i-1] == s2[j-1]){
            return dp[i][j]=(f(i-1,j-1,s1,s2,dp)+f(i-1,j,s1,s2,dp))%mod;
        }
        else{
            return dp[i][j]=f(i-1,j,s1,s2,dp)%mod;
        }
    }
    int countWays(string s1, string s2) {
        
        int n=s1.size();
        
        int m=s2.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return f(n,m,s1,s2,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        string s1;
        getline(cin, s1);

        string s2;
        getline(cin, s2);

        Solution obj;
        int res = obj.countWays(s1, s2);

        cout << res << endl;
    }
}

// } Driver Code Ends