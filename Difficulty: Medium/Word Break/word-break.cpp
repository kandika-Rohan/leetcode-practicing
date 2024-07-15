//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// s : given string to search
// dictionary : vector of available strings

class Solution
{
public:
int f(int i, int n, string s, set<string>& st,vector<int>&dp) {
    if (i == n) {
        return 1; // Reached the end of the string successfully
    }
    if(dp[i] != -1){
        return dp[i];
    }
    string temp = "";
    for (int j = i; j < n; j++) {
        temp += s[j];
        if (st.find(temp) != st.end()) {
            if (f(j + 1, n, s, st,dp)) {
                return dp[i]=1;
            }
        }
    }
    return dp[i]=0; // Couldn't segment the string properly
}

int wordBreak(int n, string s, vector<string>& dictionary) {
    set<string> st(dictionary.begin(), dictionary.end()); 
    // Convert vector to set for O(1) lookups
    int m=s.size();
    vector<int>dp(m,-1);
    return f(0, m, s, st,dp);
}
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dictionary;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dictionary.push_back(S);
        }
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.wordBreak(n, s, dictionary)<<"\n";
    }
}

// } Driver Code Ends