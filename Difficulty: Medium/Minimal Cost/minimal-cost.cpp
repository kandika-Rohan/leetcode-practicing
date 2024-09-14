//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int i,int k,vector<int>&arr,vector<int>&dp){
        if(i == 0)return 0;
        if(dp[i] != -1)return dp[i];
        int mini=INT_MAX;
        for(int j=1;j<=k;j++){
            
            if(i-j>=0){
                mini=min(mini,f(i-j,k,arr,dp)+abs(arr[i]-arr[i-j]));
            }
        }
        return dp[i]=mini;
    }
    int minimizeCost(vector<int>& arr, int& k) {
        // Code here
        vector<int>dp(arr.size()+1,-1);
        return f(arr.size()-1,k,arr,dp);
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
        int res = obj.minimizeCost(arr, k);
        cout << res << endl;
        // string tl;
        // getline(cin, tl);
    }
    return 0;
}

// } Driver Code Ends