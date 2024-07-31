//{ Driver Code Starts
#include<bits/stdc++.h>
#define MAX 1000
using namespace std;
 
int maxSubsequenceSubstring(string x, string y, int n, int m);
 
// Driver Program
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,m;
        string x,y;
        cin>>n>>m;
        cin>>x>>y;
        cout<<maxSubsequenceSubstring(x,y,n,m)<<"\n";
    }
    return 0;
}
// } Driver Code Ends


int maxSubsequenceSubstring(string X, string Y, int N, int M){
    //code
    vector<vector<int>>dp(N+1,vector<int>(M+1,0));
    int maxi=0;
    for(int i=1;i<=N;i++){
        for(int j=1;j<=M;j++){
            if(X[i-1] == Y[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j] =dp[i-1][j];
            }
            maxi=max(dp[i][j],maxi);
        }
        
    }
    return maxi;
}