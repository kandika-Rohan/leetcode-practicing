//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(string s){
        int n=s.length();
        vector<int>dp(n+1,0);
        dp[0]=1;//this is for the empty string;
        unordered_map<char,int>map;
        for(int i=0;i<n;i++){
            dp[i+1]=dp[i]*2;
            char ch=s[i];
            if(map.find(ch) != map.end()){
                //iska matlab h this is the repeating character
                int j=map[ch];
                dp[i+1]=dp[i+1]-dp[j];
            }
            map[ch]=i;
        }
        return dp[n];
    }
    string betterString(string str1, string str2) {
        // code here
        int s1=f(str1);
        int s2=f(str2);
        if(s1 == s2){
            return str1;
        }
        else if(s1>s2){
            return str1;
        }
        else{
            return str2;
        }
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends