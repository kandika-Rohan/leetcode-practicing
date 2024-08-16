//{ Driver Code Starts
// #include <bits/stdc++.h>
// using namespace std;

// // int CountPS(char s[], int n);

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
// int N;
// cin >> N;
// char S[N + 1];
// cin >> S;
// Solution ob;
//         cout << ob.CountPS(S, N) << endl;
//     }
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


// User function Template for C++

class Solution {
  public:
    int CountPS(char s1[], int m) {
        // code here
        string s="";
        for(int i=0;i<m;i++){
            s+=s1[i];
        }
        int n=s.size();
        bool dp[n][n];
        
        memset(dp,false,sizeof dp);
        
        
        for(int i=0;i<n;i++){
            dp[i][i]=true;
        }
        
        int maxlen=2;
        int start=-1;
        vector<string>st;
        for(int i=0;i<n-1;i++){
            if(s[i] == s[i+1]){
                dp[i][i+1]=true;
                start=i;
                maxlen=2;
                st.push_back(s.substr(start,maxlen));
            }
        }
        
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int j=i+len-1;
                
                if(s[i] == s[j]  && dp[i+1][j-1]){
                    dp[i][j]=true;
                    start=i;
                    maxlen=len;
                    st.push_back(s.substr(start,maxlen));
                }
            }
        }
        
        return st.size();
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        char S[N + 1];
        cin >> S;
        Solution ob;
        cout << ob.CountPS(S, N) << endl;
    }
    return 0;
}
// } Driver Code Ends