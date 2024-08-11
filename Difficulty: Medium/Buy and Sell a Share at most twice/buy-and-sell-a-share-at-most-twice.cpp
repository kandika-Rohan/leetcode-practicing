//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution
{
    public:
        
        int f(int i,int buy,int limit,vector<int>&price,vector<vector<vector<int>>>&dp){
            if(i == price.size())return 0;
            if(limit==0)return 0;
            
            if(dp[i][buy][limit] != -1){
                return dp[i][buy][limit];
            }
            
            int profit=0;
            if(buy){
                
                profit=max(f(i+1,0,limit,price,dp)-price[i],f(i+1,1,limit,price,dp));
            }
            else{
                 profit=max(f(i+1,1,limit-1,price,dp)+price[i],f(i+1,0,limit,price,dp));
            }
            return dp[i][buy][limit]=profit;
        }
        int maxProfit(vector<int>&price){
            int n=price.size();
            vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
           return f(0,1,2,price,dp);
        }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        
        int n;
        cin>>n;
        vector<int> price(n);
        for(int i=0;i<n;i++) cin>>price[i];
        Solution obj;
        cout<<obj.maxProfit(price)<<endl;
    }

}

// } Driver Code Ends