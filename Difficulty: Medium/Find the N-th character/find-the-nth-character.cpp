//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        //code here
        
        string tempString;
        
        while (r > 0) {
            tempString = "";
            for (int i = 0; i <= n; i++) {
                if (s[i] == '0') {
                    tempString += "01";
                } else {
                    tempString += "10";
                }
            }
            s = tempString;
            r--;
        }
        
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends