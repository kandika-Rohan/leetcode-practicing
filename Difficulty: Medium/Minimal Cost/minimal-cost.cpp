//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   int f(int i,int k,vector<int>&height, vector<int>&dp){
       if(i==0){
           return 0;
       }
       if(dp[i] != -1){
           return dp[i];
       }
       int minsteps=INT_MAX;
       for(int j=1;j<=k;j++){
           if(i-j>=0){
               int take=f(i-j,k,height,dp)+abs(height[i]-height[i-j]);
               minsteps=min(minsteps,take);
           }
       }
       return dp[i]=minsteps;
   }
    int minimizeCost(vector<int>& height, int n, int k) {
        // Code here
        vector<int>dp(n+1,-1);
       return f(n-1,k,height,dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimizeCost(arr, N, K) << "\n";
    }
    return 0;
}
// } Driver Code Ends