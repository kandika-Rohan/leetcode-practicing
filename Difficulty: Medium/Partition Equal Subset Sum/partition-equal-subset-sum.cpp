//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
        
        int totalSum=accumulate(begin(arr),end(arr),0);
        
        if(totalSum%2 != 0)return false;
        
        int k=totalSum/2;
        
        
        int n=arr.size();
        
        vector<vector<bool>>dp(n,vector<bool>(k+1,false));
        
        for(int i=0;i<n;i++){
            
            dp[i][0]=true;
        }
        if(arr[0]<=k){
            dp[0][arr[0]]=true;
        }
        
        for(int i=1;i<n;i++){
            
            for(int target=1;target<=k;target++){
                
                bool nottake=dp[i-1][target];
                
                bool take=false;
                
                if(target>=arr[i]){
                    take=dp[i-1][target-arr[i]];
                }
                dp[i][target]=take || nottake;
            }
        }
        
        return dp[n-1][k];
        
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
        if (ob.equalPartition(arr))
            cout << "true\n";
        else
            cout << "false\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends