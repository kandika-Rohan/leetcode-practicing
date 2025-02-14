//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int reverse(int n){
        int num=n;
        int val=0;
        while(num>0){
            
            val=val*10+(num%10);
            
            num/=10;
        }
        
        return val;
    }
    int isSumPalindrome(int n) {
        // code here
        
        unordered_set<int>st;
        int mod=1e4;
        int c=0;
        while(st.find(n) == st.end() && c<5){
            
            st.insert(n);
            
            int rev=reverse(n);
            
            if(rev == n){
                
                return rev;
            }
            
            int sum=rev+n;
            int rev2=reverse(sum);
            if(rev2 == sum ){
                return rev2;
            }
            n=sum;
            c++;
        }
        
        return -1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        cout << ob.isSumPalindrome(n) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends