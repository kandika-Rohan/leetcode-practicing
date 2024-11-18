//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    public:
    
    bool f(int i,int j,string s,string pat
    ,vector<vector<int>>&dp){
        if(dp[i][j] != -1)return dp[i][j];
        
        if(i == 0 && j != 0){
            return dp[i][j]=false;
        }
        
        if(i == 0 && j == 0)return dp[i][j]=true;
        
       if(j == 0 && i !=0){
           for(int k=1;k<=i;k++){
               if(s[k-1] != '*'){
                   return dp[i][j]=false;
               }
           }
           
           return dp[i][j]=true;
       }
       
       
       if(s[i-1] == pat[j-1] || s[i-1] == '?'){
           
           return dp[i][j]=f(i-1,j-1,s,pat,dp);
       }
       else if(s[i-1] == '*'){
           return dp[i][j]=f(i-1,j,s,pat,dp)||f(i,j-1,s,pat,dp);
       }
       else{
           return dp[i][j]=false;
       }
    }
    bool match(string wild, string pattern)
    {
        // code here
        int n=wild.size();
        int m=pattern.size();
        
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        
        return f(wild.size(),pattern.size(),wild,pattern,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t-->0)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        bool x=ob.match(wild, pattern);
        if(x)
        cout<<"Yes\n";
        else
        cout<<"No\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends