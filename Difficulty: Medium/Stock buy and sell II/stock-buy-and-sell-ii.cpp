//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


class Array
{
public:
    template <class T>
    static void input(vector<T> &A,int n)
    {
        for (int i = 0; i < n; i++)
        {
            scanf("%d ",&A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A)
    {
        for (int i = 0; i < A.size(); i++)
        {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int f(int i,int buy,vector<int>&p, vector<vector<int>>&dp){
        if(i == p.size())return 0;
        if(dp[i][buy] != -1)return dp[i][buy];
        int profit=0;
        if(buy){
            profit=max(f(i+1,0,p,dp)-p[i],f(i+1,1,p,dp));
        }
        else{
            profit=max(f(i+1,1,p,dp)+p[i],f(i+1,0,p,dp));
        }
        return dp[i][buy]=profit;
    }
    int stockBuyAndSell(int n, vector<int> &prices) {
        
        vector<vector<int>>dp(n,vector<int>(2,-1));
        return f(0,1,prices,dp);
    }
};


//{ Driver Code Starts.

int main(){
    int t;
    scanf("%d ",&t);
    while(t--){
        
        int n;
        scanf("%d",&n);
        
        
        vector<int> prices(n);
        Array::input(prices,n);
        
        Solution obj;
        int res = obj.stockBuyAndSell(n, prices);
        
        cout<<res<<endl;
        
    }
}

// } Driver Code Ends