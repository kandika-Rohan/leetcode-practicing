//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
 

// } Driver Code Ends
/*You are required to complete this method*/

class Solution
{
    public:
    const int M=1e9+7;
    int f(int i,int j,string s,string t,vector<vector<int>>&dp){
        if(j==0){
            return 1;
        }
        if(i==0){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        if(s[i-1] == t[j-1]){
            return dp[i][j]=(f(i-1,j-1,s,t,dp)+f(i-1,j,s,t,dp))%M;
        }
        else{
            return dp[i][j]=(f(i-1,j,s,t,dp))%M;
        }
    }
    int subsequenceCount(string s, string t)
    {
      //Your code here
      int n=s.size();
      int m=t.size();
      vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
      
      return f(n,m,s,t,dp);
    }
};
 


//{ Driver Code Starts. 

//  Driver code to check above method
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string tt;
		cin>>s;
		cin>>tt;
		
		Solution ob;
		cout<<ob.subsequenceCount(s,tt)<<endl;
		
		
	}
  
}
// } Driver Code Ends