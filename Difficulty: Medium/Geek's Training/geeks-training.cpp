//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int f(int ind,int last,vector<vector<int>>& points,vector<vector<int>>&dp){
        if(ind == 0){
            int maxi=INT_MIN;
            for(int i=0;i<=2;i++){
                if(i != last){
                    maxi=max(maxi,points[0][i]);
                }
            }
            return dp[0][last]=maxi;
        }
        if(dp[ind][last] != -1){
            return dp[ind][last];
        }
        else{
            int maxi=INT_MIN;
            for(int i=0;i<=2;i++){
                if(last != i){
                    maxi=max(maxi,points[ind][i]+f(ind-1,i,points,dp));
                }
            }
            return dp[ind][last]=maxi;
        }
    }
    int maximumPoints(vector<vector<int>>& points, int n) {
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return f(n-1,3,points,dp);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> points;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            points.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(points, n) << endl;
    }
    return 0;
}
// } Driver Code Ends