//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include<bits/stdc++.h>
class Solution{

  public:
	int minDifference(int nums[], int n)  { 
	     int totSum = 0;
        for (int i=0; i<n; i++) totSum += nums[i];

        int k = totSum;

        
        vector<vector<bool>> dp(n, vector<bool>(k + 1, false));

  
        for (int i = 0; i < n; i++) dp[i][0] = true;
        if (nums[0] <= k) dp[0][nums[0]] = true;

       
        for (int ind = 1; ind < n; ind++) {
            for (int target = 1; target <= k; target++) {
                bool notTake = dp[ind - 1][target];
                bool take = false;
                if (nums[ind] <= target) take = dp[ind - 1][target - nums[ind]];
                dp[ind][target] = take || notTake;
            }
        }

      
        int mini = 1e9;
        for (int s1 = 0; s1 <= totSum / 2; s1++) {
            if (dp[n - 1][s1]) {
                mini = min(mini, abs((totSum - s1) - s1));
            }
        }

        return mini;
	}
};



//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}
// } Driver Code Ends