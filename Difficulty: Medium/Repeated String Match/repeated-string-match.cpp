//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    vector<int>kmp(string str){
        int n=str.size();
        vector<int>lps(n,0);
        int i=1;
        int len=0;
        while(i<n){
            if(str[i] == str[len]){
                len++;
                lps[i]=len;
                i++;
            }
            else {
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
    
    bool ispresent(string b,string rep){
        int i=0,j=0;
        
        int m=b.size();
        
        int n=rep.size();
        
        vector<int>lps=kmp(b);
        
        while(i<n){
            if(b[j] == rep[i]){
                i++;
                j++;
            }
            if(j == m){
                return true;
            }
            else if(b[j] != rep[i]){
                if(j != 0){
                    j=lps[j-1];
                }
                else{
                    i++;
                }
            }
        }
        return false;
        
    }
    int repeatedStringMatch(string a, string b) {
        // Your code goes here
        
        int cnt=1;
        
        string rep=a;
        
        while(rep.size()<b.size()){
            rep=rep+a;
            cnt++;
        }
        
        if(ispresent(b,rep)){
            return cnt;
        }
        cnt+=1;
        rep=rep+a;
        if(ispresent(b,rep)){
            return cnt;
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A;
        cin >> B;
        Solution obj;
        cout << obj.repeatedStringMatch(A, B) << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends