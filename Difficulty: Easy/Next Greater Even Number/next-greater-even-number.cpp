//{ Driver Code Starts
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getNextEven(string x) {
        // Your code goes here
        
    while ( next_permutation( x.begin(), x.end() ))
        if (!( x.back() & 1 )) return stoll( x );
    return -1LL;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        Solution ob;
        cout << ob.getNextEven(x) << endl;

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends