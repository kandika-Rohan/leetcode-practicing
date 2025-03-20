//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;


// } Driver Code Ends

class Solution {
  public:
    int f(int i,vector<int>&arr,
    vector<int>&dp){
        
        if(i<0){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        
        int nottake=0+f(i-1,arr,dp);
        
        int take=f(i-2,arr,dp)+arr[i];
        
        return dp[i]=max(take,nottake);
    }
    int findMaxSum(vector<int>& arr) {
        // code here
        int n=arr.size();
        vector<int>dp(n,-1);
        return f(arr.size()-1,arr,dp);
        
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

        Solution ob;
        cout << ob.findMaxSum(arr) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends