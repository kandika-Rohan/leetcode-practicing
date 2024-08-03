//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int f(int ind,int n,int w,vector<int>&cost,vector<int>&kilo,vector<vector<int>>&dp){
        if(ind == 0){
            if(w%kilo[ind] == 0 && cost[ind] != -1){
                return (w/kilo[ind])*cost[ind];
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][w] != -1){
            return dp[ind][w];
        }
        int nottake=f(ind-1,n,w,cost,kilo,dp);
        int take=1e9;
        if(w>=kilo[ind] && cost[ind] != -1) {
            take=f(ind,n,w-kilo[ind],cost,kilo,dp)+cost[ind];
        }
        return dp[ind][w]=min(take,nottake);
    }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<int>kilo(n);
        for(int i=0;i<n;i++){
            kilo[i]=i+1;
        }
        vector<vector<int>>dp(n,vector<int>(w+1,-1));
        int ans=f(n-1,n,w,cost,kilo,dp);
        return ans>=1e9?-1:ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int w;
        scanf("%d", &w);

        vector<int> cost(n);
        Array::input(cost, n);

        Solution obj;
        int res = obj.minimumCost(n, w, cost);

        cout << res << endl;
    }
}

// } Driver Code Ends