//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  string rremove(string s) {
    // Create a new string to store the answer
    string ans = "";
    int n = s.length();

 
    for (int i = 0; i < n; ++i) {
        bool duplicate = false;

      
        while (i < n - 1 && s[i] == s[i + 1]) {
            duplicate = true;
            ++i;
        }

        if (!duplicate) {
            ans += s[i];
        }
    }

   
    return (ans == s) ? ans : rremove(ans);
}

};

//{ Driver Code Starts.

int main() {
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
// } Driver Code Ends