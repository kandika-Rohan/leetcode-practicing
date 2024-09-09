//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
   long long base9(long long n){
       long long mul=1;
       long long res=0;
       while(n>0){
           res+=(n%9)*mul;
           n/=9;
           mul*=10;
       }
       return res;
   }
    long long findNth(long long n) {
        // code here.
        return base9(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n, ans;
        cin >> n;
        Solution obj;
        ans = obj.findNth(n);
        cout << ans << endl;
    }
}

// } Driver Code Ends