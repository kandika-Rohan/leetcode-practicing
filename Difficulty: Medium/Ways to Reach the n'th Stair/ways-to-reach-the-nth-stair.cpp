//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to count number of ways to reach the nth stair.
  int mode=1000000007;
    int fun(int n,vector<int> &dp){
        if(n==0)
            return(1);
        if(n<0)
            return(0);
        
        if(dp[n]!=-1)
            return(dp[n]);
    
        return(dp[n]=(fun(n-1,dp)+fun(n-2,dp))%mode);
    }
    
    
    int countWays(int n)
    {
        // your code here
        vector<int> dp(n+1,-1);
        return(fun(n,dp));
        
    }
};



//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking stair count
        int m;
        cin>>m;
        Solution ob;
        cout<<ob.countWays(m)<<endl; // Print the output from our pre computed array
    }
    return 0;
}

// } Driver Code Ends