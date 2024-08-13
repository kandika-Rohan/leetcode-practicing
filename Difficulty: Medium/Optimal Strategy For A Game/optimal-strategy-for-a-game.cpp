//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    long long f(int i,int j,int arr[],vector<vector<long long>>&dp){
        if(i>j)return 0;
        if(dp[i][j] != -1)return dp[i][j];
        
    long long op1=arr[i]+min(f(i+2,j,arr,dp),f(i+1,j-1,arr,dp));
    long long op2=arr[j]+min(f(i+1,j-1,arr,dp),f(i,j-2,arr,dp));
    
    return dp[i][j]=max(op1,op2);
    }
    long long maximumAmount(int n, int arr[]){
        // Your code here
        vector<vector<long long>>dp(n,vector<long long>(n,-1));
        return f(0,n-1,arr,dp);
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
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(n,a)<<endl;
	}
	return 0;
}
// } Driver Code Ends