//{ Driver Code Starts
// Initial Template for c++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:

    bool ispalindrome(int start,int end,string s){
        while(start<end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int f(int i,string s,int n,vector<int>&dp){
        if(i==n){
            return 0;
        }
        if(dp[i] != -1){
            return dp[i];
        }
        int mini=INT_MAX;
        for(int j=i;j<n;j++){
            if(ispalindrome(i,j,s)){
                int cost=1+f(j+1,s,n,dp);
                mini=min(mini,cost);
            }
        }
        return dp[i]=mini;
    }
    
    int palindromicPartition(string str)
    {
        // code here
        
        int n=str.size();
        vector<int>dp(n,-1);
        return f(0,str,n,dp)-1;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}
// } Driver Code Ends