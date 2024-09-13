//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
    public:
    //Function to find minimum number of attempts needed in 
    //order to find the critical floor.
    int fnn(int n,int k,vector<vector<int>>&dp){
        if(k == 0 || k==1){
            return k;
        }
        if( n == 1){
            return k;
        }
        if(dp[n][k] != -1){
            return dp[n][k];
        }
        int mini=INT_MAX;
        for(int f=1;f<=k;f++){
            
            int temp=1+max(fnn(n-1,f-1,dp),fnn(n,k-f,dp));
            
            mini=min(temp,mini);
        }
        
        return dp[n][k]=mini;
    }
    int eggDrop(int n, int k) 
    {
        // your code here
        vector<vector<int>>dp(n+1,vector<int>(k+1,-1));
        return fnn(n,k,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;
        Solution ob;
        //calling function eggDrop()
        cout<<ob.eggDrop(n, k)<<endl;
    }
    return 0;
}

// } Driver Code Ends