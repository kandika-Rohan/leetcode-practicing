//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    bool f(int i,int j,string &t,string &p,vector<vector<int>>&dp){
        
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(i == 0 && j == 0){
            return true;
        }
        if(i != 0 && j == 0){
            return false;
        }
        
        if(i == 0 && j != 0){
            
            for(int k=1;k<=j;k++){
                if(p[k-1] != '*'){
                    return false;
                }
            }
            return true;
        }
        
        if(t[i-1] == p[j-1] || p[j-1] == '?'){
            return dp[i][j]=f(i-1,j-1,t,p,dp);
        }
        else if(p[j-1] == '*'){
            
            return dp[i][j]=f(i-1,j,t,p,dp)||f(i,j-1,t,p,dp);
        }
        else{
            return dp[i][j]=false;
        }
    }
    bool wildCard(string &txt, string &pat) {
        // code here
        int n=txt.size();
        int m=pat.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
       bool ans=f(n,m,txt,pat,dp);
       return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        bool ans = obj.wildCard(text, pat);
        if (ans)
            cout << "true" << endl;
        else
            cout << "false" << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends