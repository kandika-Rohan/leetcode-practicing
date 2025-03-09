//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution {
  public:
    int countPS(string &s) {
        // code here
        
        int n=s.size();
        
        vector<vector<int>>dp(n,vector<int>(n,false));
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        int cnt=0;
        
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                cnt++;
                dp[i][i+1]=true;
            }
        }
        
        for(int len=3;len<=n;len++){
            
            for(int i=0;i<n-len+1;i++){
                
                int j=i+len-1;
                
                if(s[i] == s[j] && dp[i+1][j-1]){
                    cnt++;
                    dp[i][j]=true;
                }
            }
        }
        
        return cnt;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution ob;
        cout << ob.countPS(s) << endl;
        cout << "~\n";
    }
    return 0;
}
// } Driver Code Ends