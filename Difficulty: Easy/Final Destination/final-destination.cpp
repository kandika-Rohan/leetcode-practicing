//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int canReach(long long a, long long b, long long x) {
        // code here
        
        long long dist=abs(a)+abs(b);
        
        return x>=dist && ((x-dist)%2 == 0)?1:0;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long a,b,x;
        
        cin>>a>>b>>x;

        Solution ob;
        cout << ob.canReach(a,b,x) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends