//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int Maximize(vector<int> arr) {
        // Complete the function
         int n = arr.size();
        sort(arr.begin(), arr.end());
        long long ans = 0;
        long long mod = 1000000000 + 7;
        
        for (int i = 0; i < n; i++) {
            long long temp = (arr[i] * (long long)i) % mod;
            ans = (ans + temp) % mod;
        }
        
        return (int)ans;
    } 
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        //  cin.ignore();
        int n = arr.size();
        Solution ob;
        cout << ob.Maximize(arr) << endl;
    }
}
// } Driver Code Ends