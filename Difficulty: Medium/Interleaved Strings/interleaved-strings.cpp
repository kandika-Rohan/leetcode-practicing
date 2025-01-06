//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
   bool f(int i,int j,string A, string B, string C, vector<vector<int>> &dp){
        if (i<0 and j<0) return true;
        if (i<0 and j>=0){
            return B.substr(0,j+1)==C.substr(0,j+1);
        }
        if (i>=0 and j<0){
           return A.substr(0,j+1)==A.substr(0,j+1);
        }
        if (dp[i][j]!=-1) return dp[i][j];
        if (A[i]==C[i+j+1]){
             dp[i][j]=f(i-1,j,A,B,C,dp);
             if (dp[i][j]) return true;
        }
         if (B[j]==C[i+j+1]){
            
             dp[i][j]=f(i,j-1,A,B,C,dp);
             if (dp[i][j]) return true;
        }
        
            return dp[i][j]=false;
        
    }
  public:
    /*You are required to complete this method */
    bool isInterleave(string A, string B, string C) 
    {
        //Your code here
        int a=A.size();
        int b=B.size();
        int c=C.size();
        if (a+b<c or a+b>c) return false;
        vector<vector<int>> dp(a,vector<int>(b,-1));
        return f(a-1,b-1,A,B,C,dp);
    }


};



//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string a, b, c;
        cin >> a;
        cin >> b;
        cin >> c;
        Solution obj;
        if (obj.isInterleave(a, b, c))
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
    // your code goes here
    return 0;
}
// } Driver Code Ends