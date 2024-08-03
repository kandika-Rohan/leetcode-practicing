//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
//     int f(int ind, int n,vector<int>&dp) {
//     if (ind == 0) {
//         return 0;
//     }
//     if(dp[ind] != -1){
//         return dp[ind];
//     }
//     int addnum = f(ind - 1, n,dp) + 1;
//     int mul = 1e9;
    
//     if (ind % 2 == 0) { 
//         mul = f(ind / 2, n,dp) + 1;
//     }

//     return dp[ind]=min(mul, addnum);
// }

int minOperation(int n) {
    if(n<=2){
        return n;
    }
    vector<int>dp(n+1);
    dp[0]=0;
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(i%2 == 0){
            dp[i]=dp[i/2]+1;
        }
        else{
            dp[i]=dp[i-1]+1;
        }
    }
    return dp[n];
}

};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	    {
	        int n;
	        cin>>n;
	        Solution ob;
	        cout<<ob.minOperation(n)<<endl;
	    }
}
// } Driver Code Ends