//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string modify(string& s){
    // code here.
    unordered_set<char> st = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    int i = 0;
    int j = s.size() - 1;
    
    while (i < j) {
        if (st.find(s[i]) != st.end() && st.find(s[j]) != st.end()) {
            swap(s[i], s[j]);
            i++;
            j--;
        } else if (st.find(s[i]) == st.end()) {
            i++;
        } else {
            j--;
        }
    }
    
    return s;
}
}
;

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.modify(s) << endl;

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends