//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> longestIncreasingSubsequence(int n, vector<int>& arr) {
        // Code here
        
        vector<int>dp(n,1);
        vector<int>hash(n);
        int maxi=0;
        int ind=-1;
        for(int i=0;i<n;i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                
                if(arr[i]>arr[j] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                ind=i;
            }
        }
        
        vector<int>ans;
        ans.push_back(arr[ind]);
        
        while(ind != hash[ind]){
        ind=hash[ind];
        ans.push_back(arr[ind]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        vector<int> res = obj.longestIncreasingSubsequence(N, arr);
        for (auto x : res)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends