//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int numDecodingsHelper(int i, const string &s) {
        
        if (i == s.size()) {
            return 1;
        }
        
        
        if (s[i] == '0') {
            return 0;
        }
        
        
        int ways = numDecodingsHelper(i + 1, s);
        
        
        if (i + 1 < s.size()) {
            
            int twoDigit = (s[i] - '0') * 10 + (s[i + 1] - '0');
            
            if (twoDigit >= 10 && twoDigit <= 26) {
                
                ways += numDecodingsHelper(i + 2, s);
                
            }
        }
        
        return ways;
    }
    
    int countWays(string s) {
        return numDecodingsHelper(0, s);
    }
};



//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string s;
        cin >> s;
        Solution obj;
        int ans = obj.countWays(s);
        cout << ans << "\n";
    }
    return 0;
}
// } Driver Code Ends