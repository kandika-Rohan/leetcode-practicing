//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int i,int n,vector<int>&heights,vector<int>&dp){
        if(i == 0)
        return 0;
        
        if(dp[i] != -1)return dp[i];
        int nottake=1e9;
        if(i>0){
        nottake=f(i-1,n,heights,dp)+abs(heights[i]-heights[i-1]);
        }
        
        int take=1e9;
        if(i>1){
            take=f(i-2,n,heights,dp)+abs(heights[i]-heights[i-2]);
        }
        
        return dp[i]=min(take,nottake);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n+1,-1);
        return f(n-1,n,height,dp);
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends