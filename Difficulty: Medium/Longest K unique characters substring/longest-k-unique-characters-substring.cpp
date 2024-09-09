//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        int len=-1;
        int i=0;
        int dist=0;
        vector<int>hash(26,0);
        
        for(int j=0;j<s.size();j++){
            
            hash[s[j] - 'a']++;
            if(hash[s[j] - 'a'] == 1){
                dist++;
            }
            
            while(dist > k && i<=j){
                hash[s[i]-'a']--;
                if(hash[s[i]-'a'] == 0){
                    dist--;
                }
                i++;
            }
            
            if (dist == k) {
            len = max(len, j - i + 1); 
        }
        }
        return len;
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