//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        
        int mod=1e9+7;
        
        int n=s.size();
        
        
        vector<long long>dp(n,0);
        
        dp[0]=s[0]-'0';
        
        long long ans=dp[0];
        
        for(int i=1;i<n;i++){
            
            dp[i]=(dp[i-1]*10)%mod+((s[i]-'0')*(i+1))%mod;
            
            ans=(ans+dp[i])%mod;
        }
        
        return ans%mod;
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking string
        string s;
        cin>>s;
        Solution ob;
        //calling sumSubstrings() function
        cout << ob.sumSubstrings(s) << endl;
        
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends