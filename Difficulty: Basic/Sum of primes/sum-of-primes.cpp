//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<bool>solve(int n){
        
        vector<bool>isprime(n+1,true);
        
        isprime[0]=isprime[1]=false;
        
        for(int i=2;i*i<=n;i++){
            if(isprime[i]){
                for(int j=i*i;j<=n;j+=i){
                    isprime[j]=false;
                }
            }
        }
        
        return isprime;
    }
    int primeSum(int n) {
        // code here
        
        int sum=0;
        
        vector<bool>isprime=solve(10);
        
        while(n>0){
            int digit=n%10;
            
            if(isprime[digit]){
                
                sum+=digit;
            }
            n/=10;
        }
        
        return sum;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        cout << ob.primeSum(N) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends