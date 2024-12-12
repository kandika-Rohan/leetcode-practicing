//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int>kmp(string pat){
        int n=pat.size();
        int i=1;
        int len=0;
        vector<int>lps(n,0);
        while(i<n){
            if(pat[i] == pat[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else{
                if(len != 0){
                    len=lps[len-1];
                }
                else{
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    int findMatching(string text, string pat) {
        // Code here
        
        vector<int>lps=kmp(pat);
        
        int i=0;
        int j=0;
        int n=text.size();
        int m=pat.size();
        while(i<n){
            if(pat[j] == text[i]){
                i++;
                j++;
            }
            if(j == m){
               
                return i-j;
                j=lps[j-1];
            }
            else if(pat[j] != text[i]){
                if(j != 0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string text, pat;
        cin >> text >> pat;
        Solution obj;
        cout << obj.findMatching(text, pat) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends