//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int f(int i,vector<int>&coins,int sum,
    vector<vector<int>>&dp){
        
        if(sum == 0){
            return 0;
        }
        
        if(i == 0){
            
            if(sum%coins[i] == 0){
                return sum/coins[i];
            }
            else{
                return 1e8;
            }
        }
        
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        
        int nottake=f(i-1,coins,sum,dp);
        
        int take=1e8;
        
        if(sum>=coins[i]){
            take=1+f(i,coins,sum-coins[i],dp);
        }
        
        return dp[i][sum]=min(take,nottake);
        
    }
    int minCoins(vector<int> &coins, int sum) {
        vector<vector<int>>dp(coins.size(),vector<int>(sum+1,-1));
        int ans=f(coins.size()-1,coins,sum,dp);
        return ans==1e8?-1:ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    string ts;
    getline(cin, ts);
    int t = stoi(ts);
    while (t--) {
        string ks;
        getline(cin, ks);
        int k = stoi(ks);
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution obj;
        int res = obj.minCoins(arr, k);
        cout << res << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends