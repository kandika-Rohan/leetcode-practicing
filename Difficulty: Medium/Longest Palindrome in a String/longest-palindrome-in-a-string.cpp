//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
    
     string printLCS(string &s, string &t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        int maxLen = 0;
        int endIndex = 0;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    
                    int substringLength = dp[i][j];
                    int originalStart = i - substringLength;
                    int reverseStart = m - j;
                   
                    if (originalStart == reverseStart) {
                        if (substringLength > maxLen) {
                            maxLen = substringLength;
                            endIndex = i - 1;
                        }
                    }
                }
            }
        }
        
        return s.substr(endIndex - maxLen + 1, maxLen);
    }
  public:
    string longestPalin (string s) {
       string t=s;
       reverse(t.begin(),t.end());
       return printLCS(s,t);
    }
};



//{ Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        string S; cin >> S;
        
        Solution ob;
        cout << ob.longestPalin (S) << endl;
    }
}
// Contributed By: Pranay Bansal

// } Driver Code Ends