//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

   int f(int ind, int prevInd, vector<int> &nums, int n, vector<vector<int>> &dp) {
        if (ind == n) return 0;
        if (dp[ind][prevInd +1 ] != -1) return dp[ind][prevInd + 1];
        int notTake = f(ind + 1, prevInd, nums, n, dp);
        int take = 0;
        if (prevInd == -1 || nums[ind] > nums[prevInd] &&nums[ind]-nums[prevInd]>=ind-prevInd) {
            take = 1 + f(ind + 1, ind, nums, n, dp);
        }
        return dp[ind][prevInd + 1] = max(take, notTake);
    }
    
    int min_operations(vector<int>& nums) {
      
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        int m =  f(0, -1, nums, n, dp);
        return n-m;
    }


};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++)
            cin >> nums[i];
        Solution ob;
        int ans = ob.min_operations(nums);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends