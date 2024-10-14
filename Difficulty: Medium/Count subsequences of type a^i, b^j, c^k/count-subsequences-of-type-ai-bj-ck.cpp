//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    const int mod=1e9+7;
    int fun(string &s) {
        //code here
        int acount=0,abcount=0,abccount=0;
        
        for(int i=0;i<s.size();i++){
            
            if(s[i] == 'a'){
                acount=((2*acount)%mod +1)%mod;
            }
            else if(s[i] == 'b'){
                abcount=((2*abcount)%mod + acount)%mod;
            }
            else{
                abccount=((2*abccount)%mod + abcount)%mod;
            }
        }
        return abccount%mod;
    }
};

//{ Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}
// } Driver Code Ends