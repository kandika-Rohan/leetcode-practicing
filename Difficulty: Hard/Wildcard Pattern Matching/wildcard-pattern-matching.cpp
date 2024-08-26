//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool f(int i,int j,string str,string pattern,vector<vector<int>>&dp){
        if(i==0 && j==0)return true;
        if(i != 0 && j==0)return false;
        if(dp[i][j] != -1)return dp[i][j];
        if(i == 0 && j != 0){
            for(int k=1;k<=j;k++){
                if(pattern[k-1] !='*'){
                    return false;
                }
            }
            return true;
        }
        
        
        if(str[i-1]  == pattern[j-1] || pattern[j-1] =='?' ){
            return dp[i][j]=f(i-1,j-1,str,pattern,dp);
        }
        else if(pattern[j-1] == '*'){
            return dp[i][j]=f(i-1,j,str,pattern,dp) || f(i,j-1,str,pattern,dp);
        }
        else{
            return dp[i][j]=false;
        }
    }
    int wildCard(string pattern, string str) {
        // code here
        int n=pattern.size();
        int m=str.size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return f(m,n,str,pattern,dp);
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