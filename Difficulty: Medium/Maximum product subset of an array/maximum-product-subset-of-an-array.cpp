//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
  const int MOD = 1e9 + 7;
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
         int n = arr.size();
        if(n==1) return arr[0];
        int maxneg = INT_MIN;
        long long int product = 1;
        for(int i=0;i<n;i++){
            if(arr[i]){
                product *= (long long int)arr[i];
                product %= MOD;
            }
        if(arr[i]<0) maxneg = max(maxneg,arr[i]);
        }
        if(product>=0) return product%MOD;
        else return (product/maxneg)%MOD;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends