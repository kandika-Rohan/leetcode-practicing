//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string addBinary(string& s1, string& s2) {
        // your code here
        int n1=s1.size();
        int n2=s2.size();
        
        if(n1>n2){
            int diff=n1-n2;
            
            for(int i=0;i<diff;i++){
                s2="0"+s2;
            }
        }
        else if(n1<n2){
            int diff=n2-n1;
            
            for(int i=0;i<diff;i++){
                s1="0"+s1;
            }
        }
        
        int size1=s1.size();
        
        int size2=s2.size();
        
        int val=s1[size1-1]-'0'+s2[size2-1]-'0';
        
        string ans="";
        
        int carry=val/2;
        
        ans=to_string(val%2)+ans;
        
        for(int i=size1-2;i>=0;i--){
            
            int v=s1[i]-'0'+s2[i]-'0';
            
            v+=carry;
            
            carry=v/2;
            
            ans=to_string(v%2)+ans;
        }
        if(carry>0){
            ans=to_string(carry)+ans;
        }
        int start=-1;
        for(int i=0;i<ans.size();i++){
            if(ans[i]=='1'){
                start=i;
                break;
            }
        
        }
        if(start == -1){
            return ans;
        }
        return ans.substr(start);
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string A, B;
        cin >> A >> B;
        Solution ob;
        cout << ob.addBinary(A, B);
        cout << "\n";

        cout << "~"
             << "\n";
    }
}

// Contributed By: Pranay Bansal

// } Driver Code Ends