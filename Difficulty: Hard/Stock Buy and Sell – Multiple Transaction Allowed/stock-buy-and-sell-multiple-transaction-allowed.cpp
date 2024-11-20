//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i,vector<int>&prices,int buy,vector<vector<int>>&dp){
        
        if(i >= prices.size())return 0;
        
        if(dp[i][buy] != -1)return dp[i][buy];
        
        int profit=0;
        
        if(buy){
            
            profit=max(f(i+1,prices,0,dp)-prices[i],
            f(i+1,prices,1,dp));
        }
        else{
            profit=max(f(i+1,prices,1,dp)+prices[i],
            f(i+1,prices,0,dp));
        }
        
        return dp[i][buy]=profit;
    }
    int maximumProfit(vector<int> &prices) {
        // code here
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(3,-1));
        
        return f(0,prices,1,dp);
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
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.maximumProfit(arr);
        cout << res;

        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends