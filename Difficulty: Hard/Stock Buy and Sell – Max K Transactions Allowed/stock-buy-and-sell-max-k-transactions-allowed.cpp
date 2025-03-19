//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i,bool buy,int k,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(k == 0){
            return 0;
        }
        if(i >= prices.size())return 0;
        
        if(dp[i][k][buy] != -1){
            return dp[i][k][buy];
        }
        int profit=0;
        if(buy){
            profit=max(f(i+1,0,k,prices,dp)-prices[i],f(i+1,1,k,prices,dp));
        }
        else{
            profit=max(f(i+1,1,k-1,prices,dp)+prices[i],f(i+1,0,k,prices,dp));
        }
        
        return dp[i][k][buy]=profit;
    }
    int maxProfit(vector<int>& prices, int k) {
        // code here
        int n=prices.size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return f(0,true,k,prices,dp);
    }
};


//{ Driver Code Starts.

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(0);

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        string input;
        getline(cin, input);
        istringstream iss(input);
        vector<int> arr;
        int num;

        // Read integers from the input string
        while (iss >> num) {
            arr.push_back(num);
        }
        int k;
        cin >> k;
        cin.ignore();
        Solution ob;
        cout << ob.maxProfit(arr, k) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends