//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int countOfSubstrings(string s, int k) {
        // code here
        
        int cnt=0;
        
        int i=0;
        
        unordered_map<char,int>map;
        
        int dist=0;
        
        for(int j=0;j<s.size();j++){
            
            map[s[j]]++;
            
            if(map[s[j]] == 1){
                dist+=1;
            }
            
            while((j-i+1) >k){
                map[s[i]]--;
                if(map[s[i]] == 0){
                    map.erase(s[i]);
                    dist--;
                }
                i++;
            }
            
            if((j-i+1 == k) && (dist == (k-1))){
                cnt++;
            }
        }
        return cnt;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        int K;
        cin>>S;
        cin>>K;

        Solution ob;
        cout << ob.countOfSubstrings(S,K) << endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends