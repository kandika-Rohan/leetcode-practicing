//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    string minWindow(string str1, string str2) {
      
    int m = str1.size();
    int n = str2.size();

    // Initialize the DP table
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; ++i) {
        dp[i][0] = i;  // Any window in str1[0:i] contains the empty subsequence str2[0:0]
    }

    // Fill the DP table
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

  
    int start = -1;
    int min_len = INT_MAX;
    for (int i = 1; i <= m; ++i) {
        if (dp[i][n] != -1) {
            int window_len = i - dp[i][n];
            if (window_len < min_len) {
                start = dp[i][n];
                min_len = window_len;
            }
        }
    }

    return start == -1 ? "" : str1.substr(start, min_len);
    }
};


//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        string str1, str2;
        cin >> str1 >> str2;

        Solution obj;
        cout << obj.minWindow(str1, str2) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}

// } Driver Code Ends