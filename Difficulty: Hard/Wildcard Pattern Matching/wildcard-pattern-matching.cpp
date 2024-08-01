//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool f(int i,int j,string s,string p, vector<vector<int>>&dp){
        if(i==0 && j== 0){
            return true;
        }
        if(i>0 && j==0){
            return false;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i==0 && j>0){
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }
        if(s[i-1] == p[j-1] || p[j-1] =='?'){
            return dp[i][j]=f(i-1,j-1,s,p,dp);
        }
        else if(p[j-1] =='*'){
            return dp[i][j]=f(i-1,j,s,p,dp)||f(i,j-1,s,p,dp);
        }
        else{
            return false;
        }
    }
    int wildCard(string pattern, string str) {
        int n=str.size();
        int m=pattern.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return f(n, m, str, pattern,dp) ? 1 : 0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends