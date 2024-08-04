//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string s) 
    { 
        // code here 
       
        string temp="";
        string ans="";
        stack<string>st;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i] == '.'){
                if(!temp.empty()){
                    reverse(temp.begin(),temp.end());
                    ans=ans+"."+temp;
                    // cout<<ans<<endl;
                }
                temp="";
            }
            else{
                temp+=s[i];
            }
        }
        if(!temp.empty())
        reverse(temp.begin(),temp.end());
        ans+="."+temp;
        
        string res=ans.substr(1,ans.length());
        
        return res;
    } 
};

//{ Driver Code Starts.
int main() 
{
    int t;
    cin >> t;
    while (t--) 
    {
        string s;
        cin >> s;
        Solution obj;
        cout<<obj.reverseWords(s)<<endl;
    }
}
// } Driver Code Ends