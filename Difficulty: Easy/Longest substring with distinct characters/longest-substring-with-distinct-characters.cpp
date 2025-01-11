//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int longestUniqueSubstr(string &s) {
        // code here
        
        int i=0;
        
        unordered_map<char,int>map;
        
        int ans=0;
        
        for(int j=0;j<s.size();j++){
            
            map[s[j]]++;
            
            while(map[s[j]]>1){
                map[s[i]]--;
                
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                }
                
                i++;
            }
            
            ans=max(ans,(j-i+1));
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {

        Solution obj;
        string s;
        cin >> s;
        cout << obj.longestUniqueSubstr(s) << endl;
        cout << "~"
             << "\n";
    }

    return 0;
}

// } Driver Code Ends