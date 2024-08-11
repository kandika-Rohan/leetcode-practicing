//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(int i,int buy,int k,int n,int A[],vector<vector<vector<int>>>&dp){
        if( i >= n)return 0;
        if(k == 0)return 0;
        if(dp[i][buy][k] != -1)return dp[i][buy][k];
        int profit=0;
        if(buy){
            profit=max(f(i+1,0,k,n,A,dp)-A[i],f(i+1,1,k,n,A,dp));
        }
        else{
            profit=max(f(i+1,1,k-1,n,A,dp)+A[i],f(i+1,0,k,n,A,dp));
        }
        return dp[i][buy][k]=profit;
    }
    int maxProfit(int K, int N, int A[]) {
        // code here
        vector<vector<vector<int>>>dp(N,vector<vector<int>>(2,vector<int>(K+1,-1)));
        return f(0,1,K,N,A,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}
// } Driver Code Ends