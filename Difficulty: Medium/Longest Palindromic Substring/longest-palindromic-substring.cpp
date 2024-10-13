//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    string longestPalindrome(string s){
        // code here 
        int n=s.size();
        
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        
        int maxlen=1;
        int start=0;
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                
                if(maxlen<2){
                    maxlen=2;
                    start=i;
                }
                dp[i][i+1]=true;
            }
        }
        
        for(int len=3;len<=n;len++){
            for(int i=0;i<=n-len;i++){
                int j=i+len-1;
                if(s[i] == s[j] && dp[i+1][j-1]){
                    dp[i][j]=true;
                    if(maxlen<len){
                        maxlen=len;
                        start=i;
                    }
                }
            }
        }
        
        return s.substr(start,maxlen);
    }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        Solution ob;
        cout<<ob.longestPalindrome(S)<<endl;
    }
    return 0;
}

// } Driver Code Ends