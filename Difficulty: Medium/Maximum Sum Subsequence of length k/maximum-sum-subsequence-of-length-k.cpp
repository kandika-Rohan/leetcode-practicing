//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int f(int i, int prev, vector<int>& a, int k, vector<vector<vector<int>>>& dp) {
        if (k == 0) return 0;
        if (i >= a.size()) return -1e9;
        if (dp[i][prev + 1][k] != -1) return dp[i][prev + 1][k];
        
        int nottake = f(i + 1, prev, a, k, dp);
        int take = -1e9;
        if (prev == -1 ||   a[prev] <= a[i]) {
            take = a[i] + f(i + 1, i, a, k - 1, dp);
        }
        
        return dp[i][prev + 1][k] = max(take, nottake);
    }

    int max_sum(vector<int>& a, int k) {
        int n = a.size();
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n + 1, vector<int>(k + 1, -1)));
        int ans = f(0, -1, a, k, dp);
        return ans < 0 ? -1 : ans;
    }
};




//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n, k;
    	cin >> n >> k;
    	vector<int> v(n);
    	for(int i = 0; i < n; i++)
    		cin >> v[i];
        Solution ob;
        cout<<ob.max_sum(v, k)<<"\n";
     }
	return 0;
}


// } Driver Code Ends