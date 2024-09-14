//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int f(string s){
        
        unordered_map<char,int>map;
        
        int n=s.size();
        vector<int>dp(n+1,0);
        dp[0]=1;
        for(int i=0;i<n;i++){
            
            char ch=s[i];
            
            dp[i+1]=dp[i]*2;//each chareacter has the twp possibilities
            
            if(map.find(ch) != map.end()){
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
        if(s1 > s2){
            return str1;
        }
        else if(s1< s2){
            return str2;
        }
        return str1;
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