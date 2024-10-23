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
        const int mod=1e9+7;
        long long total=0;
        
        long long curr=0;
        
        for(int i=0;i<s.size();i++){
            
            int digit=s[i]-'0';
            
            curr=(curr*10)%mod+(digit*(i+1))%mod;
            
            total=(total+curr)%mod;
        }
        
        
        return total%mod;
        
        
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
        
    }
    return 0;
}

// } Driver Code Ends