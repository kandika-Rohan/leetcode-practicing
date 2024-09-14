//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to find equilibrium point in the array.
    // arr: input array
    int equilibriumPoint(vector<long long> &arr) {
        // Your code here
        vector<long long>pre(arr.size(),0);
        vector<long long>suf(arr.size(),0);
        
        pre[0]=arr[0];
        
        for(int i=1;i<arr.size();i++){
            pre[i]=pre[i-1]+arr[i];
        }
        
        int n=arr.size();
        suf[n-1]=arr[n-1];
        
        for(int i=n-2;i>=0;i--){
            suf[i]=suf[i+1]+arr[i];
        }
        
        for(int i=0;i<n;i++){
            if(pre[i] == suf[i]){
                return i+1;
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To discard any leftover newline characters
    while (t--)   // while testcases exist
    {
        vector<long long> arr;
        string input;
        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        cout << ob.equilibriumPoint(arr) << endl;
    }
}
// } Driver Code Ends