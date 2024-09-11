//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    unorde
    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        vector<string>res;
        for(auto it:dict){
            if(it == s.substr(0,it.length())){
                if(s.length() == it.length()){
                    res.push_back(it);
                }
                else{
                    vector<string>temp=wordBreak(n,dict,
                    s.substr(it.length()));
                    
                    for(auto t:temp){
                        res.push_back(it+" "+t);
                    }
                }
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends