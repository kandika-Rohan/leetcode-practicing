//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int>lps(string pattern){
        int n=pattern.size();
        vector<int>ans(n,0);
        
        int i=1;
        int len=0;
        
        while(i<n){
            if(pattern[i] == pattern[len]){
                len++;
                ans[i]=len;
                i++;
            }
            else {
                
                if(len != 0){
                    len=ans[len-1];
                }
                else{
                    ans[i]=0;
                    i++;
                }
            }
        }
        return ans;
    }
    vector<int> search(string pat, string text) {
        // code here
        
        vector<int>lp=lps(pat);
        
        int i=0,j=0;
        int m=pat.size();
        int n=text.size();
        
        vector<int>ans;
        
        while(i<n){
            
            if(pat[j] == text[i]){
                i++;
                j++;
            }
            if(j == m){
                ans.push_back(i-j+1);
                j=lp[j-1];
            }
            else if(i<n && pat[j] != text[i]){
                if(j != 0){
                    j=lp[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector<int> res = ob.search(pat, S);
        if (res.size() == 0)
            cout << -1 << endl;
        else {
            for (int i : res)
                cout << i << " ";
            cout << endl;
        }
    }
    return 0;
}

// } Driver Code Ends