//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i,int j,vector<vector<int>>&mat,int n,int m,
    vector<vector<int>>dp){
       
        if(j>=m || i>=n || j<0 || i<0){
            return 0;
        }
        
         
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        
        int right=f(i,j+1,mat,n,m,dp);
        int rdiag=f(i-1,j+1,mat,n,m,dp);
        int downdiag=f(i+1,j+1,mat,n,m,dp);
        
        return dp[i][j]=max({right,rdiag,downdiag})+mat[i][j];
        
    }
    int maxGold(vector<vector<int>>& mat) {
        // code here
        
        int n=mat.size();
        
        int m=mat[0].size();
        
       
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            
            dp[i][m-1]=mat[i][m-1];
        }
        
        int maxi=0;
        
        for(int j=m-2;j>=0;j--){
            
            for(int i=0;i<n;i++){
                
                dp[i][j]=max(dp[i][j],dp[i][j+1]+mat[i][j]);
                
                if(i+1<n){
                    dp[i][j]=max(dp[i][j],dp[i+1][j+1]+mat[i][j]);
                }
                
                if(i-1>=0){
                    dp[i][j]=max(dp[i][j],dp[i-1][j+1]+mat[i][j]);
                }
                
                maxi=max(maxi,dp[i][j]);
            }
        }
        
        return maxi;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                cin >> mat[i][j];
        }
        cin.ignore();
        Solution ob;
        cout << ob.maxGold(mat) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends