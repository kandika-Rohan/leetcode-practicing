//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  bool ispalindrome(int start,int end,string s){
      if(start == end)return true;
      while(start <= end){
          if(s[start++] !=s[end--] )return false;
      }
      return true;
  }
  void solve(int ind,string s,vector<vector<string>>&ans,vector<string>&m){
      if(ind == s.size()){
          ans.push_back(m);
          return ;
      }
      for(int i=ind;i<s.size();i++){
          if(ispalindrome(ind,i,s)){
              m.push_back(s.substr(ind,i-ind+1));
              solve(i+1,s,ans,m);
              m.pop_back();
          }
      }
  }
    vector<vector<string>> allPalindromicPerms(string s) {
        // code here
        vector<vector<string>>ans;
        vector<string>path;
        solve(0,s,ans,path);
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        
        cin>>S;

        Solution ob;
        vector<vector<string>> ptr = ob.allPalindromicPerms(S);
        
        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                cout<<ptr[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends