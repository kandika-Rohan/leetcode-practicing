//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    string longestPalindrome(string s) {
        // code here
        int n=s.size();
        if(n <= 1){
            return s;
        }
        
        int start=0;
        int maxlen=1;
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        bool flag=false;
        
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1]=true;
                maxlen=2;
                if(flag == false){
                    start=i;
                }
                flag=true;
            }
        }
        for(int len=3;len<=n;len++){
            
            for(int i=0;i<=n-len;i++){
                
                int j=i+len-1;
                
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    
                    if(maxlen<len){
                        maxlen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
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
        cout << ob.longestPalindrome(S) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends