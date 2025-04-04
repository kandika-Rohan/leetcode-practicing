//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
bool static comp (string &s1, string &s2){
        return s1.length() < s2.length();
    }
    
    bool check(string &s1, string &s2){
        if(s1.length() != s2.length() + 1){
            return false;
        }
        int i = 0;
        int j = 0;
        while(i < s1.length()){
            if(j < s2.length() && s1[i] == s2[j]){
                i++;
                j++;
            }else{
                i++;
            }
        }
        return i == s1.length() && j == s2.length();
    }
    
    int longestChain(int n, vector<string>& words) {
        sort(words.begin(), words.end(), comp);
        vector<int> dp (n, 0);
        dp[0] = 1;
        int ans = 1;
        for(int i = 1; i < n; i++){
            int curr = 1;
            for(int j = 0; j < i; j++){
                if(check(words[i], words[j])){
                    curr = max(curr, dp[j] + 1);
                }
            }
            ans = max(curr, ans);
            dp[i] = curr;
        }
        return ans;
    }
    
    int longestStringChain(vector<string>& words) {
        return longestChain(words.size(),words);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<string> words;
        string input;
        getline(cin, input);
        stringstream ss(input);
        string number;
        while (ss >> number) {
            words.push_back(number);
        }
        Solution obj;
        cout << obj.longestStringChain(words) << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends