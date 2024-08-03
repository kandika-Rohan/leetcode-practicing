//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    public:
void solve(string s, int i, char lastchar, string &ans) {
    if (i < 0) {
        return;
    }
    if (lastchar != s[i]) {
        solve(s, i - 1, s[i], ans);  
        ans += s[i];  
    } else {
        solve(s, i - 1, lastchar, ans); 
    }
}

string removeConsecutiveCharacter(string s) {
    string ans = "";
    int n = s.length();
    if (n == 0) return ans;

    ans += s[0];

    for (int i = 1; i < n; i++) {
        if (s[i] != s[i - 1]) {
            ans += s[i];
        }
    }

    return ans;
}

};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends