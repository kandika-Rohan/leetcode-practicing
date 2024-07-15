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
    int f(int ind, int n, std::vector<int>& a, int prev_ind,vector<vector<int>>&dp) {
    if (ind == n) {
        return 0;
    }
    if(dp[ind][prev_ind+1]  != -1){
        return dp[ind][prev_ind+1];
    }
    int nottake = 0 + f(ind + 1, n, a, prev_ind,dp);
    int take = 0;
    
    if (prev_ind == -1 || std::abs(a[prev_ind] - a[ind]) == 1) {
        take = 1 + f(ind + 1, n, a, ind,dp);
    }
    
    return dp[ind][prev_ind+1]=max(nottake, take);
}

int longestSubseq(int n, std::vector<int>& a) {
    vector<vector<int>>dp(n,vector<int>(n+1,-1));
    return f(0, n, a, -1,dp);
}
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        vector<int> a(n);
        Array::input(a, n);

        Solution obj;
        int res = obj.longestSubseq(n, a);

        cout << res << endl;
    }
}

// } Driver Code Ends