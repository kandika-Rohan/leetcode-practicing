//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int i,int sum,vector<int>&coins,vector<vector<int>>&dp){
        if(dp[i][sum] != -1){
            return dp[i][sum];
        }
        if(i == 0){
            if(sum % coins[0] == 0){
                return 1;
            }
            return 0;
        }
        int nottake=f(i-1,sum,coins,dp);
        int take=0;
        if(sum>=coins[i]){
            take=f(i,sum-coins[i],coins,dp);
        }
        return dp[i][sum]=take+nottake;
    }
    int count(vector<int>& coins, int sum) {
        // code here.
        vector<vector<int>>dp(coins.size(),vector<int>(sum+1,-1));
        return f(coins.size()-1,sum,coins,dp);
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
        int sum;
        cin >> sum;
        cin.ignore();
        Solution ob;
        cout << ob.count(arr, sum) << endl;
        cout << "~" << endl;
    }

    return 0;
}

// } Driver Code Ends