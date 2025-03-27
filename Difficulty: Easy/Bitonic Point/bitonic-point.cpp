//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++
class Solution {
  public:
    int findMaximum(vector<int> &arr) {
        // code here
        
        vector<int>backword(arr.size(),0),forward(arr.size(),0);
        
        int n=arr.size();
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                backword[i]=-1;
            }
        }
        
        for(int i=1;i<n;i++){
            if(arr[i-1]>arr[i]){
                forward[i-1]=-1;
            }
        }
        
        for(int i=0;i<n;i++){
            if(backword[i] == -1 && forward[i] == -1){
                return arr[i];
            }
        }
        
        return arr[n-1];
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> arr;
        int value;

        // Read the entire line of integers
        string line;
        // cin.ignore(); // Ignore the newline after the test case input
        getline(cin, line);
        stringstream ss(line);

        // Parse integers and add them to the vector
        while (ss >> value) {
            arr.push_back(value);
        }

        Solution ob;
        auto ans = ob.findMaximum(arr);
        cout << ans << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends