//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int smallestSubstring(string s) {
        
        
    vector<int> v(3, 0); 
    int i = 0;
    int mini = INT_MAX;  

    for (int j = 0; j < s.size(); j++) {
        
        v[s[j] - '0']++; 

        while (v[0] > 0 && v[1] > 0 && v[2] > 0) {
            mini = min(mini, j - i + 1);  
            
            v[s[i] - '0']--;  
            i++;  
        }
    }


    return (mini == INT_MAX) ? -1 : mini;
}

};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.smallestSubstring(S);
        cout << endl;
    }
}
// } Driver Code Ends