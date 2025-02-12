//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool isprime(int n) {
    if (n <= 1) return false;  // 1 is not prime
    if (n == 2) return true;   // 2 is prime
    if (n % 2 == 0) return false; // Even numbers >2 are not prime
    
    int val = sqrt(n);
    
    for (int i = 3; i <= val; i += 2) { // Skip even numbers
        if (n % i == 0) return false;
    }
    
    return true;
}

int isTwistedPrime(int N) {
    int val = N, sum = 0;
    
    // Reverse the digits of N
    while (val > 0) {
        int digit = val % 10;
        sum = sum * 10 + digit;
        val /= 10;
    }

    // Check if both N and its reverse are prime
    return isprime(N) && isprime(sum);
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
        cout << ob.isTwistedPrime(N) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends