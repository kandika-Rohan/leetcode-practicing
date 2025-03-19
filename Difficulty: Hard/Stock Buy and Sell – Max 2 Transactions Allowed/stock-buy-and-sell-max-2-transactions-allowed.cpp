//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int solve(int i,vector<int>&prices,bool buy,
    vector<vector<vector<int>>>&dp,int k){
        
        if(k == 0){
            
            return 0;
        }
        if(i>=prices.size())return 0;
        
        if(dp[i][k][buy] != -1){
            
            return dp[i][k][buy];
        }
        
        int profit=0;
        
        if(buy){
            
            profit=max(solve(i+1,prices,0,dp,k)-prices[i],
            solve(i+1,prices,1,dp,k));
        }
        else{
            
            profit=max(solve(i+1,prices,1,dp,k-1)+prices[i],
            solve(i+1,prices,0,dp,k));
        }
        
        return dp[i][k][buy]=profit;
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        
        vector<vector<vector<int>>>dp(n,
        vector<vector<int>>(3,vector<int>(2,-1)));
        
        return solve(0,prices,true,dp,2);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.maxProfit(arr);

        cout << res << endl << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends