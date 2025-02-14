//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> primes(int n) {
        vector<bool> isPrime(n+1, true);
        isPrime[0] = isPrime[1] = false;

        for(int i = 2; i * i <= n; i++) {
            if(isPrime[i]) {
                for(int j = i * i; j <= n; j += i) {
                    isPrime[j] = false;
                }
            }
        }

        vector<int> primeList;
        unordered_set<int> primeSet;
        
        for(int i = 2; i <= n; i++) {
            if(isPrime[i]) {
                primeList.push_back(i);
                primeSet.insert(i);
            }
        }

        for(auto it : primeList) {
            int val = n - it;
            if(val >= 2 && primeSet.find(val) != primeSet.end()) {
                return {min(it, val), max(it, val)};
            }
        }

        return {};  // If no valid pair is found (this shouldn't happen for even n > 2)
    }

    vector<int> primeDivision(int n) {
        return primes(n);
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
        vector<int> ans = ob.primeDivision(N);
        cout << ans[0] << " " << ans[1] << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends