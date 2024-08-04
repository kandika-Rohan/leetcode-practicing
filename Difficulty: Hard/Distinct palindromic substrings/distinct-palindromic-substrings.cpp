//{ Driver Code Starts
// C++ program to find all distinct palindrome sub-strings
// of a given string
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
  public:
    int palindromeSubStrs(string s) {
    int n = s.size();
    set<string> st;
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    
    // Single character substrings are palindromes
    for (int i = 0; i < n; i++) {
        dp[i][i] = true;
        st.insert(s.substr(i, 1));
    }
    
    // Two consecutive characters
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == s[i + 1]) {
            dp[i][i + 1] = true;
            st.insert(s.substr(i, 2));
        }
    }
    
    // Substrings of length 3 and more
    for (int length = 3; length <= n; length++) {
        for (int i = 0; i < n - length + 1; i++) {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1]) {
                dp[i][j] = true;
                st.insert(s.substr(i, length));
            }
        }
    }

    return st.size();
}

};

//{ Driver Code Starts.

// Driver program
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        cout << ob.palindromeSubStrs(str) << endl;
    }
    return 0;
}

// } Driver Code Ends