//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:
    int getMinDiff(int k, vector<int> &arr) {
        if (arr.size() <= 1) return 0; // No difference for single-element arrays

        // Sort the array
        sort(arr.begin(), arr.end());

        int n = arr.size();
        int minDiff = arr[n - 1] - arr[0]; // Initial difference

        int smallest = arr[0] + k; // Smallest element after adding k
        int largest = arr[n - 1] - k; // Largest element after subtracting k

        for (int i = 0; i < n - 1; i++) {
            int currentMin = min(smallest, arr[i + 1] - k);
            int currentMax = max(largest, arr[i] + k);
            minDiff = min(minDiff, currentMax - currentMin);
        }

        return minDiff;
    }
};



//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();

    while (t--) {
        int k;
        cin >> k;
        cin.ignore();
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int res = ob.getMinDiff(k, arr);
        cout << res;

        cout << "\n";
        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends