//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    const int mod=1e9+7;
    int nCr(int n, int r) {
        // code here
        if(r>n)return 0;
        if(r == 0)return 1;
        
   
           int run = r; 
           
           if(n<=2*r){
               run  = n-r; 
           }
           
          long sum1 = 1 ; 
          
           for (int i=0;i<run;i++){
               sum1*=(n-i); 
               sum1/=(i+1);
               
               
           }
           
           return sum1; 
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, r;
        cin >> n >> r;

        Solution ob;
        cout << ob.nCr(n, r) << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends