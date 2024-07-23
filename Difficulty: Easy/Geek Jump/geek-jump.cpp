//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind,vector<int>&height){
        if(ind == 0){
            return 0;
        }
        int onejump=f(ind-1,height)+abs(height[ind]-height[ind-1]);
        int twojump=1e9;
        if(ind > 1){
            twojump=f(ind-2,height)+abs(height[ind]-height[ind-2]);
        }
        return min(onejump,twojump);
    }
    int minimumEnergy(vector<int>& height, int n) {
        // Code here
        vector<int>dp(n,0);
        for(int i=1;i<n;i++){
            int take=dp[i-1]+abs(height[i-1]-height[i]);
            int nottake=1e9;
            if(i>1){
              nottake=dp[i-2]+abs(height[i-2]-height[i]);
            }
            dp[i]=min(take,nottake);
        }
        return dp[n-1];
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