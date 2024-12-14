//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string FirstNonRepeating(string &s) {
        // Code here
    vector<char> v;
    unordered_map<char, int> mp;
    string ans;
 
    for (char ch : s) {
        if (mp.find(ch)
            == mp.end()) { // any new character visited for
                           // the first time
            v.push_back(ch);
            mp[ch] = 1;
        }
        else {
            // any repeated character visited
            int index
                = find(v.begin(), v.end(), ch) - v.begin();
            // for any repeated character encountered more
            // than twice the index will be equal to
            // v.size()
            if (index < v.size())
                v.erase(v.begin() + index);
        }
        ans += (v.empty() ? '#' : v.front());
    }
 
    return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        string A;
        cin >> A;
        Solution obj;
        string ans = obj.FirstNonRepeating(A);
        cout << ans << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends