//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int reverseExponentiation(int n) {
        // code here
        int rev_num=0;
        
        int val=n;
        while(val != 0){
            int digit=val%10;
            rev_num=rev_num*10+digit;
            val/=10;
        }
        
        int ans=pow(n,rev_num);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T; // test cases

    while (T--) {
        int n;
        cin >> n; // input N

        Solution ob;
        // power of the number to its reverse
        int ans = ob.reverseExponentiation(n);
        cout << ans << endl;
    }

    return 0;
}

// } Driver Code Ends