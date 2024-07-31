//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
    // your code here
    
    int dist=0;
    int maxi=-1;
    
    unordered_map<char,int>map;
    int i=0;
    for(int j=0;j<s.length();j++){
        map[s[j]]++;
        if(map[s[j]] == 1){
            dist++;
        }
        if(dist > k){
            map[s[i]]--;
            if(map[s[i]] == 0){
                dist--;
            }
            i++;
        }
      
      if(dist == k){
          maxi=max(maxi,j-i+1);
      }

    }
    // cout<<s.substr(start,end)<<endl;
    
    return maxi;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int k;
        cin >> k;
        Solution ob;
        cout << ob.longestKSubstr(s, k) << endl;
    }
}

// } Driver Code Ends