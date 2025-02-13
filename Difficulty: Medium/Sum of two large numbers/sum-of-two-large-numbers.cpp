//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    string findSum(string &s1, string &s2) {
        // Your code goes here
        int n1=s1.size();
        int n2=s2.size();
        
        int diff=abs(n1-n2);
        
        if(n1<n2){
            
            for(int i=0;i<diff;i++){
                s1="0"+s1;
            }
        }
        else if(n1>n2){
             for(int i=0;i<diff;i++){
                s2="0"+s2;
            }
        }
        
        n1=s1.size();
        n2=s2.size();
        
        int carry=0;
        string ans="";
        for(int i=n1-1;i>=0;i--){
            
            int val1=s1[i]-'0';
            int val2=s2[i]-'0';
            
            int sum=val1+val2+carry;
            
            carry=sum/10;
            
            sum=sum%10;
            
            ans=to_string(sum)+ans;
        }
        
        if(carry>0){
            
            ans=to_string(carry)+ans;
        }
        int start=-1;
        
        for(int i=0;i<ans.size();i++){
            
            if(ans[i] != '0'){
                start=i;
                break;
            }
        }
        if(start == -1){
            return "0";
        }
        return ans.substr(start);
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string x, y;
        cin >> x >> y;
        Solution ob;
        cout << ob.findSum(x, y) << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends